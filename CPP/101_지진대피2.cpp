#include <iostream>
using namespace std;

/*
1. MAXN = 500 * 500
2. BFS 중복 방문 허용.
3. Queue 이용
4. 의미는 start 위치에서 외곽까지 최소 거리비용을 알내는 문제

*/
#define MAXN 500
#define iINF 12000

int N;	//자재박스의 개수
int Sx; // 지게차의 최초 열위치
int Sy; // 지게차의 최초 행위치
int BoxX[12000]; // 자재박스의 열위치
int BoxY[12000]; // 자재박스의 행위치
int map[MAXN + 10][MAXN + 10];
int visited[MAXN + 10][MAXN + 10];
int wp, rp;

struct Position {
	int x;
	int y;
	int t;
};

Position que[MAXN * MAXN * 10];

void push(int x, int y, int t) {
	if (visited[y][x] == 0 || visited[y][x] > t) {
		visited[y][x] = t;
		que[wp].x = x;
		que[wp].y = y;
		que[wp].t = t;
		wp++;
	}
}

Position pop() {
	return que[rp++];
}

bool IsEmpty() {
	return rp == wp;
}

void InputData(void) {
	cin >> N >> Sx >> Sy;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		map[y][x] = 1;
	}
}

int bfs(int x, int y, int t) {
	wp = rp = 0;
	push(x, y, t);
	int dx[] = { 0,0,-1,1 };
	int dy[] = { -1,1,0,0 };
	while (!IsEmpty()) {
		Position cur = pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx<0 || nx>MAXN + 1 || ny<0 || ny>MAXN + 1) continue;
			push(nx, ny, cur.t + map[ny][nx]);
		}
	}
	return visited[0][0] - 1;
}

int main(void) {
	int ans = -1;
	InputData(); // 입력함수	
	ans = bfs(Sx, Sy, 1);
	//	코드를 작성하세요

	cout << ans << endl;//출력
	return 0;
}

