#!/bin/bash

dirs=(
    "Run2_st2zut_ElElEl_01"
    "Run2_st2zut_ElElEl_02"
    "Run2_st2zut_ElElEl_03"
    "Run2_st2zut_ElElEl_04"
    "Run2_st2zut_ElElEl_05"
    "Run2_st2zct_ElElEl_01"
    "Run2_st2zct_ElElEl_02"
    "Run2_st2zct_ElElEl_03"
    "Run2_st2zct_ElElEl_04"
    "Run2_st2zct_ElElEl_05"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

