import os
import re
import yaml

# An entry line: an object path, then the sections it contributes, in parens.
SECTION_ENTRY_RE = re.compile(r'^\s*(?P<obj>[^\s()]+\.o)\((?P<sections>[^)]*)\);?\s*$')

# The lcf placeholders, in the order Splat lays the sections out.
SECTIONS = [".text", ".data", ".rodata", ".gcc_except_table", ".lit8", ".lit4", ".sdata", ".sbss", ".bss"]

PLACEHOLDERS = {
	".text": "#<REPLACE_W_TEXT_FILES>",
	".data": "#<REPLACE_W_DATA_FILES>",
	".rodata": "#<REPLACE_W_RODATA_FILES>",
	".gcc_except_table": "#<REPLACE_W_GCC_EXCEPT_TABLE_FILES>",
	".lit8": "#<REPLACE_W_LIT8_FILES>",
	".lit4": "#<REPLACE_W_LIT4_FILES>",
	".sdata": "#<REPLACE_W_SDATA_FILES>",
	".sbss": "#<REPLACE_W_SBSS_FILES>",
	".bss": "#<REPLACE_W_BSS_FILES>",
}

ALIGNED_SECTIONS = (".data", ".rodata", ".sdata")
BOUNDARY_SECTIONS = ALIGNED_SECTIONS + (".sbss", ".bss")
ALIGN_CANDIDATES = (4, 8, 16)
DEFAULT_ALIGNALL = 0x8
DEFAULT_TAIL_ALIGN = 0x10
COMPILED_ALIGNALL = {".data": 0x8, ".rodata": 0x8, ".sdata": 0x4}
DEFAULT_COMPILED_ALIGNALL = 0x4


def load_splat_options(yaml_path):
	"""Return the options block of the Splat config, with paths resolved."""
	with open(yaml_path, "r") as splat_yaml_file:
		config = yaml.safe_load(splat_yaml_file)

	options = config.get("options", {})
	yaml_dir = os.path.dirname(os.path.abspath(yaml_path))
	base_path = os.path.normpath(os.path.join(yaml_dir, options.get("base_path", ".")))

	def resolve(key, default):
		return os.path.normpath(os.path.join(base_path, options.get(key, default)))

	return {
		"base_path": base_path,
		"ld_script_path": resolve("ld_script_path", f"build/{options.get('basename', 'out')}.ld"),
		"build_path": resolve("build_path", "build"),
		"asm_path": resolve("asm_path", "asm"),
		"src_path": resolve("src_path", "src"),
		"asset_path": os.path.normpath(options.get("asset_path", "assets")),
	}


SECTION_SUFFIXES = (".data", ".rodata", ".sdata", ".sbss", ".bss", ".lit4", ".lit8", ".gcc_except_table")


def subsegment_sections(config):
	"""Group the config's section subsegments by section, sorted by address.

	Splat writes these two ways: `[0x1D9830, rodata, name]` and
	`{ type: bss, vram: 0x2F2400, name: ... }`.
	"""
	sections = {}
	for segment in config.get("segments", []):
		if not isinstance(segment, dict):
			continue
		for entry in segment.get("subsegments", []):
			if isinstance(entry, dict):
				address, kind, name = entry.get("vram"), entry.get("type"), entry.get("name")
			elif isinstance(entry, list) and len(entry) >= 3:
				address, kind, name = entry[0], entry[1], entry[2]
			else:
				continue
			if address is None or kind is None or name is None:
				continue
			kind = str(kind)
			section = kind if kind.startswith(".") else "." + kind
			if section not in BOUNDARY_SECTIONS:
				continue
			sections.setdefault(section, []).append((address, kind, str(name)))

	for entries in sections.values():
		entries.sort()
	return sections


def alignment_of(address):
	"""The largest alignment the original actually gives this address."""
	divisors = [candidate for candidate in ALIGN_CANDIDATES if address % candidate == 0]
	return max(divisors) if divisors else ALIGN_CANDIDATES[0]


def section_alignments(config):
	alignments = {}
	for section, entries in subsegment_sections(config).items():
		for address, _, name in entries:
			alignments[(section, os.path.basename(name) + ".o")] = alignment_of(address)
	return alignments


def tail_alignments(config):
	alignments = {}
	for section, entries in subsegment_sections(config).items():
		for index, (_, kind, name) in enumerate(entries):
			if not kind.startswith("."):
				continue
			align = DEFAULT_TAIL_ALIGN
			if index + 1 < len(entries):
				align = alignment_of(entries[index + 1][0])
			alignments[(section, os.path.basename(name) + ".o")] = align
	return alignments


