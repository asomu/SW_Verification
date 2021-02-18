import java.util.Scanner;

public class Main {
	int N;//도화지 크기
	char A[][] = new char[10 + 2][10 + 2];//도화지 색정보
	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int i = 0; i < N; i++) A[i] = sc.next().toCharArray();
		sc.close();
	}
	
	int Solve(){
		int i, r, c, minr, minc, maxr, maxc, cnt = 0;
		int check[][] = new int[10 + 2][10 + 2];
		for (i = '1'; i <= '9'; i++){
			//i번색 상하좌우 찾기
			minr = minc = 10;
			maxr = maxc = 0;
			for (r = 0; r < N; r++){
				for (c = 0; c < N; c++){
					if (A[r][c] != i) continue;
					if (minr > r) minr = r;
					if (maxr < r) maxr = r;
					if (minc > c) minc = c;
					if (maxc < c) maxc = c;
				}
			}
			if (minr == 10) continue;//해당 색 없음
			for (r = minr; r <= maxr; r++){
				for (c = minc; c <= maxc; c++){
					check[r][c]++;
				}
			}
		}
		for (r = 0; r < N; r++){
			for (c = 0; c < N; c++){
				if(cnt < check[r][c]) cnt = check[r][c];
			}
		}
		return cnt;
	}

	public static void main(String[] args){
		int ans = -1;
		Main m = new Main();

		m.InputData();				//	입력 함수

		ans = m.Solve();//	코드를 작성하세요

		System.out.println(ans);//출력
	}
}