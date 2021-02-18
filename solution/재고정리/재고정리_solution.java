import java.util.Scanner;

public class Main {
	int N;//제품 수
	int M;//제품 종류 수
	int ID[];//제품 ID

	int sum[][];
	int cnt[];
	boolean used[];
	int sol;
	void DFS(int n, int p, int m){
		if(sol <= m) return;//가지치기, 이미 이전 답보다 좋지 않음
		if(n > M){//완성, 종료 조건
			sol = m; return;
		}
		for(int i = 1; i <= M; i++){//제품 ID
			if(used[i]) continue;//이미 i번 제품은 정리 했음
			used[i] = true;
			int mcnt = cnt[i] - (sum[i][p + cnt[i] - 1] - sum[i][p - 1]);
			DFS(n + 1, p + cnt[i], m + mcnt);
			used[i] = false;
		}
	}
	int solve(){
		int i, j;
		sum = new int[M + 1][N + 10]; cnt = new int[M + 1]; used = new boolean[M + 1];
		for(i = 1; i <= N; i++) sum[ID[i]][i] = 1;
		for(i = 1; i <= M; i++){//ID 1~M
			for(j = 2; j <= N; j++) sum[i][j] += sum[i][j - 1];
			cnt[i] = sum[i][N];
		}
		sol = N;
		DFS(1, 1, 0);//순서, 놓을 첫 위치, 옮긴 수
		return sol;
	}

	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); M = sc.nextInt();
		ID = new int[N + 10];
		for(int i = 1; i <= N; i++){
			ID[i] = sc.nextInt();
		}
	}
	
	public static void main(String[] args) {
		int ans = -1;
		Main m = new Main();
		m.InputData();//입력 함수
		
		//	코드를 작성하세요
		ans = m.solve();
		
		System.out.println(ans);
	}
}