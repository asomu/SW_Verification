#include <iostream>
using namespace std;

int N;//버섯 수
int P[150000 + 10];//버섯 값

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
	}
}

int solve(){
	int sum = P[0];
	for(int i = 1; i < N; i++){
		if(P[i - 1] < P[i]) sum = sum - P[i - 1] + P[i];
	}
	return sum;
}

int main(){
	int ans = -1;
	InputData();
	ans = solve();
	cout << ans << endl;
	return 0;
}