#include <iostream>
using namespace std;

int N;//LED 수
int S[100000 + 10];//LED 상태

int pat[100000 + 10];//초기 ON/OFF 패턴 개수 

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> S[i];
	}
}

int solve(){
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

int main(){
	int ans = -1;
	InputData();
	ans = solve();
	cout << ans << endl;
	return 0;
}