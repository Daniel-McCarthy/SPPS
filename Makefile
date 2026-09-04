.PHONY: install splat-us build-us clean-us

INCLUDE_DIR     := include
ISO_DIR         := iso
ISO_EXTRACT_DIR := iso/extract

US_DIR 			:= config/SLUS_20199
US_OUTPUT_DIR 	:= config/SLUS_20199/out
US_ASSETS_DIR	:= config/SLUS_20199/out/assets
US_ASM_DIR 		:= config/SLUS_20199/out/asm
US_SRC_DIR		:= src/SLUS_20199
US_YAML_FILE	:= config/SLUS_20199/SLUS_201.99.yaml
US_ROM_FILE		:= config/SLUS_20199/SLUS_201.99
US_ISO_FILE		:= $(ISO_DIR)/SLUS_20199.iso
US_UNDEF_SYMS_AUTO 	:= $(US_DIR)/undefined_syms_auto.yaml
US_UNDEF_FUNCS_AUTO := $(US_DIR)/undefined_funcs_auto.yaml

US_SRC_SPPBX_DIR := $(US_SRC_DIR)/E/tam/ps2/sppbx
US_SRC_SOURCE_DIR := $(US_SRC_DIR)/Z/ul/ul/source

JP_DIR 			:= config/SLPM_65198
JP_OUTPUT_DIR 	:= config/SLPM_65198/out
JP_ASSETS_DIR	:= config/SLPM_65198/out/assets
JP_ASM_DIR 		:= config/SLPM_65198/out/asm
JP_SRC_DIR		:= src/SLPM_65198
JP_YAML_FILE	:= config/SLPM_65198/SPPS_JP.yaml
JP_ROM_FILE		:= config/SLPM_65198/SLPM_651.98
JP_UNDEF_SYMS_AUTO 	:= $(JP_DIR)/undefined_syms_auto.yaml
JP_UNDEF_FUNCS_AUTO := $(JP_DIR)/undefined_funcs_auto.yaml

BUILD_DIR		:= build
LINK_DIR		:= $(BUILD_DIR)/link
TARGET_DIR		:= $(BUILD_DIR)/target
OBJDIFF_CLI		:= ./tools/objdiff/objdiff-cli
REPORT_FILE		:= $(BUILD_DIR)/report.json
OUTPUT_ELF		:= $(BUILD_DIR)/SLUS_201.99.elf

BINUTILS_DIR    := ./tools/binutils/mips-ps2-decompals-

AS              := $(BINUTILS_DIR)as
GNULD           := $(BINUTILS_DIR)ld
OBJCOPY         := $(BINUTILS_DIR)objcopy
OBJDUMP         := $(BINUTILS_DIR)objdump
GCC             := $(BINUTILS_DIR)gcc
STRIP           := $(BINUTILS_DIR)strip

REMOVE_SECTION_ARGS := --objcopy_path $(OBJCOPY) --objdump_path $(OBJDUMP) --root $(LINK_DIR)

AS_FLAGS := -EL -I$(INCLUDE_DIR) -G 128 -march=r5900 -mabi=eabi -no-pad-sections -mno-pdr

PYTHON 	:= python3
# SPLAT  	:= $(PYTHON) -m splat split
PIP 	:= $(PYTHON) -m pip

WIBO := tools/wibo/wibo

COMPILER_LOCATION := tools/compiler/MWCCPS2-2.4

MWCC_PATH := $(COMPILER_LOCATION)/mwccps2.exe
MWCC := $(WIBO) $(MWCC_PATH)
MWLD := $(WIBO) $(COMPILER_LOCATION)/mwldps2.exe
MWCC_ARGS := -Iinclude -O0,p -sym on -char unsigned -str readonly
MWCCGAP := $(PYTHON) tools/mwccgap/mwccgap.py
MWCCGAP_ARGS := --mwcc-path $(MWCC_PATH) --as-path $(AS) --macro-inc-path $(INCLUDE_DIR)/macro.inc --use-wibo --wibo-path $(WIBO) --as-march r5900 --as-mabi eabi $(MWCC_ARGS)
ALL_C_FILES := $(shell find $(US_SRC_DIR) -name '*.c' -not -path *nonmatchings* 2>/dev/null)
C_FILES := $(shell $(PYTHON) tools/Scripts/list_subsegments.py --splat-yaml-path $(US_YAML_FILE) --kind c --prefix $(US_SRC_DIR)/ --suffix .c 2>/dev/null)

ALL_S_FILES := $(shell find $(US_ASM_DIR) -name '*.s' -not -path *nonmatchings* 2>/dev/null) # recursively grabs .s files not in nonmatchings and suppresses errors
FULL_DISASM_S_FILES := $(patsubst $(US_SRC_DIR)/%.c,$(US_ASM_DIR)/%.s,$(C_FILES))
S_FILES := $(filter-out $(FULL_DISASM_S_FILES),$(ALL_S_FILES))

OBJDIFF_BASE_DIR := $(BUILD_DIR)/objdiff
OBJDIFF_BASE_O_FILES := $(patsubst $(US_SRC_DIR)/%.c,$(OBJDIFF_BASE_DIR)/%.o,$(ALL_C_FILES))

