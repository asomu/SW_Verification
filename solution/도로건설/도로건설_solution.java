import java.util.Scanner;

public class Main {
	int N;//지도 크기
	char map[][] = new char [110][110];//지도 정보

	public void inputData()  {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			map[i] = sc.next().toCharArray();
		}
	}
	
	public class Q{
		int r, c;
		Q(int r, int c){
			this.r=r; this.c=c;
		}
	}
	Q queue[] = new Q[100*100*100];
	int wp, rp;
	int visit[][] = new int[110][110];
	
	public int BFS(){
		int rr[] = {-1, 1, 0, 0};
		int cc[] = {0, 0, -1, 1};
		
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				visit[i][j] = Integer.MAX_VALUE;
			}
		}
		wp = rp = 0;
		queue[wp++] = new Q(0, 0);
		visit[0][0] = 0;
		
		while(rp < wp){
			Q d = queue[rp++];
			for(int i=0;i<4;i++){
				int nr = d.r + rr[i]; int nc = d.c + cc[i];
				if((nr<0)||(nr>=N)||(nc<0)||(nc>=N)) continue;//범위 벗어남
				if(visit[nr][nc] > visit[d.r][d.c] + map[nr][nc] - '0'){
					visit[nr][nc] = visit[d.r][d.c] + map[nr][nc] - '0';
					queue[wp++] = new Q(nr, nc);
				}
			}
		}
		return visit[N-1][N-1];
	}

	public static void main(String[] args){
		long ans = -1;
		Main m = new Main();
		m.inputData();
		ans = m.BFS();
		System.out.println(ans);
	}
}