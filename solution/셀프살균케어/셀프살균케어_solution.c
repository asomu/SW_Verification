#include <stdio.h>
#define MIN(x,y) ((x)<(y)?(x):(y))
int y[110];		//	살균대상의 y 좌표 배열
int x[110];		//	살균대상의 x 좌표 배열
int N;				//	필터 한 변의 크기
int L;				//	LED의 범위(길이) 
int M;				//	살균대상의 개수
int sol;			//	정답

int main(void){
	int i, j, k, si, sj, t, h, w;

	//	입력
	scanf("%d %d %d", &N, &L, &M);
	for (i = 0; i < M; i++){
		scanf("%d %d", &y[i], &x[i]);
	}

	for (h = 1; h < L / 2; h++){		//	세로길의의 범위 루프
		w = L / 2 - h;							//	세로길이에 따른 가로길이 연산
		for (i = 0; i < M; i++){			//	가능한 살균대상의 모든 조합
			for (j = i; j < M; j++){
				t = 0;
				si = MIN(y[i], y[j]);		//	살균범위의 시작 y, x좌표 계산
				sj = MIN(x[i], x[j]);
				for (k = 0; k < M; k++){
					//	살균범위내에 살균대상이 있을경우 카운트 증가)
					if (si <= y[k] && y[k] <= si + h && sj <= x[k] && x[k] <= sj + w)   t++;
				}
				if (sol < t) sol = t;			//	현재 최대값보다 클 경우 정답 갱신
			}
		}
	}

	//	정답출력
	printf("%d", sol);
	return 0;
}