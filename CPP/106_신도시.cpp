#include <iostream>
using namespace std;

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보
int visited[20][20];

int dx[12][4] = { {0,0,0,0}, {-1,1,0,0}, {0,0,0,0}, {1,0,0,0}, {-1,0,0,0}, {-1,0,0,0}, {1,0,0,0}, {0,0,1,0}, {-1,1,0,0}, {-1,0,0,0}, {0,-1,1,0}, {0,0,-1,1} };
int dy[12][4] = { {0,0,0,0}, {0,0,0,0}, {-1,1,0,0}, {0,1,0,0}, {0,1,0,0}, {0,-1,0,0}, {0,-1,0,0}, {-1,1,0,0}, {0,0,1,0}, {0,1,-1,0}, {-1,0,0,0}, {-1,1,0,0} };

struct Position {
	int x = 0;
	int y = 0;
	Position(int x, int y) :x(x), y(y) {};
	Position() {};
};

int rp, wp;
Position Que[10 * 10];

void enQue(int x, int y) {
	Que[wp].x = x;
	Que[wp++].y = y;
}

Position deQue() {
	return Que[rp++];
}

int solve() {
	enQue(X, Y);
	int pipe = 0;
	int newPipe = 0;
	int curX = 0;
	int curY = 0;
	int nx = 0;
	int ny = 0;
	while (wp > rp) {
		Position tmp = deQue();
		curX = tmp.x;
		curY = tmp.y;
		pipe = map[tmp.y][tmp.x];
	
		for (int i = 0; i < 4; i++) {
			if (dx[pipe][i] == 0 && dy[pipe][i] == 0) break;
			nx = curX + dx[pipe][i];
			ny = curY + dy[pipe][i];
			if (nx < 0 || ny < 0 || nx > N || ny > N || visited[ny][nx] == 1) continue;
			newPipe = map[ny][nx];
			for (int j = 0; j < 4; j++) {
				if (dx[newPipe][j] == 0 && dy[newPipe][j] == 0) break;
				if (dx[pipe][i] * -1 == dx[newPipe][j] && dy[pipe][i] * -1 == dy[newPipe][j]) {
					enQue(nx, ny);
					visited[ny][nx] = 1;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 1)
				map[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] > 0)
				cnt++;
		}
	}
	return cnt;

}



void Input_Data(void) {
	char str[20];
	cin >> N;
	cin >> X >> Y;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] < 'A') {
				map[i][j] = str[j] - '0';
			}
			else {
				map[i][j] = str[j] - 'A' + 10; \
			}
		}
	}
}



int main() {
	int ans = -1;
	Input_Data();		//	입력 함수
	ans = solve();
	//	코드를 작성하세요


	cout << ans << endl;	//	정답 출력
	return 0;
}
