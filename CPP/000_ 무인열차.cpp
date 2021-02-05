#include <iostream>
using namespace std;

int N;
int M;
int map[50 + 10][50 + 10];

struct st {
	int x, y;
}dat[2][50*50];

st queue[50 * 50];
int wp, rp;
int ncount;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
#define ABS(a) (((a) < 0) ? -(a) : (a))

void BFS(int y, int x, int p) {
	int i, nx, ny;
	st d;
	wp = rp = 0;

	dat[p][ncount].x = queue[wp].x = x;
	dat[p][ncount].y = queue[wp].y = y;
	wp++;
	while (wp>rp)
	{
		d = queue[rp++];
		for (i = 0; i < 4; i++) {
			nx = d.x + dx[i];
			ny = d.y + dy[i];
			if (map[ny][nx] == 0) continue;
			map[ny][nx] = 0;
			ncount++;
			dat[p][ncount].x = queue[wp].x = nx;
			dat[p][ncount].y = queue[wp].y = ny;
			wp++;
		}
	}
}

int solve() {
	int ans = 0x7FFFFFFF;
	int point = 0;
	int cnt[2] = { 0, };
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++) {
			if (map[i][j] == 1) {
				ncount = 1;
				BFS(i, j, point);
				cnt[point] = ncount;
				point++;
			}
		}
	}
	for (i = 1; i <= cnt[0]; i++) {
		for (j = 1; j <= cnt[1]; j++) {
			int tmp = ABS(dat[0][i].x - dat[1][j].x) + ABS(dat[0][i].y - dat[1][j].y);
			if (tmp < ans) ans = tmp;
		}
	}
	return ans - 1;
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

	InputData();	// 입력함수

	// 코드를 작성 하세요

	int ans = solve();
	cout << ans << endl;
	return 0;
}