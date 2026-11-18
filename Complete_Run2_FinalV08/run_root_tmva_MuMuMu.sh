#!/bin/bash

dirs=(
    "Run2_ttzut_MuMuMu"
    "Run2_ttzct_MuMuMu"
    "Run2_st1zut_MuMuMu"
    "Run2_st1zct_MuMuMu"
    "Run2_st2zut_MuMuMu"
    "Run2_st2zct_MuMuMu"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

