#include <iostream>
#define IFX 0xFFFFFFF
using namespace std;

int N;//지도 크기
char map[110][110];//지도 정보

struct Position {
	int y;
	int x;
	int t;
};

int rp, wp;
int num[110][110];
Position que[1100 * 1100];

void enque(int x, int y, int t) {
	que[wp].x = x;
	que[wp].y = y;
	que[wp].t = t;
	wp++;
}



int visit[110][110];

int dx[] = { 0,0,-1,1 };

int dy[] = { -1,1, 0,0 };

void bfs(int y, int x) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = IFX;
		}
	}

	visit[y][x] = num[y][x];
	enque(x, y, visit[y][x]);
	while (rp < wp) {
		Position tmp = que[rp++];
		for (int i = 0; i < 4; i++) {
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
			if (visit[ny][nx] > visit[tmp.y][tmp.x] + num[ny][nx]) {
				visit[ny][nx] = visit[tmp.y][tmp.x] + num[ny][nx];
				enque(nx, ny, visit[ny][nx]);
			}				
		}
	}
	
}

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

int main(){
	int ans = -1;
	Input_Data();		//	입력 함수
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			num[i][j] = map[i][j] - '0';
		}
	}
	//	코드를 작성하세요
	bfs(0,0);
	/*
	cout << "WP: "<<wp<<endl;
	cout << "RP: "<<rp<<endl;
	*/
	cout << visit[N-1][N-1] << endl;	//	정답 출력
	
	return 0;
}
