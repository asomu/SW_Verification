#include <stdio.h>

int N;//제품 수
struct st{
	int X, ID;//위치, 아이디
};
struct st A[50010];

struct st tmp[50010];
int nid[50010];
int check[50010];
int max_id_cnt;

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++){
		scanf("%d %d", &A[i].X, &A[i].ID);
	}
}

void new_id(void){
	int i, j, ni;
	for(i=0;i<N;i++){
		ni = A[i].ID % 50000;
		for(j=0;j<50000;j++){
			if(check[ni] == 0){
				max_id_cnt++;
				check[ni] = A[i].ID;
				A[i].ID = ni;
				break;
			}
			else if(check[ni] == A[i].ID){
				A[i].ID = ni;
				break;
			}
			ni = (ni + 1) % 50000;
		}
	}
}

void sort(int s, int e){
	int i=s,k=s,m=(s+e)/2, j=m+1;
	if(s >= e) return;
	sort(s, m); sort(j, e);
	while((i<=m) && (j<=e)){
		if(A[i].X > A[j].X) tmp[k++] = A[j++];
		else tmp[k++] = A[i++];
	}
	while(i<=m) tmp[k++] = A[i++];
	while(j<=e) tmp[k++] = A[j++];
	for(i=s;i<=e;i++) A[i] = tmp[i];
}

int solve(void){
	int i, j, cnt = 0, min = 1<<30;
	new_id();
	sort(0, N-1);
	for(i=0;i<50000;i++) check[i] = 0;
	i=j=0;
	for(;;){
		while((i<N) && (max_id_cnt > cnt)){
			if(check[A[i].ID]++ == 0) cnt++;
			i++;
		}
		if(max_id_cnt != cnt) break;
		while(check[A[j].ID]>1){
			check[A[j].ID]--; j++;
		}
		if(min > A[i-1].X - A[j].X) min = A[i-1].X - A[j].X;
		cnt--; check[A[j].ID]=0; j++;
	}
	return min;
}

int main(void){
	int ans = -1;
	Input_Data();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}
