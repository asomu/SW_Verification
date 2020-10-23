#include <iostream>
#define MAX_BOX 500
#define MAX_MAP 501

using namespace std;

int N;	//자재박스의 개수
int Sx; // 지게차의 최초 열위치
int Sy; // 지게차의 최초 행위치
int BoxX[12000]; // 자재박스의 열위치
int BoxY[12000]; // 자재박스의 행위치


int map[MAX_MAP][MAX_MAP];
int visited[MAX_MAP][MAX_MAP];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

//queue

struct Point {
	int x = 0;
	int y = 0;
	int t = 0;
};

Point start;
Point que[500 * 500 * 4];
int rp;
int wp;

void push(Point p) {
	que[wp] = p;
	wp++;
}

void pop() {
	rp++;
}

Point top() {
	return que[rp];
}

int IsEmpty() {
	return wp == rp;
}

void SetInit() {
	for (int i = 0; i < N; i++) {
		map[BoxY[i]][BoxX[i]] = 1;
	}
}

void BFS(Point start) {
	visited[start.y][start.x] = 1;
	start.t = 0;
	push(start);
	while (wp > rp) {
		Point tmp = que[rp++];
		if (visited[tmp.y][tmp.x] < tmp.t) continue;
		for (int i = 0; i < 4; i++) {
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (nx<0 || nx>MAX_MAP-1 || ny<0 || ny>MAX_MAP-1)continue;
			if (visited[ny][nx] == 0 || visited[tmp.y][tmp.x] + map[ny][nx] < visited[ny][nx]) {
				visited[ny][nx] = visited[tmp.y][tmp.x] + map[ny][nx];
				tmp.x = nx;
				tmp.y = ny;
				tmp.t = visited[ny][nx];
				push(tmp);
			}
		}
	}
}

void InputData(void) {
	cin >> N >> start.x >> start.y;
	for (int i = 0; i < N; i++) {
		cin >> BoxX[i] >> BoxY[i];
	}
}

int main(void) {
	int ans = -1;
	InputData(); // 입력함수	
	SetInit();
	BFS(start);
	ans = visited[1][1];
	//	코드를 작성하세요
	cout << ans - 1 << endl;//출력
	return 0;
}