def object_name(obj_path):
	"""MWLD refers to objects by base name, so drop the directories.

	Also strip any per-section suffix, so `spev06.rodata.o` resolves to the
	merged `spev06.o` that merge_translation_units.py produced.
	"""
	name = os.path.basename(obj_path)
	stem = name[: -len(".o")]
	for suffix in SECTION_SUFFIXES:
		if stem.endswith(suffix):
			stem = stem[: -len(suffix)]
			break
	return stem + ".o"


def collect_section_entries(ld_lines, asset_marker=None):
	entries = {section: [] for section in SECTIONS}

	for line in ld_lines:
		match = SECTION_ENTRY_RE.match(line)
		if not match:
			continue

		# ELF metadata, not linked.
		if asset_marker and asset_marker in match.group("obj"):
			continue

		sections = match.group("sections").split()
		if not sections:
			continue

		# Strip the trailing wildcard ld_wildcard_sections adds.
		section = sections[0].rstrip("*")
		if section not in entries:
			continue

		name = object_name(match.group("obj"))
		# crt0 is placed explicitly by the template.
		if name.startswith("crt0."):
			continue

		entries[section].append(name)

	return entries


	"""Render one section's object list as indented MWLD lcf lines."""
def format_section_entries(section, object_names, starts, tails):
	lines = []
	for i, name in enumerate(object_names):
		# The first line lands on an already-indented placeholder.
		indent = "" if i == 0 else "\t\t"
		tail = tails.get((section, name))

		if section in ALIGNED_SECTIONS:
			start = starts.get((section, name), DEFAULT_ALIGNALL)
			lines.append(f"{indent}. = ALIGN({hex(start)});\n" if tail is not None
				else f"{indent}ALIGNALL({hex(start)});\n")
			indent = "\t\t"
			if tail is not None:
				floor = COMPILED_ALIGNALL.get(section, DEFAULT_COMPILED_ALIGNALL)
				lines.append(f"{indent}ALIGNALL({hex(floor)});\n")

		lines.append(f"{indent}{name}\t({section})\n")
		if tail is not None:
			lines.append(f"\t\t. = ALIGN({hex(tail)});\n")
	return "".join(lines)


def main():
	import argparse

	parser = argparse.ArgumentParser(description="Generate an MWLD linker script from Splat's .ld output.")
	parser.add_argument("--splat-yaml-path", default="config/SLUS_20199/SLUS_201.99.yaml", help="Relative path to the Splat config (default: config/SLUS_20199/SLUS_201.99.yaml).")
	parser.add_argument("--splat-ld-linker-path", default=None, help="Relative path to the Splat linker file. Defaults to the ld_script_path in the Splat config.")
	parser.add_argument("--template-linker-path", default="include/template.lcf", help="Relative path to the template linker file (default: include/template.lcf).")
	parser.add_argument("--output-name", default="spps_linker.lcf", help="File name to write into the build directory (default: spps_linker.lcf).")
	args = parser.parse_args()

	base_dir = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "../../"))
	yaml_path = os.path.join(base_dir, args.splat_yaml_path)
	splat_options = load_splat_options(yaml_path)
	with open(yaml_path, "r") as handle:
		config = yaml.safe_load(handle)
	starts = section_alignments(config)
	tails = tail_alignments(config)

	if args.splat_ld_linker_path:
		splat_linker_path = os.path.join(base_dir, args.splat_ld_linker_path)
	else:
		splat_linker_path = splat_options["ld_script_path"]

	build_dir = splat_options["build_path"]
	output_linker_path = os.path.join(build_dir, args.output_name)
	template_linker_path = os.path.join(base_dir, args.template_linker_path)

	print(f"Splat Config: {os.path.join(base_dir, args.splat_yaml_path)}")
	print(f"Splat Linker Path: {splat_linker_path}")
	print(f"Build Directory: {build_dir}")

	with open(splat_linker_path, "r") as splat_linker_file:
		entries = collect_section_entries(splat_linker_file.readlines(), splat_options["asset_path"])

	for section in SECTIONS:
		print(f"  {section}: {len(entries[section])} objects")

	with open(template_linker_path, "r") as template_linker_file:
		template_lines = template_linker_file.readlines()

	updated_lines = template_lines
	for section in SECTIONS:
		rendered = format_section_entries(section, entries[section], starts, tails)
		updated_lines = [line.replace(PLACEHOLDERS[section], rendered) for line in updated_lines]

	os.makedirs(build_dir, exist_ok=True)
	with open(output_linker_path, "w+") as output_linker_file:
		output_linker_file.writelines(updated_lines)

	print(f"Wrote {output_linker_path}")


if __name__ == "__main__":
	main()
