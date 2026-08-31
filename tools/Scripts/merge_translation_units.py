"""Build one object per translation unit from Splat's per-section output.

"""

import argparse
import os
import shutil
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

import yaml

# Suffixes Splat gives the per-section files that belong to a text subsegment.
SECTION_SUFFIXES = (
    ".data",
    ".rodata",
    ".sdata",
    ".sbss",
    ".bss",
    ".lit4",
    ".lit8",
    ".gcc_except_table",
)


def strip_section_suffix(stem: str) -> str:
    for suffix in SECTION_SUFFIXES:
        if stem.endswith(suffix):
            return stem[: -len(suffix)]
    return stem


def load_c_units(splat_yaml_path):
    """Names of the subsegments the splat config says are built from C."""
    if not splat_yaml_path:
        return None
    with open(splat_yaml_path) as handle:
        config = yaml.safe_load(handle) or {}
    names = set()
    for segment in config.get("segments", []):
        if not isinstance(segment, dict):
            continue
        for entry in segment.get("subsegments", []):
            if isinstance(entry, list) and len(entry) >= 3 and entry[1] == "c":
                names.add(str(entry[2]))
    return names


def collect_units(asm_dir: Path, src_dir: Path, c_units):
    """Map each translation unit to its assembly parts, text first."""
    data_dir = asm_dir / "data"
    units = defaultdict(lambda: {"text": None, "disasm_text": None, "sections": []})

    for source in sorted(asm_dir.rglob("*.s")):
        if "nonmatchings" in source.parts:
            continue

        if data_dir in source.parents:
            relative = source.relative_to(data_dir)
            unit = str(relative.with_name(strip_section_suffix(relative.stem)))
            units[unit]["sections"].append(source)
        else:
            relative = source.relative_to(asm_dir)
            unit = str(relative.with_suffix(""))
            units[unit]["disasm_text"] = source
            if unit not in c_units:
                units[unit]["text"] = source

    for source in sorted(src_dir.rglob("*.c")):
        unit = str(source.relative_to(src_dir).with_suffix(""))
        if unit in c_units:
            units[unit]

    return units


def run(command):
    result = subprocess.run(command, capture_output=True, text=True)
    if result.returncode != 0:
        sys.stderr.write(result.stdout + result.stderr)
        sys.exit(f"Command failed: {' '.join(str(c) for c in command)}")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--asm-dir", required=True, help="Splat asm output directory.")
    parser.add_argument("--src-dir", required=True, help="C source directory.")
    parser.add_argument("--c-obj-dir", required=True, help="Where compiled C objects were written.")
    parser.add_argument("--out-dir", required=True, help="Where to write the per-unit objects.")
    parser.add_argument("--as-path", required=True, help="Path to the assembler.")
    parser.add_argument("--as-flags", default="", help="Flags to pass to the assembler.")
    parser.add_argument("--ld", required=True, help="Path to a MIPS-aware ld.")
    parser.add_argument("--work-dir", required=True, help="Scratch directory for concatenated sources.")
    parser.add_argument("--splat-yaml-path", required=True, help="Splat config, which decides who links from C.")
    parser.add_argument("--target-out-dir", help="Also build an objdiff target object per unit, always from the original's disassembly.")
    args = parser.parse_args()

    asm_dir = Path(args.asm_dir).resolve()
    src_dir = Path(args.src_dir).resolve()
    c_obj_dir = Path(args.c_obj_dir).resolve()
    out_dir = Path(args.out_dir).resolve()
    work_dir = Path(args.work_dir).resolve()
    as_flags = args.as_flags.split()

    if not asm_dir.is_dir():
        sys.exit(f"Assembly directory not found: {asm_dir}")

    for directory in (out_dir, work_dir):
        if directory.exists():
            shutil.rmtree(directory)

    c_units = load_c_units(args.splat_yaml_path)
    units = collect_units(asm_dir, src_dir, c_units)

    assembled = 0
    combined = 0
    for unit, parts in sorted(units.items()):
        destination = out_dir / f"{unit}.o"
        destination.parent.mkdir(parents=True, exist_ok=True)

        c_object = c_obj_dir / f"{unit}.o" if unit in c_units else None
        sources = ([parts["text"]] if parts["text"] else []) + parts["sections"]

        if c_object is not None and c_object.is_file():
            # Compiled translation unit: combine it with any assembly siblings.
            if not parts["sections"]:
                shutil.copy2(c_object, destination)
                combined += 1
                continue

            sections_object = work_dir / f"{unit}.sections.o"
            sections_object.parent.mkdir(parents=True, exist_ok=True)
            concatenated = work_dir / f"{unit}.sections.s"
            concatenated.write_text("".join(p.read_text() for p in parts["sections"]))
            run([args.as_path, *as_flags, "-o", str(sections_object), str(concatenated)])
            run([args.ld, "-EL", "-r", "-o", str(destination), str(c_object), str(sections_object)])
            combined += 1
            continue

        if not sources:
            continue

        # Assembly-only translation unit: one assembler invocation over all of
        # its parts, so references to file statics bind to the local definition.
        concatenated = work_dir / f"{unit}.s"
        concatenated.parent.mkdir(parents=True, exist_ok=True)
        concatenated.write_text("".join(p.read_text() for p in sources))
        run([args.as_path, *as_flags, "-o", str(destination), str(concatenated)])
        assembled += 1

    print(f"Assembled {assembled} unit(s) from concatenated sources, combined {combined} compiled unit(s)")
    print(f"Link objects written to {out_dir}")

    if not args.target_out_dir:
        return

    target_dir = Path(args.target_out_dir).resolve()
    if target_dir.exists():
        shutil.rmtree(target_dir)

    targets = 0
    for unit, parts in sorted(units.items()):
        sources = ([parts["disasm_text"]] if parts["disasm_text"] else []) + parts["sections"]
        if not sources:
            continue

        destination = target_dir / f"{unit}.o"
        destination.parent.mkdir(parents=True, exist_ok=True)
        concatenated = work_dir / f"{unit}.target.s"
        concatenated.parent.mkdir(parents=True, exist_ok=True)
        concatenated.write_text("".join(p.read_text() for p in sources))
        run([args.as_path, *as_flags, "-o", str(destination), str(concatenated)])
        targets += 1

    print(f"Built {targets} objdiff target object(s) in {target_dir}")


if __name__ == "__main__":
    main()
