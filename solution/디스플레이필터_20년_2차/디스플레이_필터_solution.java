import java.util.Scanner;

public class Main {
	int N;//������ ��
	int R[]=new int [11]; //�ݻ��� ����
	int P[]=new int [11]; //������ ����
	static int sol = 0x7FFFFFFF;
	static int diff = 0x7FFFFFFF;
	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int i = 1; i <= N; i++) {
			R[i] = sc.nextInt();
			P[i] = sc.nextInt();
		}
		sc.close();
	}

	void Dfs(int n, int r, int p, int cnt){
		int val = Math.abs(r - p);
		if (n > N) {
			if (cnt == 0) return;
			if (val < diff)
			{
				diff = val;
				sol = cnt;
			}
			else if (diff == val)
			{
				if (sol>cnt) sol = cnt;
			}
			return;
		}
		Dfs(n+1, r*R[n], p+P[n], cnt+1);
		Dfs(n+1, r, p, cnt);
	}

	public static void main(String[] args){
		Main m = new Main();

		m.InputData();	 //	�Է� �Լ�

		//	�ڵ带 �ۼ��ϼ���
		m.Dfs(1,1,0,0);
		System.out.println(m.N-sol);//���
	}
}