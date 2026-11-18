#!/bin/bash

dirs=(
    "Run2_st2zut_ElMuMu_01"
    "Run2_st2zut_ElMuMu_02"
    "Run2_st2zut_ElMuMu_03"
    "Run2_st2zut_ElMuMu_04"
    "Run2_st2zut_ElMuMu_05"
    "Run2_st2zct_ElMuMu_01"
    "Run2_st2zct_ElMuMu_02"
    "Run2_st2zct_ElMuMu_03"
    "Run2_st2zct_ElMuMu_04"
    "Run2_st2zct_ElMuMu_05"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

