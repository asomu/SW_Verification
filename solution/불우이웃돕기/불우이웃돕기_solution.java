import java.util.Scanner;

public class Main {
	int N;//보내려는 물품 개수
	int C[] = new int[10];//BOX 개수(1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 순)
	int sol[] = new int[10];//보내는 BOX 개수

	int num[] = {1, 5, 10, 50, 100, 500, 1000, 3000, 6000, 12000 };
	int solve(){
		int sum = 0, i, cnt, totalcnt = 0;
		for(i = 0; i < 10; i++){
			sum += num[i] * C[i];
		}
		sum -= N;

		for(i = 9; i >= 0; i--){
			cnt = sum / num[i];
			if(cnt > C[i]) cnt = C[i];
			sum -= num[i] * cnt;
			sol[i] = C[i] - cnt;
			totalcnt += sol[i];
		}
		return totalcnt;
	}

	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for(int i = 0; i < 10; i++){
			C[i] = sc.nextInt();
		}
	}
	void OutputData(int ans){
		System.out.println(ans);
		for(int i = 0; i < 10; i++){
			System.out.print(sol[i] + " ");
		}
		System.out.println();
	}
	public static void main(String[] args) {
		int ans = -1;
		Main m = new Main();
		m.InputData();//입력 함수
		
		//	코드를 작성하세요
		ans = m.solve();
		
		m.OutputData(ans);//	출력 함수
	}
}