import java.util.Scanner;

public class Main {
	int N;//직원 수
	int S;//시작 직원 번호
	int M;

	int MAXQ = (1 << 16);
	int MOD = (MAXQ - 1);
	int queue[] = new int[MAXQ];
	int wp, rp;
	void push(int n) { queue[wp] = n; wp = (wp + 1) & MOD; }
	int front() { return queue[rp]; }
	void pop() { rp = (rp + 1) & MOD; }
	boolean empty() { return wp == rp; }
	void solve(){
		int i, j = S;
		for(i = 1; i <= N; i++){
			push(j); if(++j > N) j = 1;
		}
		for(i = 1; i <= N; i++){
			for(j = 1; j < M; j++){
				push(front()); pop();
			}
			System.out.print(front() + " "); pop();
		}
		System.out.println();
	}

	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); S = sc.nextInt(); M = sc.nextInt();
	}
	
	public static void main(String[] args) {
		Main m = new Main();
		m.InputData();//입력 함수
		
		//	코드를 작성하세요
		m.solve();

	}
}