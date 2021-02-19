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

with  open(input_file_list[0], 'r') as r:
        N = int(r.readline())
        R = []
        P = []
        for i in range(N):
            Number = r.readline().strip("\n").split()
            R.append(int(Number[0]))
            P.append(int(Number[1]))

min_diff = 10**1000
min_cnt = N

def dfs(num, mul, sum, cnt_filter):
    global min_diff
    global min_cnt
    if cnt_filter != 0:
        diff = abs(mul - sum)
        if min_diff > diff:
            min_diff = diff
            min_cnt = cnt_filter
        elif min_diff == diff and min_cnt > cnt_filter:
            min_cnt = cnt_filter
                
    if num >= N:
        return
    for i in range(num, N):
        dfs(i+1, mul*R[i], sum+P[i], cnt_filter + 1)


def solve():
    dfs(0, 1, 0, 0)

if __name__ == "__main__":
    solve()
    print(N - min_cnt)

# %%

# %%
