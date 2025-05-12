# This script is used to remove empty sections from object files to avoid MWLD linker errors.
# This is purely a workaround that is likely not needed for other projects.
import subprocess
import glob
import argparse
import os

def get_section_sizes(obj_file):
	"""Return a dict of section sizes from objdump output."""
	result = subprocess.run(
		['objdump', '-h', obj_file],
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

def remove_section(obj_file, section):
	"""Use objcopy to remove the section from the object file."""
	print(f"[*] Removing section '{section}' from {obj_file}")
	subprocess.run(
		['mipsel-linux-gnu-objcopy', f'--remove-section=.{section}', obj_file],
		check=True
	)

def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('extension', help='File extension for object files (e.g. .bss.s.o)')
	parser.add_argument('section', help='Section name to remove if empty (e.g. bss)')
	args = parser.parse_args()

	extension = args.extension
	section = args.section
	base_dir = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '../../'))
	build_dir = os.path.join(base_dir, 'build')

	files = []
	for root, _, filenames in os.walk(build_dir):
		for filename in filenames:
			if filename.endswith(extension):
				files.append(os.path.join(root, filename))

	# Don't remove .bss from .bss.s.o files
	if section == 'bss':
		files = [file for file in files if '.bss.s.o' not in file]
	# Don't remove .data from .data.o files
	if section == 'data':
		files = [file for file in files if '.data.s.o' not in file]

	if not files:
		print(f"WARNING: No files matched pattern: {args.pattern}")
		return

	for file in files:
		try:
			sizes = get_section_sizes(file)
			if f".{section}" not in sizes:
				continue

			size = sizes[f".{section}"]
			if size == 0:
				remove_section(file, section)
			else:
				print(f"WARNING: {file} contains non-empty '.{section}' ({size} bytes), not removing.")
		except subprocess.CalledProcessError as e:
			print(f"Error processing {file}: {e}")

if __name__ == '__main__':
	main()
