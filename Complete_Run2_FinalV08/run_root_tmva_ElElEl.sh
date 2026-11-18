#!/bin/bash

dirs=(
    "Run2_ttzut_ElElEl"
    "Run2_ttzct_ElElEl"
    "Run2_st1zut_ElElEl"
    "Run2_st1zct_ElElEl"
    "Run2_st2zut_ElElEl"
    "Run2_st2zct_ElElEl"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

