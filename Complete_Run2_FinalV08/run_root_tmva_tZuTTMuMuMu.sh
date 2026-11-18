#!/bin/bash

dirs=(
    "Run2_ttzut_MuMuMu_01"
    "Run2_ttzut_MuMuMu_02"
    "Run2_ttzut_MuMuMu_03"
    "Run2_ttzut_MuMuMu_04"
    "Run2_ttzut_MuMuMu_05"
    "Run2_ttzut_MuMuMu_06"
    "Run2_ttzut_MuMuMu_07"
    "Run2_ttzut_MuMuMu_08"
    "Run2_ttzut_MuMuMu_09"
    "Run2_ttzut_MuMuMu_10"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

