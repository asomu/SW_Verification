#%%
#분류: Stack, Sliding Window.
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

# for file in input_file_list:
#     with open(file, 'r', encoding='uft-8') as f:
#         input =  f.read()
#         print(input)

with  open(input_file_list[0], 'r') as r:
    N = int(r.readline())
    H = []
    
    for i in range(N):
        H.append(int(r.readline()))

def solve():
    my_stack = []
    for i in range(N-1):
        if H[i] <= H[i+1]:

#solve()





#user_input = input()
#print ("Hello Goorm! Your input is " + user_input)




# %%
