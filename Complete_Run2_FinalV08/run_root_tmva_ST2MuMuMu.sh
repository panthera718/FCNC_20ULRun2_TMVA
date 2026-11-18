#!/bin/bash

dirs=(
    "Run2_st2zut_MuMuMu_01"
    "Run2_st2zut_MuMuMu_02"
    "Run2_st2zut_MuMuMu_03"
    "Run2_st2zut_MuMuMu_04"
    "Run2_st2zut_MuMuMu_05"
    "Run2_st2zct_MuMuMu_01"
    "Run2_st2zct_MuMuMu_02"
    "Run2_st2zct_MuMuMu_03"
    "Run2_st2zct_MuMuMu_04"
    "Run2_st2zct_MuMuMu_05"
)

for d in "${dirs[@]}"; do
    echo ">>> Entering directory: $d"
    cd "$d" || { echo "Failed to enter directory $d"; exit 1; }
    
    root -l -q TMVAClassification_FCNC.C
    
    cd ..
    echo "<<< Returning to parent directory"
    echo
done

