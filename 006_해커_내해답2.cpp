#include <iostream>
using namespace std;


char str[100000 + 10];//초기 문자열
char cmd[500000 + 10];//명령어 문자열
char print[1000000 + 10];//명령어 문자열

void InputData() {
	cin >> str;
	cin >> cmd;
}

struct Node {
	char n;
	Node* prv;
	Node* next;
};
auto head = new Node();
auto tail = new Node();
Node* cur = tail;

int cnt;

void push(char n) {
	auto newList = new Node;
	newList->n = n;
	newList->next = cur;
	newList->prv = cur->prv;
	cur->prv->next = newList;
	cur->prv = newList;
	cnt++;
}

void Left() {
	if(cur->prv != head)
		cur = cur->prv;
}

void Right() {
	if(cur!=tail)
		cur = cur->next;
}

void Delete() {
	auto tmp = cur->prv;
	tmp->prv->next = tmp->next;
	tmp->next->prv = tmp->prv;
	delete(tmp);
	cnt--;
}



void intiList() {
	for (int i = 0; str[i]; i++) {
		push(str[i]);
	}
}

void solve() {
	for (int i = 0; cmd[i]; i++) {
		auto tmp = cmd[i];
		if (tmp == 0)
			break;
		if (tmp == 'R')
			Right();
		else if (tmp == 'L')
			Left();
		else if (tmp == 'B')
			Delete();
		else
		{
			push(tmp);
		}

	}
	int i = 0;
	for (i=0; i<cnt; i++) {
		print[i] = head->n;
		head = head->next;
	}
	print[i] = 0;
	cout << print << endl;
}

int main() {
	InputData();//	입력 함수
	head->next = tail;
	tail->prv = head;
	//	코드를 작성하세요
	intiList();
	solve();
	return 0;
}
