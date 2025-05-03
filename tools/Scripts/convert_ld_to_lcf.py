import os
import yaml

def get_linker_file_lines(splat_linker_file_lines):
	# Parse Splat generated .ld linker file and grab lines to convert
	text_o_lines = []
	data_o_lines = []
	sdata_o_lines = []
	bss_o_lines = []
	sbss_o_lines = []
	rodata_o_lines = []

	for line in splat_linker_file_lines:
		if ("(.text);" in line):
			text_o_lines.append(line)
			continue
		if ("(.rodata);" in line):
			rodata_o_lines.append(line)
			continue
		if ("(.data);" in line):
			data_o_lines.append(line)
			continue
		if ("(.sdata);" in line):
			sdata_o_lines.append(line)
			continue
		if ("(.bss);" in line):
			bss_o_lines.append(line)
			continue
		if ("(.sbss);" in line):
			sbss_o_lines.append(line)
			continue
	return text_o_lines, data_o_lines, sdata_o_lines, bss_o_lines, sbss_o_lines, rodata_o_lines

def convert_ld_text_to_lcf(text_o_lines):
	lcf_text_lines = []
	ld_text_pattern = '(.text);'
	for line in text_o_lines:
		if ld_text_pattern not in line:
			raise Exception(f'ERROR: Unexpected line in ld linker text: {line}')
		lcf_text_lines.append(line.replace(ld_text_pattern, ' (.text)'))
	return lcf_text_lines

def convert_ld_data_to_lcf(data_o_lines):
	lcf_data_lines = []
	ld_data_pattern = '(.data);'
	for line in data_o_lines:
		if ld_data_pattern not in line:
			raise Exception(f'ERROR: Unexpected line in ld linker data: {line}')
		lcf_data_lines.append(line.replace(ld_data_pattern, ' (.data)'))
	return lcf_data_lines

def convert_ld_sdata_to_lcf(sdata_o_lines):
	lcf_sdata_lines = []
	ld_sdata_pattern = '(.sdata);'
	for line in sdata_o_lines:
		if ld_sdata_pattern not in line:
			raise Exception(f'ERROR: Unexpected line in ld linker sdata: {line}')
		lcf_sdata_lines.append(line.replace(ld_sdata_pattern, ' (.sdata)'))
	return lcf_sdata_lines

def convert_ld_rodata_to_lcf(rodata_o_lines):
	lcf_rodata_lines = []
	ld_rodata_pattern = '(.rodata);'
	for i, line in enumerate(rodata_o_lines):
		if ld_rodata_pattern not in line:
			raise Exception(f'ERROR: Unexpected line in ld linker rodata: {line}')
		alignall_indendation = '' if i == 0 else '\t\t'
		lcf_rodata_lines.append(f'{alignall_indendation}ALIGNALL(0x8);\n') # TODO: Figure out how to calculate each time, setting to 8 as a default for now
		lcf_rodata_lines.append(line.replace(ld_rodata_pattern, ' (.rodata)'))
	return lcf_rodata_lines

def lcf_files_to_string(lcf_files) -> str:
	lcf_string = ''
	for i, lcf_file_line in enumerate(lcf_files):
		# fixes the first line having double the indentation of the rest of the lines
		spacing_corrected_line = lcf_file_line.replace('        ', '') if i == 0 else lcf_file_line
		lcf_string += f'{spacing_corrected_line}'
	return lcf_string

def convert_ld_bss_to_lcf(bss_o_lines):
	lcf_bss_lines = []
	ld_bss_pattern = '(.bss);'
	for line in bss_o_lines:
		if ld_bss_pattern not in line:
			raise Exception(f'ERROR: Unexpected line in ld linker bss: {line}')
		lcf_bss_lines.append(line.replace(ld_bss_pattern, ' (.bss)'))
	return lcf_bss_lines

def convert_ld_sbss_to_lcf(sbss_o_lines):
	lcf_sbss_lines = []
	ld_sbss_pattern = '(.sbss);'
	for line in sbss_o_lines:
		if ld_sbss_pattern not in line:
			raise Exception(f'ERROR: Unexpected line in ld linker sbss: {line}')
		lcf_sbss_lines.append(line.replace(ld_sbss_pattern, ' (.sbss)'))
	return lcf_sbss_lines

