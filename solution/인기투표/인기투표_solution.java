import java.util.Scanner;

public class Main {

	int N;//후보자수
	String str[];//후보자 이름
	int M;//투표참가인원
	String name[];//투표용지에 써있는 이름
	int score[];//점수

	int sum[];

	int MAXHASH = (1 << 17);
    int MOD = (MAXHASH - 1);
    
    int calhash(char []str){
        int hash = 5381; int i;
        for(i=0; i<str.length;i++) hash = (((hash << 5) + hash) + str[i]) & MOD;
        return hash;
    }
    
    void strcopy(char []dst, char []src){
        dst = new char[src.length];
        for(int i=0;i<src.length;i++) dst[i]=src[i];
    }
    
    int IDkey;
    
    class HT{
        int id; int hkey; String org;
        HT(){ id = hkey = 0; }
        HT(int nid, int nk, String str){ id = nid; hkey = nk; org = str; }
    };
    HT []htbl = new HT[MAXHASH];
    
    void insertkey(String str){//open addressing
        int i, hkey = calhash(str.toCharArray()), idx = hkey;
        for (i = 0; i < MAXHASH; i++){
            if (htbl[idx].id == 0){//새로운 문자열
                htbl[idx] = new HT(++IDkey, hkey, str); break;
            }
            idx = (idx + 13) & MOD;
        }
    }
    
    int getkey(String str){//open addressing
        int i, hkey = calhash(str.toCharArray()), idx = hkey;
        for (i = 0; i < MAXHASH; i++){
            if (htbl[idx].id == 0){//새로운 문자열
                return 0;
            }
            else if ((htbl[idx].hkey == hkey) && (str.compareTo(htbl[idx].org) == 0)){
                return htbl[idx].id;//이미 존재하는 문자열
            }
            idx = (idx + 13) & MOD;
        }
        return 0;//이런 경우 없음
    }

	void InputData(){
		Scanner sc = new Scanner(System.in);
	    N = sc.nextInt();sc.nextLine();
	    str = sc.nextLine().split(" ");
		M = sc.nextInt();
		name = new String[M]; score = new int[M];
	    for (int i = 0; i < M; i++){
	        name[i] = sc.next(); score[i] = sc.nextInt();
	    }
	}

	void solve(){
		int key, i;
		sum = new int[N + 10];
		for (i = 0; i < MAXHASH; i++) htbl[i] = new HT();
	    for (i = 0; i < N; i++){
	        insertkey(str[i]);
	    }
	    for (i = 0; i < M; i++){
			key = getkey(name[i]);
			if(key != 0) sum[key] += score[i];
	    }
	}

	void OutputData(){
	   int i, j, max, maxidx;
	   for(i = 0; i < 3; i++){
		   max = 0; maxidx = 0;
		   for(j = 1; j <= N; j++){
			   if(max < sum[j]){
				   max = sum[j]; maxidx = j;
			   }
		   }
		   System.out.println(str[maxidx - 1] + " " + max);
		   sum[maxidx] = 0;
	   }
	}

	public static void main(String[] args){
		Main m = new Main();

		m.InputData();				//	입력 함수

		//	코드를 작성하세요
		m.solve();
	
		m.OutputData();
	}
}