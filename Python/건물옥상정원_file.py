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

def solve(A):
    cnt = 0
    my_stack = []
    for item in A:
        if not my_stack:
            my_stack.append(item)
        else:
            while my_stack:
                com = my_stack.pop()
                if item < com:
                    my_stack.append(com)
                    cnt += len(my_stack)
                    my_stack.append(item)
                    break
                else:
                    pass
            else:
                my_stack.append(item)
    return cnt

sol = []

for file in input_file_list:
    with  open(file, 'r') as r:
        N = int(r.readline())
        A = []
        for i in range(N):
            A.append(int(r.readline().strip("\n")))
        ans = solve(A)
        sol.append(ans)

for i, ret in enumerate(sol):
    print(i, ret)
# %%
