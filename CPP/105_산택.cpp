#include <iostream>
#include <algorithm>
#define MaxPerson (int)1e5
using namespace std;

int N;//직원 수 100,000
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)



struct Person {
	int P;
	int S;
	long long E;
};
int idx = -1;

Person que[MaxPerson];

void push(Person p) {
	que[++idx] = p;
}

Person top() {
	return que[idx];
}

void pop() {
	if (idx != -1)
		idx--;
}

Person group[MaxPerson + 10];

void InputData() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> group[i].P >> group[i].S;
		group[i].E = (long long)group[i].P + (long long)group[i].S * (long long)T;
	}
}

bool comp(Person a, Person b) {
	return a.P > b.P;
}

int solve() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		while(idx > -1){
			if (top().E < group[i].E) {
				break;
			}
			else if (top().E == group[i].E) {
				pop();
				break;
			}
			else {
				pop();
			}
		}
		push(group[i]);
	}
	while (idx > -1) {
		cnt++;
		pop();
	}
	return cnt;
}

void printTest() {
	for (int i = 0; i < N; i++) {
		cout << group[i].P << " " << group[i].S << " " << group[i].E << endl;
	}
}

int main() {
	int ans = -1;

	InputData();			//	입력 함수
//	printTest();
	//	코드를 작성하세요
	ans = solve();
	
	cout << ans << endl;	//	정답 출력
	return 0;
}
