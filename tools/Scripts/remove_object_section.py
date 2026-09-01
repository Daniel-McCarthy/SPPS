# This script is used to remove empty sections from object files to avoid MWLD linker errors.
# This is purely a workaround that is likely not needed for other projects.
import subprocess
import glob
import argparse
import os

def get_section_sizes(obj_file, objdump_path):
	"""Return a dict of section sizes from objdump output."""
	objdump = 'objdump' if not objdump_path else objdump_path
	result = subprocess.run(
		[objdump, '-h', obj_file],
		capture_output=True,
		text=True,
		check=True
	)

	sizes = {}
	for line in result.stdout.splitlines():
		parts = line.split()
		if len(parts) >= 6 and parts[0].isdigit():
			section_name = parts[1]
			size_hex = parts[2]
			sizes[section_name] = int(size_hex, 16)
	return sizes

def remove_section(obj_file, section, objcopy_path):
	"""Use objcopy to remove the section from the object file."""
	objcopy = 'mipsel-linux-gnu-objcopy' if not objcopy_path else objcopy_path
	print(f"[*] Removing section '{section}' from {obj_file}")
	subprocess.run(
		[objcopy, f'--remove-section=.{section}', obj_file],
		check=True
	)

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('extension', help='File extension for object files (e.g. .bss.s.o)')
	parser.add_argument('section', help='Section name to remove if empty (e.g. bss)')
	parser.add_argument('--objdump_path', help='Optional path to objdump to override use of mipsel-gnu-linux-objdump')
	parser.add_argument('--objcopy_path', help='Optional path to objcopy to override use of mipsel-gnu-linux-objcopy')
	parser.add_argument('--root', help='Directory to search for object files (default: build/). Scope this to the assembled objects so compiled C objects are left alone.')
	args = parser.parse_args()

	extension = args.extension
	section = args.section
	objdump_path = args.objdump_path
	objcopy_path = args.objcopy_path
	base_dir = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '../../'))
	search_dir = os.path.join(base_dir, args.root) if args.root else os.path.join(base_dir, 'build')

	files = []
	for root, _, filenames in os.walk(search_dir):
		for filename in filenames:
			if filename.endswith(extension):
				files.append(os.path.join(root, filename))

	# Don't remove .bss from the objects that exist to carry .bss
	if section == 'bss':
		files = [file for file in files if not file.endswith('.bss.o')]
	# Don't remove .data from the objects that exist to carry .data
	if section == 'data':
		files = [file for file in files if not file.endswith('.data.o')]

	if not files:
		print(f"WARNING: No files ending in '{extension}' found under {search_dir}")
		return

	for file in files:
		try:
			sizes = get_section_sizes(file, objdump_path)
			if f".{section}" not in sizes:
				continue

			size = sizes[f".{section}"]
			# A non-empty section is the normal case and is left alone; only
			# the removals are worth reporting.
			if size == 0:
				remove_section(file, section, objcopy_path)
		except subprocess.CalledProcessError as e:
			print(f"Error processing {file}: {e}")

if __name__ == '__main__':
	main()
