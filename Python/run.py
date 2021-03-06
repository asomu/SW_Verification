#%%
import subprocess
import os
from glob import glob


#--------실행파일---------#
RUN_FILE_NAME="무인열차"

#----testcase 폴더번호입력-----#
LOCATION_OF_TESTCASE = "testcase01"

#----테스트하고 싶은 input.txt 번호입력-----#
RUN_MODE = { "ALL":True , "EACH":False}
CURRENT_MODE = RUN_MODE["ALL"]
INPUT_NUM = 2


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
     if CURRENT_MODE:
          for idx, input_file in enumerate(input_file_list):
               ret = run_test_case(input_file)
               pass_fail = check_pass_fail(idx, ret, output_file_list)
               print(pass_fail)
     else:
          ret = run_test_case(input_file_list[INPUT_NUM-1])
          pass_fail = check_pass_fail(INPUT_NUM-1, ret, output_file_list)
          print(f"결과값 {ret} 판정: {pass_fail}")
     
# %%

# %%
