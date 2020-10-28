

#include <iostream>
#define MAX_STACK (int)1e5
using namespace std;

int N;//송수신 안테나 수
int H[100000 + 10];//송수신 안테나 높이

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
}

int MyStack[MAX_STACK];
int idx = -1;

void push(int a) {
	MyStack[++idx] = a;
}

int pop() {
	return MyStack[idx--];
}

bool isEmpty() {
	return idx < 0;
}

int solve() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!isEmpty())
		{
			if (MyStack[idx] < H[i]) {
				while (!isEmpty()) {
					pop();
					cnt++;
				}
			}
			else if (MyStack[idx] == H[i]) {
				cnt++;
				continue;
			}
			else {
				cnt++;
			}
		}
		push(H[i]);
	}
	return cnt;
}



int main() {
	int ans = -1;
	InputData();//	입력 함수
	//	코드를 작성하세요
	ans = solve();
	cout << ans << endl;//출력
	return 0;
}
