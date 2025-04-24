.PHONY: install splat-us build-us clean-us

INCLUDE_DIR		:= include

US_DIR 			:= config_SLUS20199
US_OUTPUT_DIR 	:= config_SLUS20199/out
US_ASSETS_DIR	:= config_SLUS20199/out/assets
US_ASM_DIR 		:= config_SLUS20199/out/asm
US_SRC_DIR		:= config_SLUS20199/src
US_YAML_FILE 	:= config_SLUS20199/SPPS_US.yaml
US_ROM_FILE		:= config_SLUS20199/SLUS_201.99

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

MWCC := $(WIBO) tools/MWCCPS2-2.4/mwccps2.exe
MWLD := $(WIBO) tools/MWCCPS2-2.4/mwldps2.exe
MWCC_ARGS := -version -O0,p -opt display -sym on -char unsigned -str readonly

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

clean-us:
	@echo "Cleaning output and build directories"
	$(RM) -r $(US_OUTPUT_DIR)/ $(US_DIR)/.splat/
	$(RM) $(US_DIR)/undefined_funcs_auto.yaml
	$(RM) $(US_DIR)/undefined_syms_auto.yaml

clean-and-reconstruct-build-dir:
	@echo "Cleaning the build directory"
	$(RM) -r $(BUILD_DIR)/
	@echo "Reconstructing build folders"
	@mkdir $(BUILD_DIR)
	@mkdir $(BUILD_OBJS_DIR)