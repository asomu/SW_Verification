import java.util.Scanner;

public class Main {
	int N;//필터의 수
	int R[]=new int [11]; //반사의 정도
	int P[]=new int [11]; //투과의 정도
	static int sol = 0x7FFFFFFF;
	static int diff = 0x7FFFFFFF;
	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int i = 1; i <= N; i++) {
			R[i] = sc.nextInt();
			P[i] = sc.nextInt();
		}
		sc.close();
	}

	void Dfs(int n, int r, int p, int cnt){
		int val = Math.abs(r - p);
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

	public static void main(String[] args){
		Main m = new Main();

		m.InputData();	 //	입력 함수

		//	코드를 작성하세요
		m.Dfs(1,1,0,0);
		System.out.println(m.N-sol);//출력
	}
}