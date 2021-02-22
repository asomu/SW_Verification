#%%
#분류: 배열 - LIST - DIC
#난이도 **
N = int(input())
A = [ input().rstrip('\n') for _ in range(N) ]

pure_color = [0,0,0,0,0,0,0,0,0,0]
dic_color = {}

def init_dic_color():
    for i in range(10):
        dic_color[str(i)] = {'MIN':{'Y':10,'X':10},'MAX':{'Y':0,'X':0}}

def set_color_point():
    for y, item in enumerate(A):
        for x, char in enumerate(item):
            if char == '0':
                continue
            if dic_color[char]['MIN']['Y'] >= y:
                dic_color[char]['MIN']['Y'] = y
            if  dic_color[char]['MIN']['X'] >= x:
                dic_color[char]['MIN']['X'] = x
            if dic_color[char]['MAX']['Y'] <= y:
                dic_color[char]['MAX']['Y'] = y
            if dic_color[char]['MAX']['X'] <= x:
                dic_color[char]['MAX']['X'] = x
                pure_color[int(char)] = 1

def print_color():
    for key, value in dic_color.items():
        print(key, value)

def set_pure_color():
    for key, value in dic_color.items():
        if value['MIN']['X'] == 10 or key == '0':
            continue
        for y in range(value['MIN']['Y'],value['MAX']['Y']+1):
            for x in range(value['MIN']['X'],value['MAX']['X']+1):
                if A[y][x] != key:
                    pure_color[int(A[y][x])] = 0

def solve():
    init_dic_color()
    set_color_point()
    set_pure_color()
    return sum(pure_color)

print(solve())