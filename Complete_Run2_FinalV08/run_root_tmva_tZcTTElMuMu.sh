#!/bin/bash

dirs=(
    "Run2_ttzct_ElMuMu_01"
    "Run2_ttzct_ElMuMu_02"
    "Run2_ttzct_ElMuMu_03"
    "Run2_ttzct_ElMuMu_04"
    "Run2_ttzct_ElMuMu_05"
    "Run2_ttzct_ElMuMu_06"
    "Run2_ttzct_ElMuMu_07"
    "Run2_ttzct_ElMuMu_08"
    "Run2_ttzct_ElMuMu_09"
    "Run2_ttzct_ElMuMu_10"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

