.PHONY: install splat-us build-us clean-us

INCLUDE_DIR		:= include

US_DIR 			:= config/SLUS_20199
US_OUTPUT_DIR 	:= config/SLUS_20199/out
US_ASSETS_DIR	:= config/SLUS_20199/out/assets
US_ASM_DIR 		:= config/SLUS_20199/out/asm
US_SRC_DIR		:= src/SLUS_20199
US_YAML_FILE 	:= config/SLUS_20199/SPPS_US.yaml
US_ROM_FILE		:= config/SLUS_20199/SLUS_201.99

US_SRC_SPPBX_DIR := $(US_SRC_DIR)/E/tam/ps2/sppbx
US_SRC_SOURCE_DIR := $(US_SRC_DIR)/Z/ul/ul/source

BUILD_DIR		:= build
BUILD_OBJS_DIR	:= $(BUILD_DIR)/objects

# Set prefix to mips binutils binaries
CROSS = mips-linux-gnu-

AS              := $(CROSS)as
GNULD           := $(CROSS)ld
OBJCOPY         := $(CROSS)objcopy
OBJDUMP         := $(CROSS)objdump
GCC             := $(CROSS)gcc
CPP             := $(CROSS)cpp
STRIP           := $(CROSS)strip

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

US_LD_SCRIPT	:= config/SLUS_20199/out/SLUS_201.99.ld

US_SRC_FILES	:= $(foreach dir,$(US_SRC_DIR),$(wildcard $(dir)/*.c))
US_ASM_FILES	:= $(foreach dir,$(US_ASM_DIR),$(wildcard $(dir)/*.s))

# Make install - Installs Python dependencies.
install:
	$(PIP) install -r requirements.txt

# Make splat-us - Runs Splat for the US version of SPPS.
splat-us:
	$(MAKE) clean-us
	@echo "Running Splat for US 201.99"
	$(PYTHON) -m splat split ./$(US_YAML_FILE)

# Make build-us - Builds the US version of SPPS.
build-us:
# 	python3 ./$(US_DIR)/configure.py
# 	ninja -C ./$(US_DIR)
	$(MAKE) clean-and-reconstruct-build-dir
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/main.c -o ./$(BUILD_OBJS_DIR)/main.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/gmpad.c -o ./$(BUILD_OBJS_DIR)/gmpad.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/ktmenu.c -o ./$(BUILD_OBJS_DIR)/ktmenu.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/ktmnufnc.c -o ./$(BUILD_OBJS_DIR)/ktmnufnc.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/spinit.c -o ./$(BUILD_OBJS_DIR)/spinit.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SPPBX_DIR)/tmlink.c -o ./$(BUILD_OBJS_DIR)/tmlink.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SOURCE_DIR)/cdvd.c -o ./$(BUILD_OBJS_DIR)/cdvd.o
	@$(MWCC) -c $(MWCC_ARGS) $(US_SRC_SOURCE_DIR)/mcard.c -o ./$(BUILD_OBJS_DIR)/mcard.o

clean-us:
	@echo "Cleaning output and build directories"
	$(RM) -r $(US_OUTPUT_DIR)/ $(US_DIR)/.splat/
	$(RM) $(US_DIR)/undefined_funcs_auto.yaml
	$(RM) $(US_DIR)/undefined_syms_auto.yaml
	$(RM) -r .splat/
	$(RM) -r .splache $(US_DIR)/.splache

clean-and-reconstruct-build-dir:
	@echo "Cleaning the build directory"
	$(RM) -r $(BUILD_DIR)/
	@echo "Reconstructing build folders"
	@mkdir $(BUILD_DIR)
	@mkdir $(BUILD_OBJS_DIR)

mwccgap:
	@echo "Running mwccgap"
	$(MWCCGAP) $(US_SRC_SPPBX_DIR)/spinit.c ./$(BUILD_OBJS_DIR)/spinit.o --mwcc-path $(MWCC_PATH) --macro-inc-path $(INCLUDE_DIR)/macro.inc --use-wibo --wibo-path $(WIBO) --as-march r5900 --as-mabi eabi $(MWCC_ARGS)
	$(MWCCGAP) $(US_SRC_SPPBX_DIR)/tmlink.c ./$(BUILD_OBJS_DIR)/tmlink.o --mwcc-path $(MWCC_PATH) --macro-inc-path $(INCLUDE_DIR)/macro.inc --use-wibo --wibo-path $(WIBO) --as-march r5900 --as-mabi eabi $(MWCC_ARGS)
