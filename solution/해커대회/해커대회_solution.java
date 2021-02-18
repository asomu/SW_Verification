import java.util.Scanner;

public class Main {
	char str[];//초기 문자열
	char cmd[];//명령어 문자열
	class NODE{
	    char ch; NODE prev, next;
	    NODE() { ch = 0; prev = next = null; }
	    NODE(char nc, NODE p){//뒤에서 앞에 삽입
	        ch = nc; next = p; prev = p.prev; prev.next = this;
	    }
	    void selfdel(){
	        prev.next = next; next.prev = prev;
	    }
	}
	class LINE{
	    NODE head, tail, cur;
	    LINE(){
	        head = new NODE(); cur = tail = new NODE(); head.next = tail; tail.prev = head;
	    }
	    void insert(char ch){
	        cur.prev = new NODE(ch, cur);
	    }
	    void left(){
	        if(cur.prev != head) cur = cur.prev;
	    }
	    void right(){
	        if (cur != tail) cur = cur.next;
	    }
	    void del(){
	        if (cur.prev != head) cur.prev.selfdel();
	    }
	    void PRT(){
			int i = 0; char [] sol = new char[600000 + 10];
	        for (cur = head.next; cur != tail; cur = cur.next) sol[i++] = cur.ch;
	        System.out.println(String.copyValueOf(sol, 0, i));
	    }
	}
	LINE line;
	Scanner sc;
	public static void main(String[] args) {
		Main m = new Main();
		m.InputData();
		m.solve();
		m.OutputData();
	}
	void InputData(){
		sc = new Scanner(System.in);
		str = sc.next().toCharArray();
		cmd = sc.next().toCharArray();
	}
	void OutputData(){
		line.PRT();
	}
	void solve(){
		line = new LINE();
		for (int i = 0; i < str.length; i++) line.insert(str[i]);

		for (int i = 0; i < cmd.length; i++){
			switch (cmd[i]){
			case 'B'://제거
	            line.del();
	            break;
	        case 'L'://커서 왼쪽으로 이동
	            line.left();
	            break;
	        case 'R'://커서 오른쪽으로 이동
	            line.right();
	            break;
	        default://삽입
	            line.insert(cmd[i]);
	        }
		}
	}
}