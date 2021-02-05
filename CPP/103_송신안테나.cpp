#include <iostream>
using namespace std;

int N;//직원 수
int T;//산책 시간(분단위)
int P[100000 + 10];//직원 출발 위치
int S[100000 + 10];//직원 산책 속도(분당)

void InputData(){
	cin >> N >> T;
	for (int i = 0; i < N; i++){
		cin >> P[i] >> S[i];
	}
}

int main(){
	int ans = -1;

	InputData();			//	입력 함수

	//	코드를 작성하세요
	
	
	cout << ans << endl;	//	정답 출력
	return 0;
}
