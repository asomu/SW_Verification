#include <iostream>
using namespace std;

int N;//도화지 크기
char A[10 + 2][10 + 2];//도화지 색정보

void InputData(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
}

int Solve(){
	int i, r, c, minr, minc, maxr, maxc, cnt = 0;
	int check[10 + 2][10 + 2] = {0};
	for (i = '1'; i <= '9'; i++){
		//i번색 상하좌우 찾기
		minr = minc = 10;
		maxr = maxc = 0;
		for (r = 0; r < N; r++){
			for (c = 0; c < N; c++){
				if (A[r][c] != i) continue;
				if (minr > r) minr = r;
				if (maxr < r) maxr = r;
				if (minc > c) minc = c;
				if (maxc < c) maxc = c;
			}
		}
		if (minr == 10) continue;//해당 색 없음
		for (r = minr; r <= maxr; r++){
			for (c = minc; c <= maxc; c++){
				check[r][c]++;
			}
		}
	}
	for (r = 0; r < N; r++){
		for (c = 0; c < N; c++){
			if(cnt < check[r][c]) cnt = check[r][c];
		}
	}
	return cnt;
}

int main(){
	int ans = -1;
    InputData();//	입력 함수

	ans = Solve();//	코드를 작성하세요
	
	cout << ans << endl;//출력
    return 0;
}
