#include <stdio.h>

int N;//보내려는 물품 개수
int C[10];//BOX 개수(1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 순)
int sol[10];//보내는 BOX 개수

int num[10] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 };
int solve(){
	int sum = 0, i, cnt, totalcnt = 0;
	for(i = 0; i < 10; i++){
		sum += num[i] * C[i];
	}
	sum -= N;

	for(i = 9; i >= 0; i--){
		cnt = sum / num[i];
		if(cnt > C[i]) cnt = C[i];
		sum -= num[i] * cnt;
		sol[i] = C[i] - cnt;
		totalcnt += sol[i];
	}
	return totalcnt;
}

void InputData(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < 10; i++){
		scanf("%d", &C[i]);
	}
}
void OutputData(int ans){
	int i;
	printf("%d\n", ans);
	for(i = 0; i < 10; i++){
		printf("%d ", sol[i]);
	}
	printf("\n");
}
int main(){
	int ans = -1;

	InputData();//	입력 함수
    
	//	코드를 작성하세요
	ans = solve();

	OutputData(ans);//	출력 함수

	return 0;
}