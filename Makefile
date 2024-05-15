.PHONY: install splatUS buildUS

# Make install - Installs Python dependencies.
install:
	python3 -m pip install -r requirements.txt

# Make splatUS - Runs Splat for the US version of SPPS.
splatUS:
	python3 -m splat split ./SLUS_201-99/SPPS_US.yaml

