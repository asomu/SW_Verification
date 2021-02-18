import java.util.Scanner;

public class Main {
	int N; // 세로크기
	int M; // 가로크기
	int map[][] = new int [50 + 10][50 + 10]; // 사진 데이터
	int count;
	class DATA{
        int r, c, t;
        DATA(int r, int c){
        	this.r=r; this.c=c;
        }
    }
	DATA dat[][] = new DATA[2][50*50];
	int dr[] = {0,0,1,-1};
	int dc[] = {1,-1,0,0};

	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		
		for (int i = 1; i<=N; i++){
			for (int j = 1; j<=M; j++){
				map[i][j]= sc.nextInt();
			}
		}
		sc.close();
	}
	void Fill(int r, int c, int p){
	    if (map[r][c] != 1) return;
	    map[r][c] = 0;
	    dat[p][count] = new DATA(r,c);
	    count++;
		for(int i=0; i<4; i++) Fill(r+dr[i], c+dc[i], p);
	}
	int Solve(){
		int ans = 0x7FFFFFFF;
		int point = 0;
	    int cnt[]=new int[2];

		for (int i = 1; i <= N; i++){
	        for (int j = 1; j <= M; j++){
	            if (map[i][j] == 1){
	                count = 0;
	                Fill(i, j, point);
	                cnt[point] = count;
	                point++;
	            }
	        }
	    }
	    for (int i = 0; i < cnt[0]; i++){
	        for (int j = 0; j < cnt[1]; j++){
	            int temp = Math.abs(dat[0][i].r - dat[1][j].r) + Math.abs(dat[0][i].c - dat[1][j].c);
	            if (temp < ans) ans = temp;
	        }
	    }
	    return ans - 1;
	}
	public static void main(String[] args){
		Main m = new Main();

		m.InputData();	 //	입력 함수

		//	코드를 작성하세요
		int ans = m.Solve();
		System.out.println(ans);
	}
}