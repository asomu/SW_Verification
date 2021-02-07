#%%
stack = []
stack.append('a')
stack.append('b')
stack.append('c')
stack.append('d')
stack.append('e')

while stack:
    print(stack.pop())


# %%
N = int(input())
A = [ input() for a in range(N) ]
print(A)
# %%
