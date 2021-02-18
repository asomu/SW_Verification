import java.util.Scanner;

public class Main {
	int N;//LED 수
	int S[] = new int[100000 + 10];//LED 상태
	
	int pat[] = new int[100000 + 10];//초기 ON/OFF 패턴 개수 

	public void inputData()  {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		
		for (int i = 0; i < N; i++) {
			S[i] = sc.nextInt();
		}
	}
	
	public int solve(){
		int i, max = 0, cnt = 0, seq = 1;
		for(i = 1; i < N; i++){
			if(S[i] != S[i - 1]) seq++;
			else{
				pat[cnt++] = seq;
				seq = 1;
			}
		}
		pat[cnt++] = seq;
		
		if(cnt < 2){
			for(i = 0; i < cnt; i++) max += pat[i];
		}
		else{
			max = pat[0] + pat[1] + pat[2];
			seq = pat[1] + pat[2];
			for(i = 3; i < cnt; i++){
				seq += pat[i];
				if(max < seq) max = seq;
				seq -= pat[i - 2];
			}
		}
		return max;
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