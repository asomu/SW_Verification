#include <iostream>
#include <cstring>
using namespace std;

int N;//후보자수
char str[10000 + 10][20 + 10];//후보자 이름
int M;//투표참가인원
char name[100000 + 10][20 + 10];//투표용지에 써있는 이름
int score[100000 + 10];//점수
int sum[10000 + 10];
#define MAXHASH (1 << 14)
#define MOD (MAXHASH -1)




int calhash(char* str){
    int hash = 5381, c;
    while(c = *str++){
        hash = (((hash<<4)+hash) + c) % MAXHASH;
    }
    return hash;
}

int IDkey;

struct HT{
    int hkey; int id; char* org;
    HT(){hkey=id=0; org = NULL;}
    HT(int nid, int nk, char* str){hkey=nk;id=nid;org=str;}
};

HT htbl[MAXHASH];

void insertkey(char* str){
    int i, hkey=calhash(str), idx = hkey;
    for(i=0;i<MAXHASH;i++){
        if(htbl[idx].id == 0){
            htbl[idx] = HT(++IDkey, hkey, str);
            break;
        }
        idx = (idx + 13) & MOD;
    }
}

int getkey(char* str){
    int i, hkey =calhash(str), idx = hkey;
    for(i=0; i< MAXHASH; i++){
        if(htbl[i].id == 0){
            return 0;
        }
        else if((strcmp(htbl[idx].org, str) == 0) && (htbl[idx].hkey == hkey) ){
            return htbl[idx].id;
        }
        idx = (idx+13) & MOD;
    }
    return 0;
}

void solve(){
    int key , i;
    for(i=0;i<N;i++){
        insertkey(str[i]);
    }
    for(i=0;i<M;i++){
        key = getkey(name[i]);
        if(key)
        {
            sum[key] += score[i];
        }
         
    }
}

void OutPutData(){
    int i, j, max, maxid;
    for(i=1;i<3;i++){
        max =0;
        maxid = 0;
        for(j=1;j<=N;j++){
            if(max<sum[j]){
                max = sum[j];
                maxid = j;
            }
          

        }
        cout << str[maxid-1]<< " " << max << endl;
        sum[maxid] = 0;
    }
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

int main(){
	InputData();//	입력 함수
    solve();
    OutPutData();
	//	코드를 작성하세요

	return 0;
}
