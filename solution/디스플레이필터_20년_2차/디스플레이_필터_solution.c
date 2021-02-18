#include <stdio.h>

int N;	// ������ ��
int R[11]; // �ݻ��� ����
int P[11]; // ������ ����
int sol = 11;
int diff = 0x7FFFFFFF;

int ABS(int num){
	return (num < 0) ? -num : num;
}

void InputData(void){
	int i;
	scanf("%d", &N);
	for(i=1; i<=N; i++)  scanf("%d %d", &R[i], &P[i]);
}

void Dfs(int n, int r, int p, int cnt){
	int val = ABS(r - p);
	if (n > N) {
		if (cnt == 0) return;
		if (val < diff)
		{
			diff = val;
			sol = cnt;
		}
		else if (diff == val)
		{
			if (sol>cnt) sol = cnt;
		}
		return;
	}
	Dfs(n+1, r*R[n], p+P[n], cnt+1); 
	Dfs(n+1, r, p, cnt);
}
int main(){

	InputData(); // �Է��Լ�
	
	// �ڵ带 �ۼ� �ϼ���
	Dfs(1, 1, 0, 0);
	printf("%d", N - sol);
	return 0;
}

