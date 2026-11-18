#!/bin/bash

dirs=(
    "Run2_st1zut_MuElEl_01"
    "Run2_st1zut_MuElEl_02"
    "Run2_st1zut_MuElEl_03"
    "Run2_st1zut_MuElEl_04"
    "Run2_st1zut_MuElEl_05"
    "Run2_st1zct_MuElEl_01"
    "Run2_st1zct_MuElEl_02"
    "Run2_st1zct_MuElEl_03"
    "Run2_st1zct_MuElEl_04"
    "Run2_st1zct_MuElEl_05"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

