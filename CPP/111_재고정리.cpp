#include <iostream>
#define MAX_NUM 100000 + 10
#define MAX_MEM 10
using namespace std;

int N;//제품 수 N = 1e5
int M;//제품 종류 수
int ID[100000 + 10];//제품 ID

int totalCnt = MAX_NUM;

int sum[MAX_MEM][MAX_NUM];
int squense[MAX_MEM];
int used[MAX_MEM];
int mCnt[MAX_MEM];

void InputData() {
	int i;
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		cin >> ID[i];
	}
}

void DFS(int n, int p, int cnt) {
	int tmp;
	if (totalCnt < cnt) {
		return;
	}
	if (n > M) {
		totalCnt = cnt;
		return;
	}
	for (int i = 1; i <= M; i++) {
		if (used[i]) continue;
		used[i] = 1;
		squense[n] = i;
		tmp = mCnt[i] - (sum[i][p + mCnt[i] - 1] - sum[i][p - 1]); // i 인자의 해당 squence 위치에서 숫자.
		DFS(n + 1, p + mCnt[i], cnt + tmp);
		used[i] = 0;
	}
}


int solve() {
	for (int i = 1; i <= N; i++) {
		sum[ID[i]][i] = 1;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			sum[i][j] = sum[i][j] + sum[i][j - 1];
		}
		mCnt[i] = sum[i][N];
	}
	DFS(1, 1, 0);
}




int main() {
	int ans = -1;

	InputData();//입력 함수
	solve();
	//	코드를 작성하세요

	cout << totalCnt << endl;
	return 0;
}