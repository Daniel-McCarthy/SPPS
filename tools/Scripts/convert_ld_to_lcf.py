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

RODATA_ALIGNALL = 0x8


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


def format_section_entries(section, object_names):
	"""Render one section's object list as indented MWLD lcf lines."""
	lines = []
	for i, name in enumerate(object_names):
		# The first line lands on an already-indented placeholder.
		indent = "" if i == 0 else "\t\t"
		if section == ".rodata":
			lines.append(f"{indent}ALIGNALL({hex(RODATA_ALIGNALL)});\n")
			indent = "\t\t"
		lines.append(f"{indent}{name}\t({section})\n")
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
	splat_options = load_splat_options(os.path.join(base_dir, args.splat_yaml_path))

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
		rendered = format_section_entries(section, entries[section])
		updated_lines = [line.replace(PLACEHOLDERS[section], rendered) for line in updated_lines]

	os.makedirs(build_dir, exist_ok=True)
	with open(output_linker_path, "w+") as output_linker_file:
		output_linker_file.writelines(updated_lines)

	print(f"Wrote {output_linker_path}")


if __name__ == "__main__":
	main()
