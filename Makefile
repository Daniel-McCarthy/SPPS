.PHONY: install splat-us build-us clean-us
US_DIR := config_SLUS20199
US_OUTPUT_DIR := config_SLUS20199/out
US_YAML_FILE := config_SLUS20199/SPPS_US.yaml

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

clean-us:
	@echo "Cleaning output and build directories"
	$(RM) -r $(US_OUTPUT_DIR)/ $(US_DIR)/.splat/
