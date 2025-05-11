## Prerequisites:
- The SPPS SLUS_201.99 elf binary.
- Linux or WSL (binutils-mips-linux-gnu)
- Python3 interpreter

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
