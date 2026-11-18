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

# 1) Run2_stzct_ElElEl/Automation_ClaApl_central
run_bin_tasks "Run2_st1zct_ElElEl/Automation_ClaApl_central"

# 2) Run2_stzct_ElMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_st1zct_ElMuMu/Automation_ClaApl_central"

# 3) Run2_stzct_MuElEl/Automation_ClaApl_central
run_bin_tasks "Run2_st1zct_MuElEl/Automation_ClaApl_central"

# 4) Run2_stzct_MuMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_st1zct_MuMuMu/Automation_ClaApl_central"

# 5) Run2_stzut_ElElEl/Automation_ClaApl_central
run_bin_tasks "Run2_st1zut_ElElEl/Automation_ClaApl_central"

# 6) Run2_stzut_ElMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_st1zut_ElMuMu/Automation_ClaApl_central"

# 7) Run2_stzut_MuElEl/Automation_ClaApl_central
run_bin_tasks "Run2_st1zut_MuElEl/Automation_ClaApl_central"

# 8) Run2_stzut_MuMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_st1zut_MuMuMu/Automation_ClaApl_central"



# 1) Run2_stzct_ElElEl/Automation_ClaApl_central
run_bin_tasks "Run2_st2zct_ElElEl/Automation_ClaApl_central"

# 2) Run2_stzct_ElMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_st2zct_ElMuMu/Automation_ClaApl_central"

# 3) Run2_stzct_MuElEl/Automation_ClaApl_central
run_bin_tasks "Run2_st2zct_MuElEl/Automation_ClaApl_central"

# 4) Run2_stzct_MuMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_st2zct_MuMuMu/Automation_ClaApl_central"

# 5) Run2_stzut_ElElEl/Automation_ClaApl_central
run_bin_tasks "Run2_st2zut_ElElEl/Automation_ClaApl_central"

# 6) Run2_stzut_ElMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_st2zut_ElMuMu/Automation_ClaApl_central"

# 7) Run2_stzut_MuElEl/Automation_ClaApl_central
run_bin_tasks "Run2_st2zut_MuElEl/Automation_ClaApl_central"

# 8) Run2_stzut_MuMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_st2zut_MuMuMu/Automation_ClaApl_central"



# 9) Run2_ttzct_ElElEl/Automation_ClaApl_central
run_bin_tasks "Run2_ttzct_ElElEl/Automation_ClaApl_central"

# 10) Run2_ttzct_ElMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_ttzct_ElMuMu/Automation_ClaApl_central"

# 11) Run2_ttzct_MuElEl/Automation_ClaApl_central
run_bin_tasks "Run2_ttzct_MuElEl/Automation_ClaApl_central"

# 12) Run2_ttzct_MuMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_ttzct_MuMuMu/Automation_ClaApl_central"

# 13) Run2_ttzut_ElElEl/Automation_ClaApl_central
run_bin_tasks "Run2_ttzut_ElElEl/Automation_ClaApl_central"

# 14) Run2_ttzut_ElMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_ttzut_ElMuMu/Automation_ClaApl_central"

# 15) Run2_ttzut_MuElEl/Automation_ClaApl_central
run_bin_tasks "Run2_ttzut_MuElEl/Automation_ClaApl_central"

# 16) Run2_ttzut_MuMuMu/Automation_ClaApl_central
run_bin_tasks "Run2_ttzut_MuMuMu/Automation_ClaApl_central"

# Task Completion Message
echo "All Nonprompt bin scripts ran successfully."
