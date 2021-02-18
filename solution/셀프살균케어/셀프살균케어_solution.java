import java.util.Scanner;

public class Main {

	int []y;			//	살균대상의 y 좌표 배열
	int []x;			//	살균대상의 x 좌표 배열
	int N;			//	필터 한 변의 크기
	int L;			//	LED의 범위(길이) 
	int M;			//	살균대상의 개수

	public int MIN(int x, int y){
		if(x<y) return x;
		return y;
	}
	
	public int solve() {
		int sol=0;
		for (int h = 1; h < L / 2; h++){		//	세로길의의 범위 루프
			int w = L / 2 - h;							//	세로길이에 따른 가로길이 연산
			for (int i = 0; i < M; i++){			//	가능한 살균대상의 모든 조합
				for (int j = i; j < M; j++){
					int t = 0;
					int si = MIN(y[i], y[j]);		//	살균범위의 시작 y, x좌표 계산
					int sj = MIN(x[i], x[j]);
					for (int k = 0; k < M; k++){
						//	살균범위내에 살균대상이 있을경우 카운트 증가)
						if (si <= y[k] && y[k] <= si + h && sj <= x[k] && x[k] <= sj + w)   t++;
					}
					if (sol < t) sol = t;			//	현재 최대값보다 클 경우 정답 갱신
				}
			}
		}
		return sol;
	}

	public void inputData()  {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();			//	필터 한 변의 크기
		L = sc.nextInt();				//	LED의 범위(길이) 
		M = sc.nextInt();			//	살균대상의 개수
		y = new int [M+1];		
		x = new int [M+1];		

		for(int i=0 ; i<M ; i++){
			y[i] = sc.nextInt();		
			x[i] = sc.nextInt();		
		}
	}

	public static void main(String[] args){
		Main m = new Main();

		m.inputData();					//	입력 함수
		int sol = m.solve();			//	문제 풀이
		System.out.println(sol);	//	정답 출력
	}
}