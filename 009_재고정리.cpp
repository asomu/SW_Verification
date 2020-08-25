#include <iostream>
using namespace std;

int N;//제품 수
int M;//제품 종류 수
int ID[100000 + 10];//제품 ID

int sol;
int cnt[10];
int used[10];
int sum[10][100000 + 10];


//n=선택한 숫자...depth 이것이 m보다 크면 종료. p = 포지션, 커서 m= 누적 상자옮긴 수
void DFS(int n, int p, int m) {
	int i;
	if (sol <= m)
		return;
	if (n > M) {
		sol = m;
		return;
	}
	for (i = 1; i <= M; i++) {
		if (used[i] == 1)
			continue;
		used[i] = 1;
		//mcnt 총 옮긴 상자 수
		//갯수에 포지션에 있는 갯수를 빼면 옮긴 상자 수
		int mcnt = cnt[i] - (sum[i][p + cnt[i] - 1] - sum[i][p - 1]);
		DFS(n + 1, p + cnt[i], m + mcnt);
		used[i] = 0;
	}
}
int solve() {
	int i, j;
	for (i = 1; i <= N; i++) {
		sum[ID[i]][i] = 1;
	}
	for (i = 1; i <= M; i++) {
		for (j = 2; j <= N; j++)
		{
			sum[i][j] += sum[i][j - 1];
		}
		cnt[i] = sum[i][N];
	}
	sol = N; //충분히 높은값...N은 모든 상자가 다 틀리다는 얘기..

	DFS(1, 1, 0);
	return sol;
}

void InputData() {
	int i;
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		cin >> ID[i];
	}
}



int main() {
	int ans = -1;

	InputData();//입력 함수

	//	코드를 작성하세요
	ans = solve();
	cout << ans << endl;
	return 0;
}