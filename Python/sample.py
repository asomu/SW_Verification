#%%
#분류:
#난이도 **
import os
from glob import glob
LOCATION_OF_TESTCASE = "testcase01"


cwd = os.getcwd().split(os.path.sep)
cwd[-1] = LOCATION_OF_TESTCASE
cwd = os.path.sep.join(cwd)
file_name = os.path.abspath( __file__ ).split(os.path.sep)[-1].split('.')[0]
input_dir = os.path.join(cwd, file_name)
if os.path.isdir(input_dir):
    input_file_list = glob(input_dir + "\\in_*")
else:
    input_file_list = []

with  open(input_file_list[0], 'r') as r:
    N = int(r.readline())
    A = [ r.readline().rstrip('\n') for i in range(N) ]




# %%
