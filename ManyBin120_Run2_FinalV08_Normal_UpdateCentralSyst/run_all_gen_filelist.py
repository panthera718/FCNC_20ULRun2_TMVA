#!/usr/bin/env python3
import subprocess
from pathlib import Path
import glob
import sys

def run_gen_filelist(target_dir: Path):
    script = target_dir / "gen_filelist.py"
    if not target_dir.is_dir():
        print(f"[SKIP] Not a directory: {target_dir}")
        return
    if not script.is_file():
        print(f"[WARN] gen_filelist.py not found in: {target_dir}")
        return

    print(f"[RUN ] python3 gen_filelist.py  (cwd={target_dir})")
    try:
        result = subprocess.run(
            ["python3", "gen_filelist.py"],
            cwd=str(target_dir),
            capture_output=True,
            text=True,
            check=False,
        )
        if result.stdout:
            print(result.stdout.rstrip())
        if result.stderr:
            print(result.stderr.rstrip(), file=sys.stderr)

        if result.returncode == 0:
            print(f"[OK  ] Finished: {target_dir}")
        else:
            print(f"[FAIL] Return code {result.returncode}: {target_dir}")
    except KeyboardInterrupt:
        raise
    except Exception as e:
        print(f"[ERROR] {target_dir}: {e}")

def main():
    pattern = "*Complete_201*/Run2_*t_*/Automation_ClaApl*/filelist/"
    matches = [Path(p).resolve() for p in glob.glob(pattern)]
    if not matches:
        print(f"[INFO] No directories matched pattern: {pattern}")
        return

    print(f"[INFO] Found {len(matches)} directories.")
    for d in sorted(matches):
        run_gen_filelist(d)

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n[INFO] Interrupted by user.", file=sys.stderr)
