#!/bin/bash

dirs=(
    "Run2_ttzut_ElTaTa_01"
    "Run2_ttzut_ElTaTa_02"
    "Run2_ttzut_ElTaTa_03"
    "Run2_ttzut_ElTaTa_04"
    "Run2_ttzut_ElTaTa_05"
    "Run2_ttzut_MuTaTa_01"
    "Run2_ttzut_MuTaTa_02"
    "Run2_ttzut_MuTaTa_03"
    "Run2_ttzut_MuTaTa_04"
    "Run2_ttzut_MuTaTa_05"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

