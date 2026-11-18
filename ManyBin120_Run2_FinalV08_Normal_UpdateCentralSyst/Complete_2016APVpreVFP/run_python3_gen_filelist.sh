#!/bin/bash

for d in Run2_*t_*/Automation_ClaApl*/filelist/; do
  cd "$d" || exit
  
  cp ../gen_filelist.py .
  python3 gen_filelist.py
  
  cd - >/dev/null || exit
done
