#include <iostream>
using namespace std;

int N; // 세로크기
int M; // 가로크기
int map[50 + 10][50 + 10]; // 사진 데이터

struct st
{
    int r, c;
}dat[2][50*50];
int count;
int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};

#define ABS(a) (((a)<0) ? -(a) : (a))

void Fill(int r, int c, int p){
	int i;
    if (map[r][c] != 1) return;
    map[r][c] = 0;
    dat[p][count].r = r;
    dat[p][count].c = c;
    count++;
	for(i=0; i<4; i++) Fill(r+dr[i], c+dc[i], p);
}

int Solve(void){
	int ans = 0x7FFFFFFF;
	int point = 0;
    int cnt[2];

	for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if (map[i][j] == 1){
                count = 0;
                Fill(i, j, point);
                cnt[point] = count;
                point++;
            }
        }
    }
    for (int i = 0; i < cnt[0]; i++){
        for (int j = 0; j < cnt[1]; j++){
            int temp = ABS(dat[0][i].r - dat[1][j].r) + ABS(dat[0][i].c - dat[1][j].c);
            if (temp < ans) ans = temp;
        }
    }
    return ans - 1;
}

void InputData(void){
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> map[i][j];
		}
	}
 
}
int main(void){
	
	InputData();	// 입력함수
	
	// 코드를 작성 하세요

	int ans = Solve();
    cout << ans << endl;
    return 0;
}