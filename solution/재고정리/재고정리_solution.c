#include <stdio.h>

int N;//제품 수
int M;//제품 종류 수
int ID[100000 + 10];//제품 ID

int sum[10][100000 + 10];
int cnt[10];
int used[10];
int sol;
void DFS(int n, int p, int m){
	int i;
	if(sol <= m) return;//가지치기, 이미 이전 답보다 좋지 않음
	if(n > M){//완성, 종료 조건
		sol = m; return;
	}
	for(i = 1; i <= M; i++){//제품 ID
		if(used[i]) continue;//이미 i번 제품은 정리 했음
		used[i] = 1;
		int mcnt = cnt[i] - (sum[i][p + cnt[i] - 1] - sum[i][p - 1]);
		DFS(n + 1, p + cnt[i], m + mcnt);
		used[i] = 0;
	}
}
int solve(){
	int i, j;
	for(i = 1; i <= N; i++) sum[ID[i]][i] = 1;
	for(i = 1; i <= M; i++){//ID 1~M
		for(j = 2; j <= N; j++) sum[i][j] += sum[i][j - 1];
		cnt[i] = sum[i][N];
	}
	sol = N;
	DFS(1, 1, 0);//순서, 놓을 첫 위치, 옮긴 수
	return sol;
}

void InputData(){
	int i;
	scanf("%d %d", &N, &M);
	for(i = 1; i <= N; i++){
		scanf("%d", &ID[i]);
	}
}
int main(){
	int ans = -1;

	InputData();//입력 함수
	
	//	코드를 작성하세요
	ans = solve();

	printf("%d\n", ans);
	return 0;
}