#include <iostream>
#define MaxN (int)1e6
using namespace std;



int N;//건물 수
int H[80010];//건물 높이

int que[MaxN];
int idx=-1;

void push(int h) {
	que[++idx] = h;
}

int top() {
	return que[idx];
}

bool IsEmpty() {
	if (idx == -1)
		return true;
	else
		return false;

}

void pop() {
	if(!IsEmpty())
		idx--;
}



void Input_Data(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
}



long long solve() {
	long long cnt = 0;
	for (int i = 0; i < N - 1; i++) {
		if (H[i] > H[i + 1]) {
			push(H[i]);
		}
		else {
			while (top() <= H[i + 1] && !IsEmpty()) {
				pop();
			}
		}
		cnt += (idx+1);
	}
	return cnt;
}

int main() {
	long long ans = -1;
	Input_Data();		//	입력 함수

	//	코드를 작성하세요

	ans = solve();
	cout << ans << endl;	//	정답 출력
	return 0;
}
