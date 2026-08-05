## Prerequisites:
- The SPPS SLUS_201.99 or SLPM_651.98 elf binary.
- Linux or WSL
- Python3 interpreter
- 7Zip
- Optional: venv

### Dev Container
This repository includes a VS Code Dev Container config at `.devcontainer/`.

To open the project in a dev container:
1. Install Docker and the VS Code Remote Development extension pack (including Dev Containers).
2. Open the repo in VS Code.
3. Run `Remote-Containers: Reopen in Container` from the Command Palette.

The container is built from `.devcontainer/Dockerfile` and mounts the repo at `/workspace`.
It also creates a Python virtual environment at `/opt/venv` and installs `requirements.txt` automatically.

## Commands

To install the required python modules and other dependencies, run at the root directory:
`make install`

And for development only dependencies, run:
`python3 -m pip install -r requirements-dev.txt` or `make install-dev`

To clone the Mwccgap submodule (if not cloned in with the git repo):

`git submodule update --init --recursive`

To run splat for the US version of the game, run at the root directory:
`python3 -m splat split ./config/SLUS_20199/SPPS_US.yaml`
Or with Make:
`make splat-us`

To run splat, compile and link the resulting elf file, run:
`make rebuild`

For your python environment, it is is highly recommended to configure a virtual environment. Here are the steps for Ubuntu:
```
sudo apt install python3-venv
python3 -m venv venv
source venv/bin/activate
```

# Setup for a fresh Ubuntu WSL install:
```
# Clone with submodules
git clone --recurse-submodule https://github.com/Daniel-McCarthy/SPPS.git

# Install and configure venv
sudo apt install python3-pip
sudo apt install python3-venv
make setup-venv
source venv/bin/activate

# Install dependencies
sudo apt install 7zip
make install
make install-dev # optional, for development work only

# Copy your ISO file to iso/SLUS_20199.iso
# Extract the elf file (or run make extract-iso) and copy it to /config/SLUS_20199/SLUS_201.99
```
Note: instead of using the standard `mipsel-gnu-linux-binutils` the [Decompals binutils](https://github.com/decompals/binutils-mips-ps2-decompals) is downloaded and used. It is statically linked against Glibc therefore an up-to-date glibc may be required.

# Special Thanks

A huge thanks is due to [@ethteck](https://github.com/ethteck), [@mkst](https://github.com/mkst), [@encounter](https://github.com/encounter), [@Decompals](https://github.com/decompals), and [@chaoticgd](https://github.com/chaoticgd) for the excellent and foundational tooling that has paved the way for huge improvements in way decompilation is done. Without them and their hard work (and to the contributors to these projects), this project would not exist.

- [splat](https://github.com/ethteck/splat) - Used for splitting the elf binaries and managing (alongside [spimdisasm](https://github.com/Decompollaborate/spimdisasm)) and generating MIPS assembly out of the binary.
- [decomp.me](https://github.com/decompme/decomp.me) - A vital platform making the process of matching functions significantly easier and smoother.
- [mwccgap](https://github.com/mkst/mwccgap) - A tool adding support for `#INCLUDE_ASM` to MWCC allowing matching to the function level rather than TU level.
- [decomp-toolkit](https://github.com/encounter/decomp-toolkit) - A great project assisting decompilation - for this project the DWARF symbol support was of great use.
- [decompals binutils](https://github.com/decompals/binutils-mips-ps2-decompals) - A project maintaining an EE supporting set of the `binutils` including patches to improve them.
- [ghidra-emotionengine-reloaded](https://github.com/chaoticgd/ghidra-emotionengine-reloaded) - A Ghidra plugin supporting PS2 EE cpu MIPS instruction set support and handling of symbols.

And a *big* thanks to [@Mc-muffin](https://github.com/Mc-muffin), [@1superchip](https://github.com/1superchip), and [@benoitren](https://git.sr.ht/~benoitren) for huge amounts of help on matching functions, and all sorts of help along the way.
And thanks to pool7 for his tireless archival of the MW compilers among other tools greatly relied on by the community.