def main():
	import argparse
	# Parse command-line arguments for build directory and Splat YAML file path
	parser = argparse.ArgumentParser(description="Generate MWLD linker script.")
	parser.add_argument("--build-dir", default="build/", help="Relative path to the build directory (default: build/).")
	parser.add_argument("--splat-ld-linker-path", default="config/SLUS_20199/out/SLUS_201.99.ld", help="Relative path to the Splat linker file (default: config/SLUS_20199/out/SLUS_201.99.ld).")
	parser.add_argument("--template-linker-path", default="include/template.lcf", help="Relative path to the template linker file (default: include/template.lcf).")
	args = parser.parse_args()

	# Configure paths/dirs needed for generating the linker file
	base_dir = os.path.normpath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '../../'))
	splat_linker_path = os.path.join(base_dir, args.splat_ld_linker_path)
	build_dir = os.path.join(base_dir, args.build_dir)
	output_linker_path = os.path.join(build_dir, "spps_linker.lcf")
	template_linker_path = os.path.join(base_dir, args.template_linker_path)
	print(f"Build Directory: {build_dir}")
	print(f"Splat Linker Path: {splat_linker_path}")
	print(f"Base Directory: {base_dir}")

	# Load the YAML file at the specified path and print its contents
	with open(splat_linker_path, 'r') as splat_linker_file:
		splat_linker_file_lines = splat_linker_file.readlines()

		# Convert the file paths to relative paths (trim extended asm and src paths)
		splat_linker_file_lines = [line.replace('config/SLUS_20199/out/asm/', '') for line in splat_linker_file_lines]
		splat_linker_file_lines = [line.replace('src/SLUS_20199/', '') for line in splat_linker_file_lines]
		splat_linker_file_lines = [line.replace('build/', '') for line in splat_linker_file_lines]

		# Remove folder structure from linker files entirely
		splat_linker_file_lines = [ f'\t\t{os.path.basename(line)}' for line in splat_linker_file_lines]

		# Filter out crt0 segments as they are already accounted for in the template linker file
		splat_linker_file_lines = [line for line in splat_linker_file_lines if "crt0" not in line]

		# Convert the file string lists into singular strings that can be replaced in the template linker file
		text_o_lines, data_o_lines, sdata_o_lines, bss_o_lines, sbss_o_lines, rodata_o_lines = get_linker_file_lines(splat_linker_file_lines)
		lcf_text_lines = convert_ld_text_to_lcf(text_o_lines)
		lcf_data_lines = convert_ld_data_to_lcf(data_o_lines)
		lcf_sdata_lines = convert_ld_sdata_to_lcf(sdata_o_lines)
		lcf_bss_lines = convert_ld_bss_to_lcf(bss_o_lines)
		lcf_sbss_lines = convert_ld_sbss_to_lcf(sbss_o_lines)
		lcf_rodata_lines = convert_ld_rodata_to_lcf(rodata_o_lines)

		# Make sure this is the right thing to do.....
		lcf_bss_lines = [line for line in lcf_bss_lines if ".bss." in line]


		# Open the file at output_linker_path for writing and write the linker script
		with open(template_linker_path, 'r') as template_linker_file:
			template_lines = template_linker_file.readlines()

			# text_files_list_string = generate_text_section_linker_files(text_segments)
			lcf_text_files_string = lcf_files_to_string(lcf_text_lines)
			lcf_data_files_string = lcf_files_to_string(lcf_data_lines)
			lcf_rodata_files_string = lcf_files_to_string(lcf_rodata_lines)
			lcf_sdata_files_string = lcf_files_to_string(lcf_sdata_lines)
			lcf_bss_files_string = lcf_files_to_string(lcf_bss_lines)
			lcf_sbss_files_string = lcf_files_to_string(lcf_sbss_lines)

			updated_lines = [line.replace("#<REPLACE_W_TEXT_FILES>", lcf_text_files_string) for line in template_lines]
			updated_lines = [line.replace("#<REPLACE_W_DATA_FILES>", lcf_data_files_string) for line in updated_lines]
			updated_lines = [line.replace("#<REPLACE_W_RODATA_FILES>", lcf_rodata_files_string) for line in updated_lines]
			updated_lines = [line.replace("#<REPLACE_W_SDATA_FILES>", lcf_sdata_files_string) for line in updated_lines]
			updated_lines = [line.replace("#<REPLACE_W_BSS_FILES>", lcf_bss_files_string) for line in updated_lines]
			updated_lines = [line.replace("#<REPLACE_W_SBSS_FILES>", lcf_sbss_files_string) for line in updated_lines]

			# Write the updated content back to the linker file
			with open(output_linker_path, 'w+') as output_linker_file:
				output_linker_file.writelines(updated_lines)

if __name__ == "__main__":
	main()