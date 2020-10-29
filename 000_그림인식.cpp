#include <iostream>
using namespace std;

int N;//도화지 크기
char A[10 + 2][10 + 2];//도화지 색정보
int map[10 + 2][10 + 2];
int info[10];
int cnt[10];
int flag[10];
struct Position {
	int x;
	int y;
};

Position color[10][100];

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
}

void Init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = A[i][j] - '0';
		}
	}
}

int solve() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			color[map[i][j]][cnt[map[i][j]]].y = i;
			color[map[i][j]][cnt[map[i][j]]].x = j;
			cnt[map[i][j]]++;
			flag[map[i][j]] = 1;
		}
	}
	for (int k = 1; k < 11; k++) {
		if (cnt[k] > 0) {
			for (int y = color[k][0].y; y <= color[k][cnt[k]-1].y; y++) {
				for (int x = color[k][0].x; x <= color[k][cnt[k]-1].x; x++) {
					if (map[y][x] != k) {
						flag[map[y][x]] = 0;
					}
				}
			}

		}
	}
	int temp = 0;
	for (int i = 1; i < 11; i++) {
		if (flag[i] > 0)
			temp++;
	}
	return temp;
}


int main() {
	int ans = -1;
	InputData();//	입력 함수
	Init();
	//	코드를 작성하세요
	ans = solve();
	cout << ans << endl;//출력
	return 0;
}
