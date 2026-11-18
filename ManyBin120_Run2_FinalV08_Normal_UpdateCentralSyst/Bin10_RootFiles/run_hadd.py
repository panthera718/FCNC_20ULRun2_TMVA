#!/usr/bin/env python3
import subprocess

# List of eras and processes to combine
eras = [
    "20UL16APVpreVFP",
    "20UL16postVFP",
    "20UL17",
    "20UL18"
]

processes = [
    "ST1zct",
    "ST1zut",
    "ST2zct",
    "ST2zut",
    "TTzct",
    "TTzut"
]

# Loop over each combination and run the hadd command
for era in eras:
    for proc in processes:
        output_file = f"{proc}_{era}_All_nbin10.root"
        input_pattern_el = f"{proc}_{era}_El*.root"
        input_pattern_mu = f"{proc}_{era}_Mu*.root"
        cmd = f"hadd {output_file} {input_pattern_el} {input_pattern_mu}"
        
        print(f"[INFO] Running: {cmd}")
        try:
            subprocess.run(cmd, shell=True, check=True)
            print(f"[OK] Created {output_file}")
        except subprocess.CalledProcessError as e:
            print(f"[ERROR] Command failed for {proc} {era}: {e}")
