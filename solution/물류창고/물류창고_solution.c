#include <stdio.h>
int N, M;//공장 수, 도로 정보 수
int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D

#define IMP (100 * 100 + 10)
#define MAXQ (100 * 100 * 100)
int dist[110][110];
int visit[110];
int queue[MAXQ];
int wp, rp;
void push(int n, int t){
	if(visit[n] <= t) return;
	visit[n] = t; queue[wp++] = n;
}
int front(){ return queue[rp];}
void pop() { rp++;}
int empty() {return wp == rp;}
int BFS(int s){
	int i, tmp,  max = 0;
	for (i = 1; i <= N; i++) visit[i] = IMP;
	wp = rp =0;
	push(s, 0);
	while(!empty()){
		tmp = front(); pop();
		for(i = 1; i <= N; i++){
			push(i, visit[tmp] + dist[tmp][i]);
		}
	}
	for (i = 1; i <= N; i++) if(max < visit[i]) max = visit[i];
	return max;
}
int solve(){
	int i, j, sol = IMP, ret;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			dist[i][j] = IMP;
		}
	}
	for (i = 0; i < M; i++) dist[A[i]][B[i]] = dist[B[i]][A[i]] = D[i];
	for(i = 1; i <= N; i++){
		ret = BFS(i);
		if(sol > ret) sol = ret;
	}
	return sol;
}
void InputData(){
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++){
		scanf("%d %d %d", &A[i], &B[i], &D[i]);
	}
}
int main(){
	int ans = -1;
	InputData();//	입력 함수
	//	코드를 작성하세요
	ans = solve();
	printf("%d\n", ans);//	정답 출력
	return 0;
}
