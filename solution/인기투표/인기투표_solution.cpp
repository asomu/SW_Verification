#include <iostream>
using namespace std;

int N;//후보자수
char str[10000 + 10][20 + 10];//후보자 이름
int M;//투표참가인원
char name[100000 + 10][20 + 10];//투표용지에 써있는 이름
int score[100000 + 10];//점수

int sum[10000 + 10];

#define MAXHASH (1 << 14)
#define MOD (MAXHASH - 1)

int strcompare(char *a, char *b){
    int i;
    for (i = 0; a[i] && b[i] && (a[i] == b[i]); i++);
    return a[i] - b[i];
}

int calhash(char *str){
    int hash = 5381, c;
    while (c = *str++) hash = (((hash << 5) + hash) + c) & MOD;
    return hash;
}

int IDkey;

struct HT{
    int id; int hkey; char *org;
    HT(){ id = hkey = 0; org = NULL; }
    HT(int nid, int nk, char *str){ id = nid; hkey = nk; org = str; }
};
HT htbl[MAXHASH];

void insertkey(char *str){//open addressing
    int i, hkey = calhash(str), idx = hkey;
    for (i = 0; i < MAXHASH; i++){
        if (htbl[idx].id == 0){//새로운 문자열
            htbl[idx] = HT(++IDkey, hkey, str); break;
        }
        idx = (idx + 13) & MOD;
    }
}

int getkey(char *str){//open addressing
    int i, hkey = calhash(str), idx = hkey;
    for (i = 0; i < MAXHASH; i++){
        if (htbl[idx].id == 0){//새로운 문자열
            return 0;
        }
        else if ((htbl[idx].hkey == hkey) && (strcompare(htbl[idx].org, str) == 0)){
            return htbl[idx].id;//이미 존재하는 문자열
        }
        idx = (idx + 13) & MOD;
    }
    return 0;//이런 경우 없음
}

void InputData(){
	int i;
    cin >> N;
    for (i = 0; i < N; i++){
        cin >> str[i];
    }
	cin >> M;
    for (i = 0; i < M; i++){
        cin >> name[i] >> score[i];
    }
}

void solve(){
	int key, i;
    for (i = 0; i < N; i++){
        insertkey(str[i]);
    }
    for (i = 0; i < M; i++){
		key = getkey(name[i]);
		if(key) sum[key] += score[i];
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
	   cout << str[maxidx - 1] << " " << max << endl;
	   sum[maxidx] = 0;
   }
}

int main(){
    InputData();//	입력 함수
    //	코드를 작성하세요
    solve();
    OutputData();
    return 0;
}
