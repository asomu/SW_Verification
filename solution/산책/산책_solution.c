#include <stdio.h>

int N;//직원 수
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)

long long stack[100000 + 10];

void Input_Data(void){
	int i;
	scanf("%d %d", &N, &T);
	for (i = 0; i < N; i++){
		scanf("%d %d", &P[i], &S[i]);
	}
}

int solve(void){
	int i, sp = 0;
	long long pos;
	for(i = 0; i < N; i++){
		pos = P[i] + (long long)T * S[i];
		for( ; (sp > 0) && (stack[sp] >= pos) ; sp--);
		stack[++sp] = pos;
	}
	return sp;
}

int main(void){
	int ans = -1;
	Input_Data();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
