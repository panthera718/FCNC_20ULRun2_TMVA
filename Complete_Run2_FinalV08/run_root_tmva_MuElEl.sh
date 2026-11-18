#!/bin/bash

dirs=(
    "Run2_ttzut_MuElEl"
    "Run2_ttzct_MuElEl"
    "Run2_st1zut_MuElEl"
    "Run2_st1zct_MuElEl"
    "Run2_st2zut_MuElEl"
    "Run2_st2zct_MuElEl"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

