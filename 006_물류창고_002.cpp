#include <iostream>
#define IMP (int)(100*100+10)
#define MAXQ (int)(100*100*100)
using namespace std;

int N, M;//공장 수, 도로 정보 수
int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D
int visit[100+10];
int dist[100+10][100+10];
int queue[MAXQ];
int wp,rp;

void push(int n, int t){
	if(visit[n] <= t)
    	return;
    queue[wp++] = n;   
    visit[n] = t;
}

void pop(){
    rp++;
}

int front(){
    return queue[rp];
}

int empty(){
	return wp == rp;
}


void InputData(){
	int i;
	cin >> N >> M;
	for (i = 0; i < M; i++){
		cin >> A[i] >> B[i] >> D[i];
	}
}

int BFS(int start){
	int tmp,max = 0;
	wp, rp =0;
	for(int i=1;i<=N;i++){
		visit[i] = IMP;
	}
	push(start,  0);
	while(!empty()){
		tmp = front();pop();
		for(int i=1;i<=N;i++){
			push(i, visit[tmp]+dist[tmp][i]);
		}
	}

	for(int i = 1; i<=N;i++){
		if(visit[i] > max){
			max = visit[i];
		}
	}

	return max;
}


int solve(){
	int i, j, ret =0;
	int sol = IMP;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			dist[i][j] = IMP;
		}
	}	

	for(i=0;i<M;i++){
			dist[A[i]][B[i]] = dist[B[i]][A[i]] = D[i];
	}


	for(i=1;i<=N;i++){
		ret = BFS(i);
		if(sol>ret){
			sol = ret;
		}
	}
	return sol;
}
int main(){
	int ans = -1;
	InputData();//	입력 함수
	ans = solve();
	//	코드를 작성하세요

	
	cout << ans << endl;//	정답 출력
	return 0;
}