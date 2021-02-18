import java.util.Scanner;

public class Main {
	int N;//제품 수
	public class st{
		int X, ID;
		st(int X, int ID){
			this.X=X; this.ID=ID;
		}
	}
	st A[] = new st[50010];
	
	st tmp[] = new st[50010];
	int nid[] = new int[50010];
	int check[] = new int[50010];
	int max_id_cnt;

	public void inputData()  {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		
		for (int i = 0; i < N; i++) {
			int X = sc.nextInt();
			int ID = sc.nextInt();
			A[i] = new st(X, ID);
		}
	}
	
	public void new_id(){
		for(int i=0;i<N;i++){
			int ni = A[i].ID % 50000;
			for(int j=0;j<50000;j++){
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
	
	public void sort(int s, int e){
		if(s >= e) return;
		int i=s,k=s,m=(s+e)/2, j=m+1;
		sort(s, m); sort(j, e);
		while((i<=m) && (j<=e)){
			if(A[i].X > A[j].X) tmp[k++] = A[j++];
			else tmp[k++] = A[i++];
		}
		while(i<=m) tmp[k++] = A[i++];
		while(j<=e) tmp[k++] = A[j++];
		for(i=s;i<=e;i++) A[i] = tmp[i];
	}
	
	public int solve(){
		int i, j, cnt = 0, min = Integer.MAX_VALUE;
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

	public static void main(String[] args){
		Main m = new Main();
		int ans = -1;

		m.inputData();				//	입력 함수

		//	코드를 작성하세요
		ans = m.solve();
	
		System.out.println(ans);	//	정답 출력
	}
}