#%%
#분류: DFS
#점수:30

N = int(input())
R = []
P = []

for i in range(N):
    Number = input().strip("\n").split()
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
