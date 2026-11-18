#!/usr/bin/env bash

run_bin_tasks() {
  local target_dir="$1"
  cd "$target_dir" || exit

#  # bin120
#  python3 gen_histo_100_Nonprompt_bin120.py
#  mv *.root rootfiles_Nonprompt_bin120

  # bin15
  python3 gen_histo_100_Nonprompt_bin15.py
  mv *.root rootfiles_Nonprompt_bin15

  # bin10
  python3 gen_histo_100_Nonprompt_bin10.py
  mv *.root rootfiles_Nonprompt_bin10

  # bin5
  python3 gen_histo_100_Nonprompt_bin5.py
  mv *.root rootfiles_Nonprompt_bin5

  cd - > /dev/null 2>&1
}

# 9) Run2_ttzct_ElElEl/Automation_ClaApl_central
run_bin_tasks "Run2_ttzct_ElTaTa/Automation_ClaApl_central"

# 10) Run2_ttzct_ElMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_ttzct_MuTaTa/Automation_ClaApl_central"

# 11) Run2_ttzct_MuElEl/Automation_ClaApl_central
run_bin_tasks "Run2_ttzct_TaElEl/Automation_ClaApl_central"

# 12) Run2_ttzct_MuMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_ttzct_TaMuMu/Automation_ClaApl_central"

# 13) Run2_ttzut_ElElEl/Automation_ClaApl_central
run_bin_tasks "Run2_ttzut_ElTaTa/Automation_ClaApl_central"

# 14) Run2_ttzut_ElMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_ttzut_MuTaTa/Automation_ClaApl_central"

# 15) Run2_ttzut_MuElEl/Automation_ClaApl_central
run_bin_tasks "Run2_ttzut_TaElEl/Automation_ClaApl_central"

# 16) Run2_ttzut_MuMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_ttzut_TaMuMu/Automation_ClaApl_central"

# Task Completion Message
echo "All Nonprompt bin scripts ran successfully."
