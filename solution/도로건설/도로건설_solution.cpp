#include <iostream>
using namespace std;

int N;//지도 크기
char map[110][110];//지도 정보

#define IMP (1<<29)
struct Q{
	int r, c;
};
Q queue[100*100*100];
int wp, rp;
int visit[110][110];

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

int BFS(){
	int rr[] = {-1, 1, 0, 0};
	int cc[] = {0, 0, -1, 1};

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visit[i][j] = IMP;
		}
	}
	wp = rp = 0;
	queue[wp].r=0; queue[wp++].c=0;
	visit[0][0] = 0;

	while(rp < wp){
		Q d = queue[rp++];
		for(int i=0;i<4;i++){
			int nr = d.r + rr[i]; int nc = d.c + cc[i];
			if((nr<0)||(nr>=N)||(nc<0)||(nc>=N)) continue;//범위 벗어남
			if(visit[nr][nc] > visit[d.r][d.c] + map[nr][nc] - '0'){
				visit[nr][nc] = visit[d.r][d.c] + map[nr][nc] - '0';
				queue[wp].r = nr; queue[wp++].c = nc;
			}
		}
	}
	return visit[N-1][N-1];
}

int main(){
	int ans = -1;
	Input_Data();
	ans = BFS();
	cout << ans << endl;
	return 0;
}