#!/bin/bash

dirs=(
    "Run2_ttzut_MuElEl_01"
    "Run2_ttzut_MuElEl_02"
    "Run2_ttzut_MuElEl_03"
    "Run2_ttzut_MuElEl_04"
    "Run2_ttzut_MuElEl_05"
    "Run2_ttzut_MuElEl_06"
    "Run2_ttzut_MuElEl_07"
    "Run2_ttzut_MuElEl_08"
    "Run2_ttzut_MuElEl_09"
    "Run2_ttzut_MuElEl_10"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

