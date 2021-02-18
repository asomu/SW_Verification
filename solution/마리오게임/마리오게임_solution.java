import java.util.Scanner;

public class Main {
	int N;//버섯 수
	int P[] = new int[150000 + 10];//버섯 값

	public void inputData()  {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			P[i] = sc.nextInt();
		}
	}
	
	public int solve(){
		int sum = P[0];
		for(int i = 1; i < N; i++){
			if(P[i - 1] < P[i]) sum = sum - P[i - 1] + P[i];
		}
		return sum;
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