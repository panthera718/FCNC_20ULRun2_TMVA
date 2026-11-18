#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import glob
import subprocess

# Process name for 2nd directory (lowercase) -> Process name for 3rd directory (uppercase)
proc_map = {
    'ttzct': 'TTzct',
    'ttzut': 'TTzut',
}

# Year tag by completion directory
year_dirs = [
    '2016APVpreVFP',
    '2016postVFP',
    '2017',
    '2018',
]

def main():
    base = os.getcwd()

    for year_dir in year_dirs:
        # Example: '2016APVpreVFP' -> year_tag = '20UL16APVpreVFP'
        year_tag = '20UL' + year_dir[2:]
        complete_dir = os.path.join(base, f'../Complete_{year_dir}')

        for proc_lower, proc_cap in proc_map.items():
            # glob pattern: ../Complete_{year_dir}/Run2_{proc_lower}_*/{proc_cap}_{year_tag}_*/*_data.root
            pattern = os.path.join(
                complete_dir,
                f'Run2_{proc_lower}_*',
                f'{proc_cap}_{year_tag}_*',
                '*_data.root'
            )
            files = glob.glob(pattern)
            if not files:
                continue

            files.sort()

            output_name = f'{proc_cap}_{year_tag}_Tau_data_obs.root'
            cmd = ['hadd', output_name] + files
##            print('Running:', ' '.join(cmd))
            try:
                subprocess.run(cmd, check=True)
            except subprocess.CalledProcessError as e:
                print(f'[Error] hadd failed for {output_name}:', e)

if __name__ == '__main__':
    main()
