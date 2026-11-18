#!/bin/bash

dirs=(
    "Run2_ttzut_ElElEl_01"
    "Run2_ttzut_ElElEl_02"
    "Run2_ttzut_ElElEl_03"
    "Run2_ttzut_ElElEl_04"
    "Run2_ttzut_ElElEl_05"
    "Run2_ttzut_ElElEl_06"
    "Run2_ttzut_ElElEl_07"
    "Run2_ttzut_ElElEl_08"
    "Run2_ttzut_ElElEl_09"
    "Run2_ttzut_ElElEl_10"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

