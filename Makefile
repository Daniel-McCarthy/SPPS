.PHONY: install splat-us build-us clean-us

INCLUDE_DIR     := include
ISO_DIR         := iso
ISO_EXTRACT_DIR := iso/extract

US_DIR 			:= config/SLUS_20199
US_OUTPUT_DIR 	:= config/SLUS_20199/out
US_ASSETS_DIR	:= config/SLUS_20199/out/assets
US_ASM_DIR 		:= config/SLUS_20199/out/asm
US_SRC_DIR		:= src/SLUS_20199
US_YAML_FILE	:= config/SLUS_20199/SPPS_US.yaml
US_ROM_FILE		:= config/SLUS_20199/SLUS_201.99
US_ISO_FILE		:= $(ISO_DIR)/SLUS_20199.iso
US_UNDEF_SYMS_AUTO 	:= $(US_DIR)/undefined_syms_auto.yaml
US_UNDEF_FUNCS_AUTO := $(US_DIR)/undefined_funcs_auto.yaml

US_SRC_SPPBX_DIR := $(US_SRC_DIR)/E/tam/ps2/sppbx
US_SRC_SOURCE_DIR := $(US_SRC_DIR)/Z/ul/ul/source

BUILD_DIR		:= build
OUTPUT_ELF		:= $(BUILD_DIR)/SLUS_201.99.elf

BINUTILS_DIR    := ./tools/binutils/mips-ps2-decompals-

AS              := $(BINUTILS_DIR)as
GNULD           := $(BINUTILS_DIR)ld
OBJCOPY         := $(BINUTILS_DIR)objcopy
OBJDUMP         := $(BINUTILS_DIR)objdump
GCC             := $(BINUTILS_DIR)gcc
STRIP           := $(BINUTILS_DIR)strip

AS_FLAGS := -EL -I$(INCLUDE_DIR) -G 128 -march=r5900 -mabi=eabi -no-pad-sections -mno-pdr

PYTHON 	:= python3
# SPLAT  	:= $(PYTHON) -m splat split
PIP 	:= $(PYTHON) -m pip

WIBO := tools/wibo/wibo

COMPILER_LOCATION := tools/compiler/MWCCPS2-2.4
COMPILER_PS2SUPPORT_DIR := $(COMPILER_LOCATION)/PS2_Support
MWLibraries		  := $(COMPILER_LOCATION)/Stationery/PlayStation2_-_2.0.0/c
MWCIncludes		  := $(COMPILER_PS2SUPPORT_DIR)
export MWLibraries
export MWCIncludes

MWCC_PATH := $(COMPILER_LOCATION)/PS2_Tools/Command_Line_Tools/mwccps2.exe
MWCC := $(WIBO) $(MWCC_PATH)
MWLD := $(WIBO) $(COMPILER_LOCATION)/PS2_Tools/Command_Line_Tools/mwldps2.exe
MWCC_ARGS := -Iinclude -O0,p -sym on -char unsigned -str readonly
MWCCGAP := $(PYTHON) tools/mwccgap/mwccgap.py
MWCCGAP_ARGS := --mwcc-path $(MWCC_PATH) --as-path $(AS) --macro-inc-path $(INCLUDE_DIR)/macro.inc --use-wibo --wibo-path $(WIBO) --as-march r5900 --as-mabi eabi $(MWCC_ARGS)
S_FILES := $(shell find $(US_ASM_DIR) -name '*.s' -not -path *nonmatchings* 2>/dev/null) # recursively grabs .s files not in nonmatchings and suppresses errors
C_FILES := $(shell find $(US_SRC_DIR) -name '*.c' -not -path *nonmatchings* 2>/dev/null) # recursively grabs .c files not in nonmatchings and suppresses errors

# Assembles build dir .o file paths
ASM_O_FILES := $(patsubst %.s,%.s.o,$(S_FILES)) # renames .s files to .s.o
ASM_O_FILES := $(patsubst $(US_ASM_DIR)/%, $(BUILD_DIR)/%,$(ASM_O_FILES)) # renames .s files to build dir
C_O_FILES := $(patsubst %.c,%.c.o,$(C_FILES)) # renames .c files to .c.o
C_O_FILES := $(patsubst $(US_SRC_DIR)/%, $(BUILD_DIR)/%,$(C_O_FILES)) # adds build dir to the front of the file names

