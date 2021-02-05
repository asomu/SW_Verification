#include <iostream>
#include <algorithm>
using namespace std;

int N;//제품 수 50,000
struct st {
	int X, ID;//위치, 아이디
};
st A[50010];

int newId[50010];
int visit[50010];
int max_cnt;


void countID() {
	for (int i = 0; i < N; i++) {
		int nId = A[i].ID % 50000; //hash key 
		for (int j = 0; j < 50000; j++) {
			if (newId[nId] == 0 ) {
				max_cnt++;
				newId[nId] = A[i].ID; //hash key 로 real ID를 찾을 수 있다.
				A[i].ID = nId; //ID 에 hash key 값을 넣었다.
				break;
			}
			else if (newId[nId] == A[i].ID) {
				A[i].ID = nId;
				break;
			}
			nId = (nId + 1) % 50000;
		}		
	}
}

bool comp(st a, st b) {	
	if (a.X < b.X)
		return true;
	else
		return false;

}

int solve() {
	int min = 1 << 30;
	int i= 0, j = 0;
	int cnt = 0;
	countID();
	sort(A, A + N, comp);
	for (;;) {
		while (i < N && (max_cnt > cnt)) {
			if (visit[A[i++].ID]++ == 0) {
				cnt++;
			}
			
		}
		if (max_cnt != cnt) break;
		while (visit[A[j].ID] > 1) {
			visit[A[j++].ID]--;
		}
		if (min > A[i - 1].X - A[j].X) {
			min = A[i - 1].X - A[j].X;
		}
		cnt--;
		visit[A[j].ID] = 0;
		j++;		
	}
	return min;
}



void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].X >> A[i].ID;
	}
}

int main() {
	int ans = -1;

	InputData();			//	입력 함수

	ans = solve();
	//	코드를 작성하세요


	cout << ans << endl;	//	정답 출력
	return 0;
}
