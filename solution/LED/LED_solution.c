#include <stdio.h>

int N;//LED 수
int S[100000 + 10];//LED 상태

int pat[100000 + 10];//초기 ON/OFF 패턴 개수 

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &S[i]);
	}
}

int solve(void){
	int i, max = 0, cnt = 0, seq = 1;
	for(i = 1; i < N; i++){
		if(S[i] != S[i - 1]) seq++;
		else{
			pat[cnt++] = seq;
			seq = 1;
		}
	}
	pat[cnt++] = seq;
	
	if(cnt < 2){
		for(i = 0; i < cnt; i++) max += pat[i];
	}
	else{
		max = pat[0] + pat[1] + pat[2];
		seq = pat[1] + pat[2];
		for(i = 3; i < cnt; i++){
			seq += pat[i];
			if(max < seq) max = seq;
			seq -= pat[i - 2];
		}
	}
	return max;
}

int main(void){
	int ans = -1;
	Input_Data();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
