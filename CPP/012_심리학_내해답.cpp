#include <iostream>
//#define DEBUG
#define Feel (int)1e9

using namespace std;

int N;//후보자 수
int A[100000 + 10];//기질 값

int neg;
int pos;
int minFeel = Feel;

int ABS(int a) {
	return (a > 0) ? a : -a;
}

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

//1. find idx
//2. 상대편 찾는 함수.
//3. solve는 for 문으로 0부터 idx.

int FindIdx() {
	int mid = N / 2;
	int i;
	if (A[mid] < 0) {
		for (i = mid; i < N; i++) {
			if (A[i] > 0) {
				return i;
			}
		}
	}
	else {
		for (i = mid; i > 0; i--)
		{
			if (A[i] < 0) {
				return i + 1;
			}
		}
	}
	return 0;
}
//Type 1 timeout
void checkMin(int n, int idx) {
	int a = A[n];
	int minTemp;
	for (int i = idx; i < N; i++) {
		minTemp = ABS(a + A[i]);
		if (minTemp < minFeel) {
			minFeel = minTemp;
			neg = n;
			pos = i;
		}
	}
}

//Type 1 timeout
void checkMin2(int n, int idx) {
	int a = A[n];
	int minTemp;
	int mid = 0;
	int s = idx;
	int e = N-1;
	while (true)
	{
		int mid = (s + e) / 2;
		minTemp = ABS(a + A[mid]);
		if (minTemp < minFeel) {
			minFeel = minTemp;
			neg = n;
			pos = mid;
		}
		if (s == e)
			break;
		if ((a + A[mid]) > 0){
			e = mid;
		}	
		else{
			s = mid+1;
		}	
	}
}

void solve(int idx) {
	for (int i = 0; i < idx; i++) {
		checkMin2(i, idx);
	}
}

int main() {
	InputData();//	입력 함수
	int idx = FindIdx();
#if defined (DEBUG)
	cout << ABS(-1210) << endl;
#endif
	solve(idx);
	//	코드를 작성하세요
	cout << neg << " " << pos;

	return 0;
}
