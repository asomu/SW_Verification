def Solve():    
    check = [[0] * 10 for _ in range(10)]
    for i in "123456789" :
        minR = minC = 10
        maxR = maxC = 0
        for r in range(N):
            for c in range(N):
                if A[r][c] != i : continue
                minR = min(minR, r)
                maxR = max(maxR, r)
                minC = min(minC, c)
                maxC = max(maxC, c)

        if minR == 10 : continue
        for r in range(minR, maxR+1):
            for c in range(minC, maxC+1):
                check[r][c] += 1

    cnt = 0
    for r in range(N):
        for c in range(N):
            if cnt < check[r][c] : cnt = check[r][c]
                
    return cnt

N = int(input())
A = [ input() for _ in range(N) ]

sol = Solve()
print(sol)