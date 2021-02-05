#include <iostream>
using namespace std;

int N;//손님 수
int P[10000 + 10];//음식 값
int T[10000 + 10];//예약 희망 시간
int rev[10000 + 10];

int solve() {
	int i, j,tmp, price, sum=0;
	for (i = 0; i < N; i++) {
		price = P[i];
		for (j = T[i]; j > 0; j--) {
			if (rev[j] == 0) {
				rev[j] = price;
				break;
			}
			else if (rev[j] < price) {
				tmp = rev[j];
				rev[j] = price;
				price = tmp;
			}
		}
	}
	for (i = 1; i < 10000 + 10; i++) {
		sum += rev[i];
	}
	return sum;
}


void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i];
		cin >> T[i];
	}
}

int main() {
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	ans = solve();
	cout << ans << endl;	//	정답 출력
	return 0;
}
