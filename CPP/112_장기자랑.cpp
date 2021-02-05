#include <iostream>
#define MaxN 10000+10
using namespace std;

int N;//직원 수
int S;//시작 직원 번호
int M;


int sol[MaxN];


struct List {
	int a=0;
	List* p=NULL;
};

List myList[MaxN];
List* start;

void solve() {

	for (int i = 1; i <= N; i++) {
		myList[i].a = i;
		if(i==N)
			myList[i].p = &myList[1];
		else
			myList[i].p = &myList[i+1];
		if (i == S)
			start = &myList[i];
	}
	for (int i = 0; i < N; i++) {
		
		for (int j = 1; j < M-1 ; j++) {
			//if (i == 0 && j == 1)
			//	continue;
			start = start->p;
		}
		cout<< start->p->a <<" ";
		start->p = start->p->p;
		start = start->p;
	}
	
}


void InputData() {
	cin >> N >> S >> M;
}
int main() {

	InputData();//	입력 함수
	solve();
	//	코드를 작성하세요


	return 0;
}