ASM_O_FILES := $(patsubst %.s,$(BUILD_DIR)/%.o,$(S_FILES))
C_O_FILES := $(patsubst %.c,$(BUILD_DIR)/%.o,$(C_FILES))

US_LD_SCRIPT	:= $(US_DIR)/SLUS_201.99.ld

US_SRC_FILES	:= $(foreach dir,$(US_SRC_DIR),$(wildcard $(dir)/*.c))
US_ASM_FILES	:= $(foreach dir,$(US_ASM_DIR),$(wildcard $(dir)/*.s))

# Make install - Installs Python required and other required dependencies.
install:
	$(PIP) install -r requirements.txt
	$(MAKE) download-wibo
	$(MAKE) download-decompals-binutils
	$(MAKE) download-mwcc
	$(MAKE) download-objdiff

# Make install-dev - Installs Python dev dependencies and other tools purely for development needs (not essential for building).
install-dev:
	$(PIP) install -r requirements-dev.txt
	$(MAKE) download-coddog

# Make splat-us - Runs Splat for the US version of SPPS.
splat-us:
	$(MAKE) clean-us
	@echo "Running Splat for US 201.99"
	$(PYTHON) -m splat split ./$(US_YAML_FILE)

# Make splat-jp - Runs Splat for the Japanese version of SPPS.
splat-jp:
	$(MAKE) clean-jp
	@echo "Running Splat for SLPM 651.98"
	$(PYTHON) -m splat split ./$(JP_YAML_FILE)

# Clean the build dir then compile and assemble the .c and .s files into .o files
build: clean-build-dir compile assemble

# Compile a .c file for each needed c.o file expected in the build dir
compile:  $(C_O_FILES)

# Assemble a .s file for each needed s.o file expected the build dir
assemble: $(ASM_O_FILES)

link:
	$(MAKE) convert-ld
	$(MAKE) merge-objects
	$(MAKE) strip-toolchain-sections
	$(MAKE) remove-unneeded-sections
	$(MAKE) mwld-convert

# Make .o from .s in build dir
# Assemble pattern
$(BUILD_DIR)/$(US_ASM_DIR)/%.o: $(US_ASM_DIR)/%.s
	@mkdir -p $(dir $@)
	$(AS) $(AS_FLAGS) -o $@ $<

# Make .o from .c in build dir
# Compile pattern
$(BUILD_DIR)/$(US_SRC_DIR)/%.o: $(US_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(MWCC) $(MWCC_ARGS) -c -o $@ $<

# objdiff base pattern: plain MWCC, no asm splicing.
$(OBJDIFF_BASE_DIR)/%.o: $(US_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(MWCC) $(MWCC_ARGS) -c -o $@ $<



# Cleans splat related temporary files
clean-us:
	@echo "Cleaning output and build directories"
	$(RM) -r $(US_OUTPUT_DIR)/ $(US_DIR)/.splat/
	$(RM) $(US_LD_SCRIPT)
	$(RM) $(US_DIR)/undefined_funcs_auto.yaml
	$(RM) $(US_DIR)/undefined_syms_auto.yaml
	$(RM) -r .splat/
	$(RM) -r .splache $(US_DIR)/.splache

clean-jp:
	@echo "Cleaning output and build directories"
	$(RM) -r $(JP_OUTPUT_DIR)/ $(JP_DIR)/.splat/
	$(RM) $(JP_DIR)/undefined_funcs_auto.yaml
	$(RM) $(JP_DIR)/undefined_syms_auto.yaml
	$(RM) -r .splat/
	$(RM) -r .splache $(JP_DIR)/.splache

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
	$(MWLD) -g -map -m __start -nodead -o $(OUTPUT_ELF).2 $(INCLUDE_DIR)/mwcc.lcf \
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
	$(MWLD) -g -map -nodead -o $(OUTPUT_ELF) $(BUILD_DIR)/spps_linker.lcf \
		$(shell find $(LINK_DIR) -name '*.o')
	@readelf -S $(OUTPUT_ELF) > $(OUTPUT_ELF).sections.txt
	@readelf -S $(US_DIR)/SLUS_201.99 > $(BUILD_DIR)/SLUS_201.99.expected.sections.txt
	
	@if [ ! -f "$(OUTPUT_ELF)" ]; then echo "❌ Failed to build ELF"; exit 1; fi
	@echo "Built ELF: $(OUTPUT_ELF)"
	@$(MAKE) --no-print-directory verify

# Fails if the loaded section does not match the original. The whole-ELF CRC
# never matches, since MWLD writes its own symbol table and debug info.
verify:
	@$(OBJCOPY) -I elf32-little -O binary --only-section=main $(US_ROM_FILE) $(BUILD_DIR)/expected_main.bin
	@$(OBJCOPY) -O binary --only-section=main $(OUTPUT_ELF) $(BUILD_DIR)/actual_main.bin
	@if cmp -s $(BUILD_DIR)/expected_main.bin $(BUILD_DIR)/actual_main.bin; then \
		echo "✅ main section matches the original ($$(stat -c%s $(BUILD_DIR)/expected_main.bin) bytes)"; \
	else \
		echo "❌ main section differs from the original"; \
		echo "   expected $$(stat -c%s $(BUILD_DIR)/expected_main.bin) bytes, got $$(stat -c%s $(BUILD_DIR)/actual_main.bin) bytes"; \
		cmp $(BUILD_DIR)/expected_main.bin $(BUILD_DIR)/actual_main.bin || true; \
		exit 1; \
	fi

# Removes uneeded sections from the object files as a work around for unresolved linker issues.
STRIP_SECTIONS := .comment .reginfo .MIPS.abiflags .gnu.attributes

strip-toolchain-sections:
	@echo "Stripping toolchain sections from link objects"
	@find $(LINK_DIR) -name '*.o' -exec $(OBJCOPY) \
		$(foreach section,$(STRIP_SECTIONS),--remove-section=$(section)) {} \;

remove-unneeded-sections:
	$(PYTHON) tools/Scripts/remove_object_section.py $(REMOVE_SECTION_ARGS) ".o" bss
	$(PYTHON) tools/Scripts/remove_object_section.py $(REMOVE_SECTION_ARGS) ".o" data
	$(PYTHON) tools/Scripts/remove_object_section.py $(REMOVE_SECTION_ARGS) ".o" text

remove-unneeded-objects:
	@echo "No unneeded objects to remove"

merge-objects:
	@echo "Building one object per translation unit"
	$(PYTHON) tools/Scripts/merge_translation_units.py \
		--asm-dir $(US_ASM_DIR) \
		--src-dir $(US_SRC_DIR) \
		--c-obj-dir $(BUILD_DIR)/$(US_SRC_DIR) \
		--out-dir $(LINK_DIR) \
		--as-path $(AS) \
		--as-flags "$(AS_FLAGS)" \
		--ld $(GNULD) \
		--work-dir $(BUILD_DIR)/merged_sources \
		--splat-yaml-path $(US_YAML_FILE) \
		--target-out-dir $(TARGET_DIR)

# Compile every .c with plain MWCC for objdiff to measure against.
objdiff-base: $(OBJDIFF_BASE_O_FILES)

# Regenerate objdiff.json from the splat config. Needs the target objects to
# exist, so run it after a build.
objdiff-config:
	$(PYTHON) tools/Scripts/generate_objdiff_config.py \
		--splat-yaml-path $(US_YAML_FILE) \
		--target-dir $(TARGET_DIR) \
		--base-dir $(OBJDIFF_BASE_DIR)

# Generate the objdiff progress report, for upload to decomp.dev.
report: objdiff-base objdiff-config
	@echo "Generating progress report"
	$(OBJDIFF_CLI) report generate -o $(REPORT_FILE)
	@$(PYTHON) tools/Scripts/summarize_report.py $(REPORT_FILE)

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
	$(MAKE) merge-objects
	$(MAKE) strip-toolchain-sections
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

# Generates a new build and generates the MWLD .lcf linker script
rebuild-link:
	$(MAKE) rebuild
	$(MAKE) mwld-convert

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

OBJDIFF_VERSION := v3.8.1

download-objdiff:
	@echo Downloading objdiff-cli
	-@mkdir -p $(dir $(OBJDIFF_CLI))
	wget -O $(OBJDIFF_CLI) https://github.com/encounter/objdiff/releases/download/$(OBJDIFF_VERSION)/objdiff-cli-linux-x86_64
	chmod +x $(OBJDIFF_CLI)

download-wibo:
	@echo Downloading wibo
	-@mkdir tools/wibo
	wget -P ./tools/wibo/ https://github.com/decompals/wibo/releases/download/0.6.16/wibo
	chmod +x $(WIBO)

# Optional: Downloads coddog for function matching functionality for development
download-coddog:
	@echo Downloading coddog
	-@mkdir tools/coddog
	wget https://github.com/ethteck/coddog/releases/download/0.4.0/coddog_0.4.0_x86_64-unknown-linux-musl.tar.gz
	@echo "📦 Extracting coddog..."
	7z x coddog_0.4.0_x86_64-unknown-linux-musl.tar.gz >/dev/null;
	7z x coddog_0.4.0_x86_64-unknown-linux-musl.tar -o./tools/coddog >/dev/null;
	-$(RM) "coddog_0.4.0_x86_64-unknown-linux-musl.tar.gz"
	-$(RM) "coddog_0.4.0_x86_64-unknown-linux-musl.tar"


setup-venv:
	$(PYTHON) -m venv venv
	$(MAKE) venv

# Runs spimdisasm against the Japanese version of SPPS generating asm enriched with our symbol_addresses.txt
spim-jp:
	$(PYTHON) -m spimdisasm elfObjDisasm $(JP_ROM_FILE) $(JP_DIR) --symbol-addrs $(JP_DIR)/symbol_addresses.txt
	mv $(JP_DIR)/SLPM_651_.text.s $(JP_DIR)/SLPM_65198-spim-w-symbols.txt
