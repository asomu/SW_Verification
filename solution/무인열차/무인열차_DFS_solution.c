#include <stdio.h>

int N; // ����ũ��
int M; // ����ũ��
int map[50 + 10][50 + 10]; // ���� ������

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
int Solve(void)
{
	int i, j, temp, ans = 0x7FFFFFFF;
	int point = 0;
    int cnt[2];

	for (i = 1; i <= N; i++){
        for (j = 1; j <= M; j++){
            if (map[i][j] == 1){
                count = 0;
                Fill(i, j, point);
                cnt[point] = count;
                point++;
            }
        }
    }
    for (i = 0; i < cnt[0]; i++){
        for (j = 0; j < cnt[1]; j++){
            temp = ABS(dat[0][i].r - dat[1][j].r) + ABS(dat[0][i].c - dat[1][j].c);
            if (temp < ans) ans = temp;
        }
    }
    return ans - 1;
}

void InputData(void){
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++){
		for (j = 1; j <= M; j++){
			scanf("%d", &map[i][j]);
		}
	}
}

int main(void){
	int ans;
	
	InputData(); // �Է��Լ�
	
	// �ڵ带 �ۼ� �ϼ���
	ans = Solve();
    printf("%d", ans);
    return 0;
}