#%%
N = int(input())
A = list(map(int, input().split()))



def count_total():
    plus = 0
    minus = 0
    total = 0
    flag = True
    for item in A:
        if flag:
            if plus <= item:
                plus = item
            else:
                minus = item
                total += plus
                flag = False
        else:
            if minus >= item:
                minus = item
            else:
                plus = item
                total -= minus
                flag = True
    if flag:
        total += plus
    return total

if __name__ == '__main__':    
    print(count_total())



# %%
