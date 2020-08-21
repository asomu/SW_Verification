#include <iostream>
#include <stack>
using namespace std;

int N;//송수신 안테나 수
int H[100000 + 10];//송수신 안테나 높이
stack<int> myStack;

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
}

int solve()
{
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		while (!myStack.empty() && H[i] > myStack.top()) {
			cnt++;
			myStack.pop();
		}
		if (!myStack.empty()) {
			cnt++;
			if (myStack.top() == H[i])
				myStack.pop();
		}
		myStack.push(H[i]);
	}
	return cnt;
}


int main() {
	int ans = -1;
	InputData();//	입력 함수
	ans = solve();

	//	코드를 작성하세요

	cout << ans << endl;//출력
	return 0;
}
