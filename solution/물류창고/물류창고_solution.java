import java.util.Scanner;

public class Main {
	int N, M;//공장 수, 도로 정보 수
	int A[], B[], D[];//공장 A, 공장 B, 거리 D

	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); M = sc.nextInt();
		A = new int[M]; B = new int[M]; D = new int[M];
		for (int i = 0; i < M; i++){
			A[i] = sc.nextInt(); B[i] = sc.nextInt(); D[i] = sc.nextInt();
		}
	}

	int IMP = (100 * 100 + 10);
	int MAXQ = (100 * 100 * 100);
	int dist[][];
	int visit[];
	int queue[];
	int wp, rp;
	void push(int n, int t){
		if(visit[n] <= t) return;
		visit[n] = t; queue[wp++] = n;
	}
	int front(){ return queue[rp];}
	void pop() { rp++;}
	boolean empty() {return wp == rp;}
	int BFS(int s){
		int i, tmp,  max = 0;
		for (i = 1; i <= N; i++) visit[i] = IMP;
		wp = rp =0;
		push(s, 0);
		while(!empty()){
			tmp = front(); pop();
			for(i = 1; i <= N; i++){
				push(i, visit[tmp] + dist[tmp][i]);
			}
		}
		for (i = 1; i <= N; i++) if(max < visit[i]) max = visit[i];
		return max;
	}
	int solve(){
		int i, j, sol = IMP, ret;
		dist = new int[N + 10][N + 10]; visit = new int[N + 10]; queue = new int[MAXQ];
		for(i = 1; i <= N; i++){
			for(j = 1; j <= N; j++){
				dist[i][j] = IMP;
			}
		}
		for (i = 0; i < M; i++) dist[A[i]][B[i]] = dist[B[i]][A[i]] = D[i];
		for(i = 1; i <= N; i++){
			ret = BFS(i);
			if(sol > ret) sol = ret;
		}
		return sol;
	}

	public static void main(String[] args){
		Main m = new Main();
		int ans = -1;

		m.InputData();				//	입력 함수

		//	코드를 작성하세요
		ans = m.solve();
	
		System.out.println(ans);	//	정답 출력
	}
}