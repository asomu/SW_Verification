#include <stdio.h>

int N;//정사각형 지도 크기
int X, Y;//수돗물 공급되는 시작 좌표, 가로, 세로
int map[20][20];//지도 정보

//방문순서 상하좌우
int A[][4] = {	{0,0,0,0},//0
				{0,0,1,1},//1
				{1,1,0,0},//2
				{0,1,0,1},//3
				{0,1,1,0},//4
				{1,0,1,0},//5
				{1,0,0,1},//6
				{1,1,0,1},//7
				{0,1,1,1},//8
				{1,1,1,0},//9
				{1,0,1,1},//10
				{1,1,1,1}};//11
int dir[] = {1, 0, 3, 2};
int rr[] = {-1, 1, 0, 0};
int cc[] = {0, 0, -1, 1};
int visit[20][20];
int pipe;

void Input_Data(void){
	int i, j;
	scanf("%d", &N);
	scanf("%d %d", &X, &Y);
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
			scanf("%1x", &map[i][j]);
		}
	}
}

void Flood_Fill(int r, int c){
	int i, nr, nc;

	visit[r][c]=1;//방문표시
	pipe--;//확산왔으므로 파이프제거

	for(i=0 ; i<4 ; i++){
		nr = r + rr[i]; nc = c + cc[i];
		if((nr<0) || (nr>=N) || (nc<0) || (nr>=N)) continue;//범위 벗어남
		if(visit[nr][nc] == 1) continue;//이미 방문했으므로 skip
		if((A[map[r][c]][i] == 1) && (A[map[nr][nc]][dir[i]] == 1)){//방문가능
			Flood_Fill(nr, nc);
		}
	}
}

int solve(){
	int i, j;
	pipe = 0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(map[i][j] != 0) pipe++;//파이프 개수 파악
		}
	}

	Flood_Fill(Y, X);
	return pipe;
}

int main(void){
	int ans = -1;
	Input_Data();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}