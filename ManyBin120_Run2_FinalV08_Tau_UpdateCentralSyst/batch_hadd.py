#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os, glob, subprocess

# 2nd step directory name (lowercase) -> 3rd step directory name (uppercase) mapping
proc_map = {
    'ttzct': 'TTzct',
    'ttzut': 'TTzut',
}

#Channel List
channels = ['ElTaTa', 'MuTaTa', 'TaElEl', 'TaMuMu']

def main():
    base_dir = os.getcwd()

    for first in os.listdir(base_dir):
        if not first.startswith('Complete_'):
            continue
        first_path = os.path.join(base_dir, first)
        if not os.path.isdir(first_path):
            continue

        # first = 'Complete_2016APVpreVFP' -> year_str='2016APVpreVFP'
        year_str = first.split('_', 1)[1]
        # year_tag = '20UL' + '16APVpreVFP' -> '20UL16APVpreVFP'
        year_tag = '20UL' + year_str[2:]

        for proc_lower, proc_cap in proc_map.items():
            for ch in channels:
                # 2nd level directory: Run2_{proc_lower}_{ch}
                second = f"Run2_{proc_lower}_{ch}"
                second_path = os.path.join(first_path, second)
                if not os.path.isdir(second_path):
                    continue

                # 3-step directory name
                third = f"{proc_cap}_{year_tag}_{ch}"

                # glob only the second_path/third/*.root files
                pattern = os.path.join(second_path, third, "*.root")
                root_files = glob.glob(pattern)
                if not root_files:
                    continue

                root_files.sort()

                # Create the output file in second_path and name it {third}.root
                output_root = os.path.join(second_path, f"{third}.root")

                cmd = ["hadd", output_root] + root_files
##                print(f"Running: {' '.join(cmd)}")
                try:
                    subprocess.run(cmd, check=True)
                except subprocess.CalledProcessError as e:
                    print(f"[Error] hadd failed in {second_path}: {e}")

if __name__ == "__main__":
    main()
