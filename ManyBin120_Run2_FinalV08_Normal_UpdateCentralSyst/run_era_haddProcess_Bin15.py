#!/usr/bin/env python3
import os
import subprocess
import glob

def main():
    # Start directory (where to run this script)
    start_dir = os.getcwd()

    # (era_dir_suffix, file_name_tag)
    eras = [
        ("2018",        "20UL18"),
        ("2017",        "20UL17"),
        ("2016postVFP", "20UL16postVFP"),
        ("2016APVpreVFP","20UL16APVpreVFP"),
    ]
    # (process_dir_suffix, file_name_prefix)
    procs = [
        ("st1zct", "ST1zct"),
        ("st1zut", "ST1zut"),
        ("st2zct", "ST2zct"),
        ("st2zut", "ST2zut"),
        ("ttzct", "TTzct"),
        ("ttzut", "TTzut"),
    ]

    for era_suffix, era_tag in eras:
        era_dir = f"Complete_{era_suffix}"
        for proc_suffix, proc_tag in procs:
            run2_dir = os.path.join(start_dir, era_dir, f"Run2_{proc_suffix}")
            if not os.path.isdir(run2_dir):
                print(f"[WARNING] No directory: {run2_dir}")
                continue

            # Go to the subdirectory
            os.chdir(run2_dir)
            print(f"\n==> Working directory: {os.getcwd()}")

            # 1) cp ../../Bin15_RootFiles/... -> .
            src_pattern = os.path.join(
                start_dir,
                "Bin15_RootFiles",
                f"{proc_tag}_{era_tag}_All_nbin15*.root"
            )
            src_files = glob.glob(src_pattern)
            if not src_files:
                print(f"[WARNING] No files to copy: {src_pattern}")
            else:
                cmd_cp = ["cp"] + src_files + ["."]
                print("COPY:", " ".join(cmd_cp))
                subprocess.run(cmd_cp, check=True)

            # 2) hadd Base.root input.root ../Run2_proc_*/.../*.root
            input_root = f"{proc_tag}_{era_tag}_All_nbin15.root"
            base_root  = f"{proc_tag}_{era_tag}_All_nbin15_Base.root"
            hadd_pattern = os.path.join(
                "..",
                f"Run2_{proc_suffix}_*",
                "Automation_ClaApl_central",
                "rootfiles_Nonprompt_bin15",
                "*.root"
            )
            hadd_inputs = " ".join([input_root, hadd_pattern])
            cmd_hadd = f"hadd {base_root} {hadd_inputs}"
            print("HADD:", cmd_hadd)
            subprocess.run(cmd_hadd, shell=True, check=True)

            # Return to original position
            os.chdir(start_dir)

if __name__ == "__main__":
    main()
