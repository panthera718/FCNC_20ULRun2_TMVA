#!/bin/bash

dirs=(
    "Run2_ttzut_TaElEl_01"
    "Run2_ttzut_TaElEl_02"
    "Run2_ttzut_TaElEl_03"
    "Run2_ttzut_TaElEl_04"
    "Run2_ttzut_TaElEl_05"
    "Run2_ttzut_TaMuMu_01"
    "Run2_ttzut_TaMuMu_02"
    "Run2_ttzut_TaMuMu_03"
    "Run2_ttzut_TaMuMu_04"
    "Run2_ttzut_TaMuMu_05"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

