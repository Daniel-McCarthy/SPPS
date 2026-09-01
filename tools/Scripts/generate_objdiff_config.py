import argparse
import json
import os
import re
import sys
from pathlib import Path

import yaml

DEFAULT_EXCLUDES = ("crt0", "sdk", "sdk_b", "sdk_c", "sdk_d", "sdk2")
CATEGORY_RULES = (
    ("E/tam/ps2/sppbx", "game", "Game Code"),
    ("Z/ul/ul/source", "ul", "UL Engine"),
)
FALLBACK_CATEGORY = ("other", "Other")


def categorize(name):
    for prefix, identifier, _ in CATEGORY_RULES:
        if name.startswith(prefix + "/"):
            return identifier
    return FALLBACK_CATEGORY[0]


def load_options(config):
    return config.get("options", {})


def resolve(base_path, options, key, default):
    return os.path.normpath(os.path.join(base_path, options.get(key, default)))


def collect_code_subsegments(config):
    subsegments = []
    for segment in config.get("segments", []):
        if not isinstance(segment, dict):
            continue
        for entry in segment.get("subsegments", []):
            if not isinstance(entry, list) or len(entry) < 3:
                continue
            _, kind, name = entry[0], entry[1], entry[2]
            if kind in ("asm", "c", "hasm"):
                subsegments.append((str(name), str(kind)))
    return subsegments


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--splat-yaml-path", default="config/SLUS_20199/SLUS_201.99.yaml")
    parser.add_argument("--target-dir", default="build/target", help="Where the objdiff target objects live.")
    parser.add_argument("--base-dir", default="build/objdiff", help="Where the plain-MWCC base objects live.")
    parser.add_argument("--output", default="objdiff.json")
    parser.add_argument("--make-args", default="rebuild-link", help="Make target objdiff runs to rebuild.")
    parser.add_argument("--include-library", action="store_true", help="Also report crt0 and the SDK blobs, which are never decompiled.")
    args = parser.parse_args()

    base_dir = Path(__file__).resolve().parents[2]
    yaml_path = base_dir / args.splat_yaml_path
    with open(yaml_path) as handle:
        config = yaml.safe_load(handle)

    options = load_options(config)
    yaml_base = os.path.normpath(os.path.join(os.path.dirname(yaml_path), options.get("base_path", ".")))
    src_path = Path(resolve(yaml_base, options, "src_path", "src"))

    subsegments = collect_code_subsegments(config)
    if not subsegments:
        sys.exit(f"No code subsegments found in {yaml_path}")

    if not (base_dir / args.target_dir).is_dir():
        sys.exit(
            f"No target objects in {args.target_dir}. Run a build first "
            "(make rebuild-link, or at least make merge-objects)."
        )

    units = []
    skipped = 0
    missing = []
    missing_bases = []
    for name, kind in subsegments:
        if not args.include_library and name in DEFAULT_EXCLUDES:
            skipped += 1
            continue

        target_path = f"{args.target_dir}/{name}.o"
        if not (base_dir / target_path).is_file():
            missing.append(name)
            continue

        unit = {
            "name": name,
            "target_path": target_path,
            "metadata": {
                "complete": kind == "c",
                "progress_categories": [categorize(name)],
            },
        }
        if (src_path / f"{name}.c").is_file():
            base_path = f"{args.base_dir}/{name}.o"
            if (base_dir / base_path).is_file():
                unit["base_path"] = base_path
            else:
                missing_bases.append(name)
        units.append(unit)

    used = {c for u in units for c in u["metadata"]["progress_categories"]}
    categories = [
        {"id": identifier, "name": label}
        for _, identifier, label in CATEGORY_RULES
        if identifier in used
    ]
    if FALLBACK_CATEGORY[0] in used:
        categories.append({"id": FALLBACK_CATEGORY[0], "name": FALLBACK_CATEGORY[1]})

    objdiff_config = {
        "$schema": "https://raw.githubusercontent.com/encounter/objdiff/main/config.schema.json",
        "custom_make": "make",
        "custom_args": args.make_args.split(),
        "build_target": False,
        "build_base": True,
        "watch_patterns": ["*.c", "*.h", "*.s", "*.inc", "*.yaml", "*.txt", "*.lcf"],
        "progress_categories": categories,
        "units": units,
    }

    output_path = base_dir / args.output
    with open(output_path, "w") as handle:
        json.dump(objdiff_config, handle, indent=2)
        handle.write("\n")

    with_c = sum(1 for u in units if "base_path" in u)
    complete = sum(1 for u in units if u["metadata"]["complete"])
    print(f"Wrote {output_path}")
    print(f"  {len(units)} units: {complete} fully migrated, {with_c - complete} partially decompiled, {len(units) - with_c} untouched")
    if skipped:
        print(f"  {skipped} library units excluded (pass --include-library to report them)")
    if missing_bases:
        print(f"  NOTE: {len(missing_bases)} unit(s) have a .c but no compiled base object;")
        print(f"        run `make objdiff-base`. First few: {missing_bases[:5]}")
    if missing:
        print(f"  WARNING: {len(missing)} unit(s) had no target object and are absent from the report,")
        print(f"           which understates the total. Rebuild to fix. First few: {missing[:5]}")


if __name__ == "__main__":
    main()
