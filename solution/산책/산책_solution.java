import java.util.Scanner;

public class Main {
	int N;//직원 수
	int T;//산책 시간(분단위)
	int P[] = new int[100000 + 10];//직원 출발 위치
	int S[] = new int[100000 + 10];//직원 산책 속도(분당)
	
	long stack[] = new long[100000 + 10];

	public void inputData()  {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		T = sc.nextInt();
		for (int i = 0; i < N; i++) {
			P[i] = sc.nextInt();
			S[i] = sc.nextInt();
		}
	}
	
	public int solve(){
		int i, sp = 0;
		long pos;
		for(i = 0; i < N; i++){
			pos = P[i] + (long)T * S[i];
			for( ; (sp > 0) && (stack[sp] >= pos) ; sp--);
			stack[++sp] = pos;
		}
		return sp;
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