US_LD_SCRIPT	:= $(US_OUTPUT_DIR)/SLUS_201.99.ld

US_SRC_FILES	:= $(foreach dir,$(US_SRC_DIR),$(wildcard $(dir)/*.c))
US_ASM_FILES	:= $(foreach dir,$(US_ASM_DIR),$(wildcard $(dir)/*.s))

# Make install - Installs Python required and other required dependencies.
install:
	$(PIP) install -r requirements.txt
	$(MAKE) download-wibo
	$(MAKE) download-decompals-binutils

# Make splat-us - Runs Splat for the US version of SPPS.
splat-us:
	$(MAKE) clean-us
	@echo "Running Splat for US 201.99"
	$(PYTHON) -m splat split ./$(US_YAML_FILE)

# Make build-us - Builds the US version of SPPS.
build-us:
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/main.c -o ./$(BUILD_OBJS_DIR)/main.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/gmpad.c -o ./$(BUILD_OBJS_DIR)/gmpad.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/ktmenu.c -o ./$(BUILD_OBJS_DIR)/ktmenu.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/ktmnufnc.c -o ./$(BUILD_OBJS_DIR)/ktmnufnc.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/spinit.c -o ./$(BUILD_OBJS_DIR)/spinit.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/tmlink.c -o ./$(BUILD_OBJS_DIR)/tmlink.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SOURCE_DIR)/cdvd.c -o ./$(BUILD_OBJS_DIR)/cdvd.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SOURCE_DIR)/mcard.c -o ./$(BUILD_OBJS_DIR)/mcard.o
# Converts paths in the linker script from full paths to relative from the build dir (This is done at linking time)
fix-linker-paths:
	@echo "Fixing linker paths"
	@$(PYTHON) tools/Scripts/update_linker_paths.py $(US_LD_SCRIPT) $(US_ASM_DIR) $(US_SRC_DIR)

# Clean the build dir then compile and assemble the .c and .s files into .o files
build: clean-build-dir compile assemble

# Compile a .c file for each needed c.o file expected in the build dir
compile:  $(C_O_FILES)

# Assemble a .s file for each needed s.o file expected the build dir
assemble: $(ASM_O_FILES)

# Rule: when linking, we need a .elf file
link: fix-linker-paths $(OUTPUT_ELF)

# Make .o from .s in build dir
# Assemble pattern
$(BUILD_DIR)/%.s.o:
	@mkdir -p $(dir $@)
	@echo $(ASM_O_FILES)
	$(AS) $(AS_FLAGS) -o $@ $(US_ASM_DIR)/$*.s

# Make .o from .c in build dir
# Compile pattern
$(BUILD_DIR)/%.c.o: $(US_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(MWCCGAP) $< $@ $(MWCCGAP_ARGS)

# Pattern: to build a .elf we need all the .o files
$(OUTPUT_ELF): $(C_O_FILES) $(ASM_O_FILES)
	$(GNULD) -EL -T $(US_LD_SCRIPT) -T $(US_UNDEF_SYMS_AUTO) -T $(US_UNDEF_FUNCS_AUTO) -o $@ $^


# Cleans splat related temporary files
clean-us:
	@echo "Cleaning output and build directories"
	$(RM) -r $(US_OUTPUT_DIR)/ $(US_DIR)/.splat/
	$(RM) $(US_DIR)/undefined_funcs_auto.yaml
	$(RM) $(US_DIR)/undefined_syms_auto.yaml
	$(RM) -r .splat/
	$(RM) -r .splache $(US_DIR)/.splache

# Cleans the full build directory
clean-build-dir:
	@echo "Cleaning the build directory"
	$(RM) -r $(BUILD_DIR)/
	@echo "Reconstructing build folders"
	@mkdir $(BUILD_DIR)

# Clean compiled .o files from the build dir
clean-c-objects:
	find $(BUILD_DIR) -name '*.c.o' -type f -delete

# Clean assembly .o files from the build dir
clean-asm-objects:
	find $(BUILD_DIR) -name '*.s.o' -type f -delete

# Runs the MWLD linker to create an ELF using the generic MWLD linker script.
mwld:
	@echo "Running mwld"
	$(MWLD) -map -nodead -o $(OUTPUT_ELF).2 $(INCLUDE_DIR)/mwcc.lcf \
		$(shell find $(BUILD_DIR) -name '*.o')
	@readelf -S $(OUTPUT_ELF).2 > $(OUTPUT_ELF).2.sections.txt
	@readelf -S $(US_DIR)/SLUS_201.99 > $(BUILD_DIR)/SLUS_201.99.expected.sections.txt

	@bash -c ' \
	if [ -f "$(OUTPUT_ELF)" ]; then \
		echo "Built ELF: $(OUTPUT_ELF)"; \
		expected_crc32=$$(7z h "$(US_ROM_FILE)" | sed -n "/CRC32/s/.*\([A-F0-9]\{8\}\).*/\1/p"); \
		new_elf_crc32=$$(7z h "$(OUTPUT_ELF).2" | sed -n "/CRC32/s/.*\([A-F0-9]\{8\}\).*/\1/p"); \
		echo "Expected ELF CRC32: $$expected_crc32"; \
		echo "Rebuilt ELF CRC32: $$new_elf_crc32"; \
		if [ "$$expected_crc32" = "$$new_elf_crc32" ]; then \
			echo "✅ Match: ELFs are identical."; \
		else \
			echo "❌ ELF CRC mismatch. Linked ELF CRC32 $$new_elf_crc32 != $$expected_crc32"; \
		fi; \
	else \
		echo "❌ Failed to build ELF"; \
		exit 1; \
	fi'

# Runs the MWLD linker to create an ELF using the our generated .lcf file.
mwld-convert:
	@echo "Running mwld"
	$(MWLD) -map -nodead -o $(OUTPUT_ELF) $(BUILD_DIR)/spps_linker.lcf \
		$(shell find $(BUILD_DIR) -name '*.o')
	@readelf -S $(OUTPUT_ELF) > $(OUTPUT_ELF).sections.txt
	@readelf -S $(US_DIR)/SLUS_201.99 > $(BUILD_DIR)/SLUS_201.99.expected.sections.txt
	
	@bash -c ' \
	if [ -f "$(OUTPUT_ELF)" ]; then \
		echo "Built ELF: $(OUTPUT_ELF)"; \
		expected_crc32=$$(7z h "$(US_ROM_FILE)" | sed -n "/CRC32/s/.*\([A-F0-9]\{8\}\).*/\1/p"); \
		new_elf_crc32=$$(7z h "$(OUTPUT_ELF)" | sed -n "/CRC32/s/.*\([A-F0-9]\{8\}\).*/\1/p"); \
		echo "Expected ELF CRC32: $$expected_crc32"; \
		echo "Rebuilt ELF CRC32: $$new_elf_crc32"; \
		if [ "$$expected_crc32" = "$$new_elf_crc32" ]; then \
			echo "✅ Match: ELFs are identical."; \
		else \
			echo "❌ ELF CRC mismatch. Linked ELF CRC32 $$new_elf_crc32 != $$expected_crc32"; \
		fi; \
	else \
		echo "❌ Failed to build ELF"; \
		exit 1; \
	fi'

# Removes uneeded sections from the object files as a work around for unresolved linker issues.
remove-unneeded-sections:
	$(PYTHON) tools/Scripts/remove_object_section.py ".s.o" bss
	$(PYTHON) tools/Scripts/remove_object_section.py ".s.o" data
	$(PYTHON) tools/Scripts/remove_object_section.py ".sbss.s.o" text
	$(PYTHON) tools/Scripts/remove_object_section.py ".bss.s.o" text
	$(PYTHON) tools/Scripts/remove_object_section.py ".sdata.s.o" text
	$(PYTHON) tools/Scripts/remove_object_section.py ".rodata.s.o" text
	$(PYTHON) tools/Scripts/remove_object_section.py ".data.s.o" text

remove-unneeded-objects:
	$(RM) $(BUILD_DIR)/data/elf_header.s.o
	$(RM) $(BUILD_DIR)/data/shstrtab.s.o
	$(RM) $(BUILD_DIR)/data/strtab.s.o
	$(RM) $(BUILD_DIR)/data/symtab.s.o
	$(RM) $(BUILD_DIR)/data/debug.s.o
	$(RM) $(BUILD_DIR)/data/line.s.o
	$(RM) $(BUILD_DIR)/data/mwcats.s.o
	$(RM) $(BUILD_DIR)/data/relmain.s.o
	$(RM) $(BUILD_DIR)/data/comment.s.o
	$(RM) $(BUILD_DIR)/data/reginfo.s.o
	$(RM) $(BUILD_DIR)/data/end.s.o

# Configure an MWLD .lcf file from the Splat generated GNU .ld file.
convert-ld:
	@$(PYTHON) tools/Scripts/convert_ld_to_lcf.py

# Freshly split, compile, and assemble to prepare for linking.
rebuild:
	@echo "Rebuilding the project"
	$(MAKE) clean-build-dir
	$(MAKE) splat-us
	$(MAKE) compile
	$(MAKE) assemble
	$(MAKE) remove-unneeded-objects
	$(MAKE) convert-ld
	$(MAKE) remove-unneeded-sections
	@echo "✅ Rebuild Done."

rebuild-full-std-linker:
	@echo "Rebuilding the project - with MW linker script"
	$(MAKE) clean-build-dir
	$(MAKE) splat-us
	$(MAKE) compile
	$(MAKE) assemble
	# $(MAKE) remove-unneeded-objects
	$(MAKE) remove-unneeded-sections
	$(MAKE) mwld
	# $(MAKE) extract-iso-with-mkiso-script
	# echo "Removing the extracted ELF..."; \
	# $(RM) "$(ISO_EXTRACT_DIR)/SLUS_201.99"; \
	# echo "Copying built ELF into ISO folder..."; \
	# cp "$(OUTPUT_ELF)" "$(ISO_EXTRACT_DIR)/SLUS_201.99"; \
	# echo "📀 Rebuilding ISO as $(ISO_DIR)/SLUS_201.99.rebuilt.iso..."; \
	# $(PYTHON) tools/mkiso.py --mode insert --output_filename "SLUS_201.99.rebuilt.iso"; \
	@echo "✅ Rebuild Done."

# Full build: Split, compile, and create the full ISO from the linked ELF.
rebuild-full:
	$(MAKE) rebuild
	$(MAKE) mwld-convert
	$(MAKE) build-iso-with-mkiso-script

mwccgap:
	@echo "Running mwccgap"
	$(MWCCGAP) $(US_SRC_SPPBX_DIR)/spinit.c ./$(BUILD_OBJS_DIR)/spinit.o --mwcc-path $(MWCC_PATH) --macro-inc-path $(INCLUDE_DIR)/macro.inc --use-wibo --wibo-path $(WIBO) --as-march r5900 --as-mabi eabi $(MWCC_ARGS)
	$(MWCCGAP) $(US_SRC_SPPBX_DIR)/tmlink.c ./$(BUILD_OBJS_DIR)/tmlink.o --mwcc-path $(MWCC_PATH) --macro-inc-path $(INCLUDE_DIR)/macro.inc --use-wibo --wibo-path $(WIBO) --as-march r5900 --as-mabi eabi $(MWCC_ARGS)

clean-iso-dir:
	@echo "Cleaning ISO directory"
	-$(RM) -r "$(ISO_EXTRACT_DIR)"
	@mkdir "$(ISO_EXTRACT_DIR)"
	-$(RM) "$(ISO_DIR)/SLUS_201.99.rebuilt.iso"
	@echo "✅ Done."

extract-iso:
	@echo "Extracting ISO"
	@if [ -f "$(US_ISO_FILE)" ]; then \
		echo "✅ Found ISO: $(US_ISO_FILE)"; \
		echo "📦 Extracting header.ims..."; \
		dd if="$(US_ISO_FILE)" of="iso/_header.ims" bs=2048 count=321; \
		echo "📦 Extracting ISO..."; \
		7z x "$(US_ISO_FILE)" -o"$(ISO_EXTRACT_DIR)" >/dev/null; \
		echo "Extraction complete."; \
	else \
		echo "❌ ISO not found at path: $(US_ISO_FILE)"; \
		exit 1; \
	fi

extract-iso-with-mkiso-script:
	@echo "Extracting ISO"
	@if [ -f "$(US_ISO_FILE)" ]; then \
		echo "✅ Found ISO: $(US_ISO_FILE)"; \
		echo "📦 Extracting ISO..."; \
		$(PYTHON) tools/mkiso.py --mode extract --iso iso/SLUS_20199.iso; \
	else \
		echo "❌ ISO not found at path: $(US_ISO_FILE)"; \
		exit 1; \
	fi

	@if [ -f "$(ISO_DIR)/SLUS_201.99.rebuilt.iso" ]; then \
		echo "✅ Rebuilt ISO: $(ISO_DIR)/SLUS_201.99.rebuilt.iso"; \
	else \
		echo "❌ Failed to rebuild ISO"; \
		exit 1; \
	fi

build-iso-with-mkiso-script:
	$(MAKE) clean-iso-dir
	@if [ -f "$(US_ISO_FILE)" ]; then \
		echo "✅ Found ISO: $(US_ISO_FILE)"; \
		echo "📦 Extracting ISO..."; \
		$(PYTHON) tools/mkiso.py --mode extract --iso iso/SLUS_20199.iso; \
		# 7z x "$(US_ISO_FILE)" -o"$(ISO_EXTRACT_DIR)" >/dev/null; \
		echo "Removing the extracted ELF..."; \
		$(RM) "$(ISO_EXTRACT_DIR)/SLUS_201.99"; \
		echo "Copying built ELF into ISO folder..."; \
		cp "$(OUTPUT_ELF)" "$(ISO_EXTRACT_DIR)/SLUS_201.99"; \
		echo "📀 Rebuilding ISO as $(ISO_DIR)/SLUS_201.99.rebuilt.iso..."; \
		$(PYTHON) tools/mkiso.py --mode insert --output_filename "SLUS_201.99.rebuilt.iso"; \
	else \
		echo "❌ ISO not found at path: $(US_ISO_FILE)"; \
		exit 1; \
	fi

	@if [ -f "$(ISO_DIR)/SLUS_201.99.rebuilt.iso" ]; then \
		echo "✅ Rebuilt ISO: $(ISO_DIR)/SLUS_201.99.rebuilt.iso"; \
	else \
		echo "❌ Failed to rebuild ISO"; \
		exit 1; \
	fi

build-iso-from-current-folder-state:
	echo "📀 Rebuilding ISO as $(ISO_DIR)/SLUS_201.99.rebuilt.iso..."; \

	$(PYTHON) tools/mkiso.py --mode insert

	@if [ -f "$(ISO_DIR)/SLUS_201.99.rebuilt.iso" ]; then \
		echo "✅ Rebuilt ISO: $(ISO_DIR)/SLUS_201.99.rebuilt.iso"; \
	else \
		echo "❌ Failed to rebuild ISO"; \
		exit 1; \
	fi

download-mwcc:
	-@mkdir -p $(COMPILER_LOCATION)
	wget https://github.com/decompme/compilers/releases/download/compilers/mwcps2-2.4-001213.tar.gz 
	@echo "📦 Extracting MWCC..."
	# | tar xzv -C $(BIN_DIR)
	7z x mwcps2-2.4-001213.tar.gz >/dev/null;
	7z x mwcps2-2.4-001213.tar -o./$(COMPILER_LOCATION) >/dev/null;
	-$(RM) "mwcps2-2.4-001213.tar.gz"
	-$(RM) "mwcps2-2.4-001213.tar"
	@echo "✅ MWCC Download Done."

download-decompals-binutils:
	@echo Downloading decompals binutils
	-$(RM) -r tools/binutils
	-@mkdir tools/binutils
	wget https://github.com/decompals/binutils-mips-ps2-decompals/releases/latest/download/binutils-mips-ps2-decompals-linux-x86-64.tar.gz
	@echo "📦 Extracting binutils..."
	7z x binutils-mips-ps2-decompals-linux-x86-64.tar.gz >/dev/null;
	7z x binutils-mips-ps2-decompals-linux-x86-64.tar -o./tools/binutils >/dev/null;
	-$(RM) "binutils-mips-ps2-decompals-linux-x86-64.tar.gz"
	-$(RM) "binutils-mips-ps2-decompals-linux-x86-64.tar"
	@find tools/binutils -type f -exec chmod +x {} \;
	@echo "✅ Decompals Binutils Download Done."

download-wibo:
	@echo Downloading wibo
	-@mkdir tools/wibo
	wget -P ./tools/wibo/ https://github.com/decompals/wibo/releases/download/0.6.16/wibo
	chmod +x $(WIBO)

setup-venv:
	$(PYTHON) -m venv venv
	$(MAKE) venv
