#%%
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

'''
#-------------------------------------------------------------
with  open(input_file_list[2], 'r') as r:
    input_list = r.readline().split()
    N = int(input_list[0])
    M = int(input_list[1])    
    map = [ r.readline().split() for i in range(N)]

#----------------------------------------------
'''
input_list = input().split()
N = int(input_list[0])
M = int(input_list[1])
map = [ input().split() for i in range(N)]
#---------------------------------------------

dx = [0,0,1,-1]
dy = [1,-1,0,0]


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
    
    map[y][x] = '0'
    point_building.append((y,x))
    queue.append((y,x))
    while queue:
        current_y, current_x = queue.pop(0)
        for i in range(4):
            check_x = current_x + dx[i]
            check_y = current_y + dy[i]
            if check_x < 0 or check_x >= M or check_y < 0 or check_y >= N:
                continue
            if map[check_y][check_x] == '1':
                map[check_y][check_x] = '0'
                point_building.append((check_y, check_x))
                queue.append((check_y, check_x))
    return point_building



    

def get_count_rail_module(total_builing):
    min_count_rail_module = N * M
    for start in total_builing[0]:
        for end in total_builing[1]:
            distance =  conut_rail_modlue(start, end)
            if min_count_rail_module > distance:
                min_count_rail_module =  distance
    return min_count_rail_module

def conut_rail_modlue(start, end):
    s_y, s_x = start
    e_y, e_x = end
    return abs(s_y - e_y) + abs(s_x - e_x) - 1

if __name__ == '__main__':
    total_builing = get_building_location()
    sol = get_count_rail_module(total_builing)

    print(sol)






# %%
