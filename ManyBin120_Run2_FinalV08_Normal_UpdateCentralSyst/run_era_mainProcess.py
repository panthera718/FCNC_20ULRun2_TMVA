#!/usr/bin/env python3
import os
import subprocess

# List of ERA and PROCESS directories
eras = [
    "Complete_2016APVpreVFP",
    "Complete_2016postVFP",
    "Complete_2017",
    "Complete_2018"
]

processes = [
    "Run2_st1zct",
    "Run2_st1zut",
    "Run2_st2zct",
    "Run2_st2zut",
    "Run2_ttzct",
    "Run2_ttzut"
]

# Iterate over each combination of ERA and PROCESS
for era in eras:
    for proc in processes:
        dir_path = os.path.join(era, proc)
        if not os.path.isdir(dir_path):
            print(f"[WARNING] Directory '{dir_path}' not found, skipping.")
            continue

        print(f"[INFO] Entering directory: {dir_path}")
        try:
            # Run modify_histograms.py
            subprocess.run(
                ["python3", "modify_histograms.py"],
                cwd=dir_path,
                check=True
            )
            print(f"[INFO] Ran modify_histograms.py successfully in {dir_path}")

            # Run create_analysis_rootfile.py
            subprocess.run(
                ["python3", "create_analysis_rootfile.py"],
                cwd=dir_path,
                check=True
            )
            print(f"[INFO] Ran create_analysis_rootfile.py successfully in {dir_path}")

        except subprocess.CalledProcessError as e:
            print(f"[ERROR] A command failed in '{dir_path}': {e}")

