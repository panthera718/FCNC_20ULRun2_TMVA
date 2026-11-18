#!/usr/bin/env bash

TOP_DIRS=(
    "Run2_ttzut_MuMuMu"
    "Run2_ttzct_MuMuMu"
    "Run2_st1zut_MuMuMu"
    "Run2_st1zct_MuMuMu"
    "Run2_st2zut_MuMuMu"
    "Run2_st2zct_MuMuMu"
)

SUB_DIRS=(
    "Automation_ClaApl_central"
    "Automation_ClaApl_jerDown"
    "Automation_ClaApl_jerUp"
    "Automation_ClaApl_jetVar01"
    "Automation_ClaApl_jetVar02"
    "Automation_ClaApl_jetVar03"
    "Automation_ClaApl_jetVar04"
    "Automation_ClaApl_jetVar05"
    "Automation_ClaApl_jetVar06"
    "Automation_ClaApl_jetVar07"
    "Automation_ClaApl_jetVar08"
    "Automation_ClaApl_jetVar09"
)

for top_dir in "${TOP_DIRS[@]}"; do
    echo "==== Processing $top_dir ===="
    cd "$top_dir" || { echo "Cannot cd to $top_dir"; exit 1; }

    for sub_dir in "${SUB_DIRS[@]}"; do
        echo "---- Sub directory: $sub_dir ----"
        cd "$sub_dir" || { echo "Cannot cd to $sub_dir"; exit 1; }

        python3 gen_histo_100.py
        mv *.root rootfiles/.

        cd ..
    done

    cd ..
done

