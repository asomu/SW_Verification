#include <iostream>
using namespace std;

int N;//제품 수
int A[100 + 10];//제품 번호

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

int Find(){
	for(int i =1; i<N;i++){
		if(A[i] < A[i-1])
		{
			return i;
		}

	}
	return 0;
}

int solve(int n){
	if(n == 0)
		return 0;
	int target = A[n];
	int i = n-1;
	int cnt = 0;
	int tmp = 0;
	while(true){
		int test = A[i--];
		if(tmp == test)	
			continue;
		else
			tmp = test;
		if(target < test)
			cnt++;
		else
			return cnt;
	}
	return -1;
}

int main(){
	int ans = -1;
	InputData();//	입력 함수
	
#if 0
	ans=Find();
#else
	int n = Find();
	ans = solve(n);
#endif
	//	코드를 작성하세요
	
	cout << ans << endl;//출력
	return 0;
}
