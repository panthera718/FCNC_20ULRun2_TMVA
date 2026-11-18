#!/usr/bin/env python3
import os
import glob
import shutil
import argparse
from pathlib import Path

def main(overwrite=False, dry_run=False):
    # Collect all target directories matching the pattern
    target_dirs = sorted(glob.glob("Complete_201*/Run2_*t_*/*t_20UL1*/"))

    if not target_dirs:
        print("[!] No target directories matched the pattern: Complete_201*/Run2_*t_*/*t_20UL1*/")
        return

    copied_total = 0
    skipped_total = 0
    missing_src_total = 0

    for tdir in target_dirs:
        tdir_path = Path(tdir)
        if not tdir_path.is_dir():
            # Header lines with a colon (:) in the list output may not be directories, so they are skipped.
            continue

        # Relative path from target directory: ../Automation_ClaApl_*/rootfiles/*.root
        parent = tdir_path.parent
        src_glob = parent / "Automation_ClaApl_*" / "rootfiles" / "*.root"
        src_files = sorted(glob.glob(str(src_glob)))

        if not src_files:
            print(f"[!] No source .root files found for: {tdir_path}  (searched: {src_glob})")
            missing_src_total += 1
            continue

        print(f"[DIR] {tdir_path}  <-- copying from  {src_glob}")
        for src in src_files:
            src_path = Path(src)
            dst_path = tdir_path / src_path.name

            if dst_path.exists() and not overwrite:
                print(f"  [-] Skip (exists): {dst_path}")
                skipped_total += 1
                continue

            if dry_run:
                action = "Would copy" if not dst_path.exists() else "Would overwrite"
                print(f"  [DRY] {action}: {src_path}  ->  {dst_path}")
                continue

            # Actual copy
            shutil.copy2(src_path, dst_path)
            print(f"  [+] Copied: {src_path.name} -> {tdir_path}")
            copied_total += 1

    print("\n=== Summary ===")
    print(f"Targets visited     : {len([d for d in target_dirs if Path(d).is_dir()])}")
    print(f"Targets w/ no source: {missing_src_total}")
    print(f"Files copied        : {copied_total}")
    print(f"Files skipped       : {skipped_total}")
    if dry_run:
        print("(Dry-run mode: nothing actually copied)")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Copy ../Automation_ClaApl_*/rootfiles/*.root into each target directory.")
    parser.add_argument("--overwrite", action="store_true", help="Overwrite if destination file exists.")
    parser.add_argument("--dry-run", action="store_true", help="Show what would be done without copying.")
    args = parser.parse_args()
    main(overwrite=args.overwrite, dry_run=args.dry_run)
