#%%
import subprocess
import os
from glob import glob

RUN_FILE_NAME="디스플레이필터"

LOCATION_OF_TESTCASE = "testcase01"
name = f'{RUN_FILE_NAME}.py'
folder_name = name.split('.')[0]
cmd = ['python', name]

def get_input_file_names():
     cwd = os.getcwd().split(os.path.sep)
     cwd[-1] = LOCATION_OF_TESTCASE
     cwd = os.path.sep.join(cwd)
     file_name = os.path.abspath( folder_name ).split(os.path.sep)[-1].split('.')[0]
     input_dir = os.path.join(cwd, file_name)
     if os.path.isdir(input_dir):
          input_file_list = glob(input_dir + "\\in_*")
     else:
          input_file_list = []
     return input_file_list

def get_output_file_names():
     cwd = os.getcwd().split(os.path.sep)
     cwd[-1] = LOCATION_OF_TESTCASE
     cwd = os.path.sep.join(cwd)
     file_name = os.path.abspath( folder_name ).split(os.path.sep)[-1].split('.')[0]
     input_dir = os.path.join(cwd, file_name)
     if os.path.isdir(input_dir):
          output_file_list = glob(input_dir + "\\out_*")
     else:
          output_file_list = []
     return output_file_list

def run_test_case(input_file):
     with open(input_file,'r') as f:
          input = f.readlines()
          input_encode = "".join(input).encode()
          proc = subprocess.Popen(cmd, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
          proc.stdin.write(input_encode)
          ret,err = proc.communicate()
          return ret.strip().decode('utf-8')

def check_pass_fail(idx, ret, output_file_list):
     with open(output_file_list[idx],'r') as f:
          solve = f.readline()
          return "PASS" if solve.strip() == ret else "FAIL"


if __name__ == '__main__':
     input_file_list = get_input_file_names()
     output_file_list = get_output_file_names()
     for idx, input_file in enumerate(input_file_list):
          ret = run_test_case(input_file)
          pass_fail = check_pass_fail(idx, ret, output_file_list)
          print(pass_fail)
     
# %%

# %%
