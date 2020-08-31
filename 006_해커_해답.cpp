#include <iostream>
using namespace std;

char str[100000 + 10];
char cmd[500000 + 10];
char sol[600000 + 10];

struct NODE {
	char ch;
	NODE* prev;
	NODE* next;
	NODE() { ch = 0; prev = next = NULL; }
	NODE(char nc,  NODE* p) {
		ch = nc;
		prev = p->prev;
		next = p;
		prev->next = this;
	}
	~NODE() { delete next; }
	void selfdel() {
		prev->next = next;
		next->prev = prev;
		next = NULL;
		delete this;
	}

};

struct LINE {
	NODE* head;
	NODE* tail;
	NODE* cur;
	LINE() {
		head = new NODE();
		tail = cur = new NODE();
		head->next = tail; 
		tail->prev = head;
	}
	~LINE() { delete head; }
	void insert(char ch) {
		cur->prev = new NODE(ch, cur);
	}
	void left() {
		if(cur->prev != head)
			cur	 = cur->prev;
	}
	void right() {
		if (cur != tail)
			cur = cur->next;
	}
	void del() {
		if(cur->prev != head)
			cur->prev->selfdel();
	}
	void PRINT() {
		int i = 0;
		for (cur = head->next; cur != tail; cur=cur->next) {
			sol[i++] = cur->ch;
		}
		sol[i] = 0;
		cout << sol << endl;


	}
};

LINE* line;


void InputData() {
	cin >> str;
	cin >> cmd;
}

void solve() {
	delete line; line = new LINE();
	for (int i = 0; str[i]; i++) {
		line->insert(str[i]);
	}
	for (int i = 0; cmd[i]; i++) {
		switch (cmd[i])
		{
		case 'B':
			line->del();
			break;
		case 'R':
			line->right();
			break;
		case 'L':
			line->left();
			break;
		default:
			line->insert(cmd[i]);
		}
	}
	line->PRINT();
}


int main() {
	InputData();
	solve();
	return 0;
}