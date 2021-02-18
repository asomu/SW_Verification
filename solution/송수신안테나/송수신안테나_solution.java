import java.util.Scanner;

public class Main {
	int N;//송수신 안테나 수
	int H[] = new int[100000 + 10];//송수신 안테나 높이
	
	int stack[] = new int[100000 + 10];
	int sp;
	void push(int h){
		stack[++sp] = h;
	}
	void pop(){
		sp--;
	}
	int top(){
		return stack[sp];
	}
	int size(){
		return sp;
	}
	boolean empty(){
		return sp == 0;
	}
	
	void InputData(){
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			H[i] = sc.nextInt();
		}
		sc.close();
	}

	int Solve(){
		int cnt = 0;
		int i;
		for (i = 0; i < N; i++){
			while (!empty() && (top() < H[i])){
				cnt++;
				pop();
			}
			if (!empty()) {
				cnt++;
				if (top() == H[i]) pop();
			}
			push(H[i]);
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