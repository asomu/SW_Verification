#include <iostream>
#include <string>
#include <algorithm> 
#define MAXHASH 32768
#define MOD (MAXHASH - 1)

using namespace std;

int N;//후보자수

struct total {
	string name;
	int score = 0;
	int ID = 0;
	bool candidate = false;
};

total hashTable[MAXHASH];
total ht[100000 + 10];

int sum[MAXHASH];

int id;

//char str[10000 + 10][20 + 10];//후보자 이름
string str[10000 + 10];

int M;//투표참가인원
//char name[100000 + 10][20 + 10];//투표용지에 써있는 이름
string name[100000 + 10];
int score[100000 + 10];//점수

int calhash(string str) {
	int hash = 5381, c;
	int i = 0;

	while (c = str[i++]) {
		hash = ((hash<<5) + c ) % MAXHASH;

	}
	return hash;
}

int calhash2(string str) {
	int hash = 5381, c;
	int i = 0;
	while (c = str[i++]) hash = (((hash << 5) + hash) + c) % MAXHASH;
	return hash;
}

void setKey(string str) {
	int idx = calhash(str);
	for (int i = 0; i < MAXHASH; i++) {
		if (hashTable[idx].candidate == false) {
			hashTable[idx].candidate = true;
			hashTable[idx].ID = id++;
			hashTable[idx].name = str;
			break;
		}
		idx = (idx + 14) % MAXHASH;
	}
}

void insertScore(string str, int score) {
	int idx = calhash(str);
	for (int i = 0; i < MAXHASH; i++) {
		if (hashTable[idx].candidate == false) {
			break;
		}
		else if (hashTable[idx].candidate == true && hashTable[idx].name == str) {
			hashTable[idx].candidate = true;
			hashTable[idx].score += score;
			break;
		}	
		idx = (idx + 14) % MAXHASH;
	}
}

total getTotal(string str) {
	int idx = calhash(str);
	for (int i = 0; i < MAXHASH; i++) {
		if (hashTable[idx].candidate == true && hashTable[idx].name == str) {		
			return hashTable[idx];
			break;
		}
		idx = (idx + 14) % MAXHASH;
	}
}

int getKey(string str) {
	int idx = calhash(str);
	for (int i = 0; i < MAXHASH; i++) {
		if (hashTable[idx].candidate == true && hashTable[idx].name == str) {
			return hashTable[idx].ID;
		}
		else if (hashTable[idx].candidate == false)
			return -1;
		idx = (idx + 14) % MAXHASH;
	}
	return -1;
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

bool comp(total a, total b) {
	bool result = true;
	if (a.score > b.score)
		result = true;
	else if (a.score == b.score) {
		if (a.ID < b.ID)
			result = true;
		else
			result = false;
	}
	else
		result = false;
	return result;
	
}

void solve() {
	int key;
	for (int i = 0; i < N; i++) {
		setKey(str[i]);
	}
	for (int j = 0; j < M; j++) {
		insertScore(name[j], score[j]);	
	}
	for (int i = 0; i < N; i++) {
		ht[i] = getTotal(str[i]);
	}
	sort(ht, ht + M, comp);
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

int main() {
	InputData();//	입력 함수

	//	코드를 작성하세요
	solve();
//	output();
	for (int i = 0; i < 3; i++) {
		cout << ht[i].name << " " << ht[i].score << endl;
	}
	

	return 0;
}
