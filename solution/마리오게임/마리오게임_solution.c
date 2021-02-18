#include <stdio.h>

int N;//버섯 수
int P[150000 + 10];//버섯 값

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d", &P[i]);
	}
}

int solve(void){
	int i, sum = P[0];
	for(i = 1; i < N; i++){
		if(P[i - 1] < P[i]) sum = sum - P[i - 1] + P[i];
	}
	return sum;
}

int main(void){
	int ans = -1;
	Input_Data();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
