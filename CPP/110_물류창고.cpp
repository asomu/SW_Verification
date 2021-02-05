#include <iostream>
#define maxFactory 110
#define INF 100*100
using namespace std;


int N, M;//공장 수, 도로 정보 수
int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D
int dist[maxFactory][maxFactory];
int visit[maxFactory];

int que[INF];
int wp = 0;
int rp = 0;

void enQue(int n, int t) {
	if (visit[n] < t)
		return;
	que[wp++] = n;
	visit[n] = t;
}

int deQue() {
	return que[rp++];
}

void initDist() {
	for (size_t i = 0; i < maxFactory; i++)
	{
		for (size_t j = 0; j < maxFactory; j++)
		{
			dist[i][j] = INF;
		}
	}
}

int BFS(int start) {
	int max = 0;
	int  tmp = 0;
	wp = rp = 0;
	for (int i = 1; i <= N; i++) {
		visit[i] = INF;
	}
	enQue(start, 0);
	while (wp > rp) {
		tmp = deQue();
		for (int i = 1; i <= N; i++) {
			enQue(i, visit[tmp] + dist[tmp][i]);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (max < visit[i]) {
			max = visit[i];
		}
	}
	return max;

}

int solve() {
	int min = INF;
	int result = 0;
	for (int i = 1; i <= N; i++) {
		result = BFS(i);
		if (min > result) {
			min = result;
		}	
	}
	return min;
}



void InputData() {
	int i;
	int x, y, z;
	cin >> N >> M;
	for (i = 0; i < M; i++) {
		cin >> x >> y >>z;
		dist[x][y] = z;
		dist[y][x] = z;
	}
}

int main() {
	int ans = -1;
	initDist();
	InputData();//	입력 함수
	ans = solve();
	//	코드를 작성하세요


	cout << ans << endl;//	정답 출력
	return 0;
}