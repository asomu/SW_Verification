#include <iostream>
using namespace std;

int N;//후보자 수
int A[100000 + 10];//기질 값

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

int ABS(int x) {
	return (x < 0) ? -x : x;
}

void solve() {
	int minSum = (int)2e9;
	int i = 0, j = N - 1, sum, minans, maxans;
	while (i < j) {
		sum = A[i] + A[j];
		if (ABS(sum) < minSum) {
			minSum = ABS(sum);
			minans = i;
			maxans = j;
		}
		if (sum > 0) {
			j--;
		}
		else if (sum < 0)
			i++;
		else
			break;
	}
	cout << minans << " " << maxans << endl;
}

int main() {
	InputData();//	입력 함수
	cout << ABS(10);
	//	코드를 작성하세요
	solve();

	return 0;
}
