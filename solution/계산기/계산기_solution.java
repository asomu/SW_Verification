import java.util.Scanner;

public class Main {

	int N;//테스트 케이스 수
	int B;//진법
	char S[];//첫 번째 정수
	char D[];//두 번째 정수
	Scanner sc;
	char d2c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
	int c2d(char ch){
		if(ch <= '9') return ch - '0';
		return ch - 'A' + 10;
	}
	void mul(int s, int d){
		int alen = S.length - s, blen = D.length - d, len = alen + blen - 1, i, j;
		int AA[] = new int[alen], BB[] = new int[blen], sol[] =  new int[len];
		
		for(i = 0, j = s; i < alen; i++, j++) AA[i] = c2d(S[j]);
		for(i = 0, j = d; i < blen; i++, j++) BB[i] = c2d(D[j]);
		
		for(i = 0; i < alen; i++){
			for(j = 0; j < blen; j++){
				sol[i + j] += AA[i] * BB[j];
			}
		}
		for(i = len - 1; i > 0; i--){
			if(sol[i] >= B){
				sol[i - 1] += sol[i] / B; sol[i] %= B;
			}
		}
		if(sol[0] >= B){
			System.out.print(d2c[sol[0] / B]); sol[0] %= B;
		}
		for(i = 0; i < len; i++) System.out.print(d2c[sol[i]]);
		System.out.println();
	}
	void solve(){
		if((S[0] == '0') || (D[0] == '0')) {
			System.out.println("0"); return;
		}
		int sign = 1; int s = 0, d = 0;
		if(S[0] == '-'){ sign *= -1; s++; }
		if(D[0] == '-'){ sign *= -1; d++; }
		if(sign < 0) System.out.print("-");
		mul(s, d);
	}

	void InputData(){
	    B = sc.nextInt();
		S = sc.next().toCharArray();
		D = sc.next().toCharArray();
	}

	public static void main(String[] args){
		Main m = new Main();
		m.sc = new Scanner(System.in);
		m.N = m.sc.nextInt();
		for(int i = 0; i < m.N; i++){
			m.InputData();				//	입력 함수

			//	코드를 작성하세요
			m.solve();
		}
	}
}