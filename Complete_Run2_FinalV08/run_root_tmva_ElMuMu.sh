#!/bin/bash

dirs=(
    "Run2_ttzut_ElMuMu"
    "Run2_ttzct_ElMuMu"
    "Run2_st1zut_ElMuMu"
    "Run2_st1zct_ElMuMu"
    "Run2_st2zut_ElMuMu"
    "Run2_st2zct_ElMuMu"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

