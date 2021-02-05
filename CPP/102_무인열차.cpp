#include <iostream>
using namespace std;

int N; // 세로크기 Y
int M; // 가로크기 X
int map[50 + 10][50 + 10]; // 지도 데이터
int num;
int vn;
int maxCnt = 500 * 500;

int ABS(int x) {
	return x > 0 ? x : -x;
}

struct Position {
	int x;
	int y;
};

int wp, rp;
Position visit[2][2500];
Position q[50 * 50 * 10];

void enque(int x, int y) {
	q[wp].x = x;
	q[wp].y = y;
	wp++;
}

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

void FF(int y, int x) {
	map[y][x] = 0;
	enque(x, y);	
	while (wp > rp) {
		Position tmp = q[rp++];		
		visit[num][vn++] = tmp;
		for (int i = 0; i < 4; i++) {
			int cnt = 0;
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (map[ny][nx] == 0) continue;
			if (nx <1 || nx>M || ny<1 || ny>N) {
				continue;
			}
			map[ny][nx] = 0;
			enque(nx, ny);
		}
	}
}

void setup() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 1) {
				FF(i, j);
				num++;
				vn = 0;
			}
		}
	}
}


void solution() {
	int tmp;
	for (int i = 0; i < 2500; i++) {
		if (visit[0][i].x == 0 && visit[0][i].y == 0) break;
		for (int j = 0; j < 2500; j++) {
			if (visit[1][j].x == 0 && visit[1][j].y == 0) break;
			tmp = ABS(visit[0][i].x - visit[1][j].x) + ABS(visit[0][i].y - visit[1][j].y);
			if(tmp<maxCnt) maxCnt = tmp;
		}
	}
}



void InputData(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

}
int main(void) {
	int ans = -1;
	InputData();	//입력 함수
	setup();
	solution();
	// 코드를 작성 하세요
	ans = maxCnt - 1;
	cout << ans << endl;//출력
	return 0;
}