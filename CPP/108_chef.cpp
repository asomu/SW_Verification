#include <iostream>
#include <algorithm>
using namespace std;

int N;//손님 수
int P[10000 + 10];//음식 값
int T[10000 + 10];//예약 희망 시간
int timeTable[10000 + 10];

struct Person {
	int pay;
	int time;
};

Person customer[10000 + 10];

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> customer[i].pay;
		cin >> customer[i].time;
	}
}

bool comp(Person a, Person b) {
	if (a.pay > b.pay)
		return true;
	else
		return false;
}

int solve() {
	int all_pay = 0;
	sort(customer, customer + N, comp);
	for (int i = 0; i < N; i++) {
		if (timeTable[customer[i].time] == 0) {
			all_pay += customer[i].pay;
			timeTable[customer[i].time] = customer[i].pay;
		}
		else{
			for (int j = customer[i].time - 1; j > 0; j--) {
				if (timeTable[j] == 0) {
					all_pay += customer[i].pay;
					timeTable[j] = customer[i].pay;
					break;
				}
			}
		}
	}
	return all_pay;
}


int main() {
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	ans = solve();
	cout << ans << endl;	//	정답 출력
	return 0;
}
