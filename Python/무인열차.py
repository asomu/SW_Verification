#%%
import builtins


input_list = input().split()
N = int(input_list[0])
M = int(input_list[1])

map = [ input().split() for i in range(N)]

dx = [0,0,1,-1]
dy = [1,-1,0,0]

'''

map = [ input().split() for i in range(N)]
for y, item in enumerate(map):
    for x, point in enumerate(item):
        print(y, x, point)

'''


def get_building_location():
    total_building = []
    for y, item in enumerate(map):
        for x, point in enumerate(item):
            if point == '1':
                total_building.append(floodfill(y,x))
    return total_building
                


def floodfill(y,x):
    point_building = []
    queue = []
    map[y][x] == '0'
    queue.append((y,x))
    while queue:
        current_y, current_x = queue.pop(0)
        for i in range(4):
            check_x = current_x + dx[i]
            check_y = current_y + dy[i]
            if check_x < 0 or check_x >= N or check_y < 0 or check_y >= N:
                continue
            if map[check_y][check_x] == '1':
                map[check_y][check_x] = '0'
                point_building.append((check_y, check_x))
                queue.append((check_y, check_x))
    return point_building



    

def get_count_rail_module():
    pass

if __name__ == '__main__':
    total_builing = get_building_location()
    for item in total_builing:
        print(item)
    # sol = get_count_rail_module()
    # print(sol)



# %%
test = 13
if test > 12 or test < 0 :
    print("OK")
# %%
