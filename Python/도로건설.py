#%%
#분류: BFS
#난이도 ***
N = int(input())
A = [ input().rstrip('\n') for _ in range(N) ]

point = {'x':0, 'y':0}
my_queue = []
dx = [0,0,-1,1]
dy = [-1,1,0,0]
price = []
# price.append([])
INF = 1000

def init_price():
    for y in range(N):
        price.append([])
        for x in range(N):
            price[y].append(INF)

def bfs():
    price[0][0] = 0
    my_queue.append(point.copy())
    while my_queue:
        tmp = my_queue.pop(0)
        for i in range(4):
            point['x'] = tmp['x'] + dx[i]
            point['y'] = tmp['y'] + dy[i]            
            if point['x'] < 0 or point['x'] >= N or point['y'] < 0 or point['y'] >= N:
                continue
            if price[point['x']][point['y']] > int(A[point['x']][point['y']]) + price[tmp['x']][tmp['y']]:
                price[point['x']][point['y']] = int(A[point['x']][point['y']]) + price[tmp['x']][tmp['y']]
                my_queue.append(point.copy())


def solve():
    init_price()
    bfs()

solve()
print(price[N-1][N-1])