"""List the code subsegments of a given type from a splat config.

"""

import argparse
import sys

import yaml


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--splat-yaml-path", default="config/SLUS_20199/SLUS_201.99.yaml")
    parser.add_argument("--kind", default="c", help="Subsegment type to list (default: c).")
    parser.add_argument("--suffix", default="", help="Appended to each name, e.g. .c")
    parser.add_argument("--prefix", default="", help="Prepended to each name.")
    args = parser.parse_args()

    with open(args.splat_yaml_path) as handle:
        config = yaml.safe_load(handle)

    if not config:
        sys.exit(f"Empty or unreadable splat config: {args.splat_yaml_path}")

    for segment in config.get("segments", []):
        if not isinstance(segment, dict):
            continue
        for entry in segment.get("subsegments", []):
            if isinstance(entry, list) and len(entry) >= 3 and entry[1] == args.kind:
                print(f"{args.prefix}{entry[2]}{args.suffix}")


if __name__ == "__main__":
    main()
