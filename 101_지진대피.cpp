#include <iostream>
#define MAX_BOX 500

using namespace std;

int N;	//자재박스의 개수
int Sx; // 지게차의 최초 열위치
int Sy; // 지게차의 최초 행위치
int BoxX[12000]; // 자재박스의 열위치
int BoxY[12000]; // 자재박스의 행위치

int map[510][510];
int visited[510][510];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

//queue

struct Point {
	int x;
	int y;
	int t;
	Point(int x, int y, int t) :x(x), y(y),t(t) {};
};

Point que[500 * 500 * 4];
int rp, wp;

void push(Point p) {
	que[wp] = p;
	wp++;
	visited[p.y][p.x] = p.t;
}

void pop() {
	rp++;
}

Point top() {
	return que[rp];
}

int IsEmpty(){
	return wp == rp;
}

void SetInit() {
	for (int i = 0; i < N; i++) {
		map[BoxY[i]][BoxX[i]] = 1;
	}
	for (int y = 1; y < 501; y++) {
		for (int x = 1; x < 501; x++) {
			visited[y][x] = MAX_BOX;
		}
	}
}

void BFS(int x, int y, int t) {
	Point tmp(x, y, t);
	for (int i = 0; i < 4; i++) {
		tmp.x = +dx[i];
		tmp.y =+ dy[i];
		tmp.t = +map[tmp.y][tmp.x];
		if (visited[tmp.y][tmp.x] <= t)
			continue;
		push(tmp);
	}
	while (!IsEmpty()) {
		tmp = top();
		pop();

		BFS(tmp.x, tmp.y, tmp.t);
	}
}

void InputData(void) {
	cin >> N >> Sx >> Sy;
	for (int i = 0; i < N; i++) {
		cin >> BoxX[i] >> BoxY[i];
	}
}

int main(void) {
	int ans = -1;
	InputData(); // 입력함수	
	SetInit();
	//	코드를 작성하세요

	cout << ans << endl;//출력
	return 0;
}

