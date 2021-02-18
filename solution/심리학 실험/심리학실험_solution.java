import java.util.Scanner;

public class Main {
	int N;//후보자 수
	int []A = new int[100000 + 10];//기질 값
	Scanner sc;
	void InputData(){
		sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int i = 0; i < N; i++) A[i] = sc.nextInt();
	}

	int ABS(int x){ return (x < 0) ? -x : x; }

	void solve(){
		int i = 0, j = N - 1, minsum = (int)(2e9 + 10), sum, minans = 0, maxans = 0;
		while (i < j){
			sum = A[i] + A[j];
			if (minsum > ABS(sum)){
				minsum = ABS(sum); minans = i; maxans = j;
			}
			if (sum > 0) j--;
			else if (sum < 0) i++;
			else break;
		}
		System.out.println(minans + " " + maxans);
	}

	public static void main(String[] args){
		Main m = new Main();

		m.InputData();				//	입력 함수

		//	코드를 작성하세요
		m.solve();
	}
}