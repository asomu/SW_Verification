#include <iostream>
#include <vector>
using namespace std;

struct POINT {
	int x;
	int y;
};

struct SAK {
	POINT minP;
	POINT maxP;
};

SAK allSak[10];
vector<int> idx;
int cnt[10];
int cnt2[10];

int N;//도화지 크기
char A[10 + 2][10 + 2];//도화지 색정보

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
}

void IntiSak() {
	for (int i = 0; i <= 9; i++) {
		allSak[i].minP.x = N;
		allSak[i].minP.y = N;
		allSak[i].maxP.x = 0;
		allSak[i].maxP.y = 0;
	}
}

void SaveSak() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			int color = A[y][x] - '0';
			cnt[color] = 1;
			cnt2[color] = 1;
			if (allSak[color].minP.x > x)
				allSak[color].minP.x = x;
			if (allSak[color].minP.y > y)
				allSak[color].minP.y = y;
 			if (allSak[color].maxP.x < x)
				allSak[color].maxP.x = x;
			if (allSak[color].maxP.y < y)
				allSak[color].maxP.y = y;
		}
	}
}

void PrintSak() {
	for (int i = 0; i <= 9; i++) {
		cout << i << ": MIN(" << allSak[i].minP.x << ", " << allSak[i].minP.y << ")" << endl;
		cout << i << ": MAX(" << allSak[i].maxP.x << ", " << allSak[i].maxP.y << ")" << endl;
	}

}

void CalcSak() {
	for (int i = 1; i <= 9; i++) {
		if (cnt[i] == 1) {
			for (int x = allSak[i].minP.x; x <= allSak[i].maxP.x; x++) {
				for (int y = allSak[i].minP.y; y <= allSak[i].maxP.y; y++) {
					if (A[y][x]-'0' != i) {
						cnt2[A[y][x] - '0'] = 0;
					}
				}
			}
		}
	}
}

int solve() {
	int ans = 0;
	for (int i = 1; i <= 9; i++) {
		if (cnt2[i] == 1)
			ans++;
	}
	return ans;
}

int main() {
	int ans = -1;
	InputData();//	입력 함수
	IntiSak();
	SaveSak();
	CalcSak();
	ans = solve();
//	PrintSak();
	//	코드를 작성하세요

	cout << ans << endl;//출력
	return 0;
}
