#include <iostream>
using namespace std;


char str[100000 + 10];//초기 문자열
char cmd[500000 + 10];//명령어 문자열


void InputData() {
	cin >> str;
	cin >> cmd;
}

struct List {
	char n;
	List* prv;
	List* next;
};
List* head;
List* tail;
List* current;
int cnt;
void push_back(char n) {
	auto newList = new List;
	newList->n = n;
	if (cnt == 0) {
		newList->prv = newList;
		newList->next = newList;
		tail = newList;
		head = newList;
		cnt++;
	}
	else {
		newList->prv = tail;
		newList->next = newList;
		tail->next = newList;
		tail = newList;
		current = newList;
		cnt++;
	}
}

void Left() {
	current = current->prv;
}

void Right() {
	current = current->next;
}

void Delete() {
	auto tmp = current;
	tmp->prv->next = tmp->next;
	tmp->next->prv = tmp->prv;
	Left();
	delete(tmp);
	cnt--;
}

void push(char n) {
	auto newList = new List;
	if (n == NULL)
		return;
	newList->n = n;
	if (cnt == 0) {
		newList->prv = newList;
		newList->next = newList;
		head = newList;
		tail = newList;
		cnt++;
	}
	else {
		newList->prv = current;
		newList->next = current->next;
		current->next->prv = newList;
		current->next = newList;
		current = newList;
		cnt++;
	}
}

void intiList() {
	for (int i = 0; i < sizeof(str); i++) {
		if (str[i] == NULL)
			break;
		push_back(str[i]);
	}
	current = tail;
}

void solve() {
	for (int i = 0; i < sizeof(cmd); i++) {
		auto tmp = cmd[i];
		if (tmp == NULL)
			break;
		if (tmp == 'R')
			Right();
		else if (tmp == 'L')
			Left();
		else if (tmp == 'B')
			Delete();
		else if (tmp > 'a' && tmp < 'z')
		{
			if (current == tail)
				push_back(tmp);
			else
				push(tmp);
		}
			
	}
	for (int i = 0; i < cnt; i++) {
		cout << head->n;
		head = head->next;
	}
}

int main() {
	InputData();//	입력 함수

	//	코드를 작성하세요
	intiList();
	solve();
	return 0;
}
