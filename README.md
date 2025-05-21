## Prerequisites:
- The SPPS SLUS_201.99 elf binary.
- Linux or WSL
- Python3 interpreter
- 7Zip
- Optional: venv

To install the required python modules, run at the root directory:

`python3 -m pip install -r requirements.txt`
Or with Make:
`make install`

To clone the Mwccgap submodule (if not cloned in with the git repo):

`git submodule update --init --recursive`

To run splat for the US version of the game, run at the root directory:
`python3 -m splat split ./config/SLUS_20199/SPPS_US.yaml`
Or with Make:
`make splat-us`

For rebuilding the iso, the `mkisofs` program will be required. It can be installed on debian systems as such:
`sudo apt install genisoimage`

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

# Copy your ISO file to iso/SLUS_20199.iso
# Extract the elf file (or run make extract-iso) and copy it to /config/SLUS_20199/SLUS_201.99
```
Note: instead of using the standard `mipsel-gnu-linux-binutils` the [Decompals binutils](https://github.com/decompals/binutils-mips-ps2-decompals) is downloaded and used. It is statically linked against Glibc therefore an up-to-date glibc may be required.
