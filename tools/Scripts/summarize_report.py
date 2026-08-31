"""Print a short summary of an objdiff progress report."""

import json
import sys


def main():
    if len(sys.argv) != 2:
        sys.exit("Usage: summarize_report.py <report.json>")

    with open(sys.argv[1]) as handle:
        report = json.load(handle)

    measures = report.get("measures", {})

    def number(key):
        value = measures.get(key, 0)
        return int(value) if isinstance(value, str) else value

    total_code = number("total_code")
    matched_code = number("matched_code")

    print()
    print(f"  Code      {matched_code:>9,} / {total_code:<9,} bytes   {measures.get('matched_code_percent', 0):6.2f}%")
    print(f"  Functions {number('matched_functions'):>9,} / {number('total_functions'):<9,}         {measures.get('matched_functions_percent', 0):6.2f}%")
    print(f"  Units     {number('complete_units'):>9,} / {number('total_units'):<9,}")
    print()

    categories = report.get("categories", [])
    if categories:
        print("  By category:")
        for category in categories:
            category_measures = category.get("measures", {})
            matched = category_measures.get("matched_code", 0)
            total = category_measures.get("total_code", 0)
            matched = int(matched) if isinstance(matched, str) else matched
            total = int(total) if isinstance(total, str) else total
            percent = category_measures.get("matched_code_percent") or 0.0
            print(f"    {category['name']:<20s} {matched:>9,} / {total:<9,} bytes   {percent:6.2f}%")
        print()

    units = report.get("units", [])
    started = [u for u in units if u.get("measures", {}).get("matched_code_percent", 0) > 0]
    if not started:
        return

    print("  Units with decompiled code:")
    for unit in sorted(started, key=lambda u: -u["measures"].get("matched_code_percent", 0)):
        unit_measures = unit.get("measures", {})
        percent = unit_measures.get("matched_code_percent", 0)
        matched = unit_measures.get("matched_functions", 0)
        total = unit_measures.get("total_functions", 0)
        # "complete" means it most be from C code and linking
        if unit.get("metadata", {}).get("complete"):
            state = "linked from C"
        elif percent == 100:
            state = "ready to flip to `c`"
        else:
            state = "in progress"
        print(f"    {unit['name']:<40s} {percent:6.2f}%  {matched:>3d}/{total:<3d} fns   {state}")
    print()


if __name__ == "__main__":
    main()
