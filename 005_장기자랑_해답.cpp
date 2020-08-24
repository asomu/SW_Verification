#include <iostream>
#define MAXQ (1<<16)
#define MOD (MAXQ -1)
using namespace std;



//Size 별 계산....
//Queue 만들기
//solve..
//

int N;//직원 수
int S;//시작 직원 번호
int M;

int queue[MAXQ];
int wp, rp;

void push(int n) {
	queue[wp] = n;
	wp = (wp + 1) % N; //WP를 circular 로 만들어 준다.
}
int front() {
	return queue[rp];
}

void pop() {
	rp = (rp + 1) % N;
}

int empty() {	
	return wp == rp;
}

void solve() {
	int i, j = S;
	for (i = 1; i <= N; i++) {
		push(j);
		if (++j > N)
			j = 1;
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j < M; j++) {
			push(front());
			pop();
		}
		cout << front()<<" ";
		pop();
	}
}



void InputData() {
	cin >> N >> S >> M;
}
int main() {

	InputData();//	입력 함수
	solve();
	//	코드를 작성하세요


	return 0;
}