#include <iostream>
using namespace std;

int N;//보내려는 물품 개수
int C[10];//BOX 개수(1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 순)
int sol[10];//보내는 BOX 개수

int num[10] = { 1,5,10,50,100,500,1000,3000,6000,12000 };

int solve() {
	int i = 0, sum =0, cnt=0, total=0;
	for (i = 0; i < 10; i++) {
		sum += C[i] * num[i];
	}
	sum -= N;
	
	for (i = 9; i >= 0; i--) {
		cnt = sum / num[i];	
		if (cnt > C[i])
			cnt = C[i];
		sol[i] = C[i] - cnt;
		sum -= num[i] * cnt;
		total += sol[i];
	}
	return total;
}

void InputData() {
	int i;
	cin >> N;
	for (i = 0; i < 10; i++) {
		cin >> C[i];
	}
}



void OutputData(int ans) {
	int i;
	cout << ans << endl;
	for (i = 0; i < 10; i++) {
		cout << sol[i] << " ";
	}
	cout << endl;
}



int main() {
	int ans = -1;

	InputData();//	입력 함수
	ans = solve();

	//	코드를 작성하세요


	OutputData(ans);//	출력 함수

	return 0;
}