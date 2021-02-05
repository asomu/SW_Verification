#include <iostream>
#include <cstring>
#include <string>
//#define DEBUG

using namespace std;

int N;//후보자수
char str[10000 + 10][20 + 10];//후보자 이름
int sum[100000 + 10];

int M;//투표참가인원
char name[100000 + 10][20 + 10];//투표용지에 써있는 이름
int score[100000 + 10];//점수
int idxkey;

#define MAXHASH (1<<15) //32768
#define MOD (MAXHASH - 1)

int CalHash(const char* str) {
	int hash = 5318, c;
	while (c = *str++) {
		hash = (((hash << 5) + hash) + c) & MOD;
	}
	return hash;
}

struct HT {
	int hkey, id; char* str;
	HT() { hkey = id = 0; str = NULL; }
	HT(int nk, int nidx, char* name) { hkey = nk; id = nidx; str = name; }
};

HT htbl[MAXHASH];

void insertkey(char* str) {
	int i, hkey, idx;
	hkey = CalHash(str);
	idx = hkey;
	for (i = 0; i < MAXHASH; i++) {
		if (htbl[idx].id == 0) {
			htbl[idx] = HT(hkey, idxkey++, str);
			break;
		}								
		idx = (idx + 14) & MOD;
	}	
}

int getKey(char* str) {
	int i, hkey, idx;
	hkey = CalHash(str);
	idx = hkey;
	for (i = 0; i < MAXHASH; i++) {
		if ((htbl[idx].hkey == hkey) && (strcmp(htbl[idx].str, str) == 0))
		{
			return htbl[idx].id;
		}
		else if (htbl[idx].id == 0)
			return -1;
		idx = (idx + 14) & MOD;
	}
	return -1;
}

void solve() {
	int i, key;
	for (i = 0; i < N; i++) {
		insertkey(str[i]);
	}
	for(i = 0; i < M; i++) {
		key = getKey(name[i]);
		if (key!=-1){
			sum[key] += score[i];
		}
	}
}

void output() {
	int i, j;
	for (i = 0; i < 3; i++) {
		int max = 0, maxid = 0;
		for (j = 0; j < N; j++) {
			if (max < sum[j]) {
				max = sum[j];
				maxid = j;
			}				
		}
		cout << str[maxid] << " " << max << endl;
		sum[maxid] = 0;
	}

}

void InputData() {
	int i;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> str[i];
	}
	cin >> M;
	for (i = 0; i < M; i++) {
		cin >> name[i] >> score[i];
	}
}

int main() {

	InputData();//	입력 함수
	solve();
	output();
	return 0;
}
