#%%
#분류: Stack, Sliding Window.
#난이도 **
import os
from glob import glob

N = int(input())
A = [ int(input()) for _ in range(N) ]

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
                my_stack.append(item)
    return cnt

sol =  solve(A)
print(sol)

# %%
