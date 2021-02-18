#include <stdio.h>

int N;//건물 수
int H[80010];//건물 높이

int stack[80010];

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		scanf("%d", &H[i]);
	}
}

long long solve(){
	int sp = 0, i;
	long long sum = 0;
	for(i=0; i<N ; i++){
		while(sp > 0){
			if(H[i] < stack[sp]) break;
			sp--;
		}
		sum += sp;
		stack[++sp] = H[i];
	}
	return sum;
}

int main(void){
	long long ans = -1;
	Input_Data();
	ans = solve();
	printf("%lld\n", ans);
	return 0;
}