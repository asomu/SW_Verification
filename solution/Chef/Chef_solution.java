import java.util.Scanner;

public class Main {
	int N;//손님 수
	int P[] = new int[10000 + 10];//음식 값
	int T[] = new int[10000 + 10];//예약 희망 시간
	int rev[] = new int[10000 + 10];//예약 확정 시간

	public void inputData()  {
		Scanner sc = new Scanner(System.in);
		
		N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			P[i] = sc.nextInt();
			T[i] = sc.nextInt();
		}
	}
	
	public int solve(){
		int i, j, price, temp, sum = 0;
		for(i = 0; i < N; i++){
			price = P[i];
			for(j = T[i]; j > 0; j--){
				if(rev[j] == 0){//예약 없음
					rev[j] = price;
					break;
				}
				else if(rev[j] < price){
					temp = price; price = rev[j]; rev[j] = temp;
				}
			}
		}
		for(i = 1; i <= 10000 ; i++){
			sum += rev[i];
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