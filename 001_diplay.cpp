#include <iostream>
#include <cmath>
#define MAX_DIFF (int)1e6

using namespace std;

int N;	// 필터의 수
int R[11]; // 반사의 정도
int P[11]; // 투과의 정도
int minDiff;
int minCnt;

void DFS(int start, int cnt, int mul, int sum)
{
	if(cnt != 0){
		int diff = abs(mul - sum);
		if((minDiff > diff) || ((minDiff == diff) && (minCnt > cnt))){
			minDiff = diff;
			minCnt = cnt;
		}
	}
	for(int i = start; i<=N; i++){
		DFS(i + 1, cnt + 1, mul * R[i], sum + P[i]);
	}
}

int solve()
{
	minDiff = MAX_DIFF;
	DFS(1, 0, 1, 0);
	return N - minCnt;
}

void InputData(void){
	cin >> N;
	for(int i=1; i<=N; i++)  cin >> R[i] >> P[i];
}

int main(){
	int ans = -1;
	InputData(); // 입력함수
	ans = solve();
	// 코드를 작성 하세요
	
	cout << ans << endl;//출력
	return 0;
}