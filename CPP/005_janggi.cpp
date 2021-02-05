#include <iostream>
using namespace std;

int N;//직원 수
int S;//시작 직원 번호
int M;

struct Node {
	int data;
	Node* next;
};


class List {
private:
	int total = 0;
	Node* tail =  nullptr;
	Node* head = nullptr;
public:
	Node* CreateNode(int n) {
		auto newNode = new Node;
		newNode->data = n;
		return newNode;
	}
	void push_back(int n) {
		if (total == 0) {
			Node* p = CreateNode(n);
			p->next = p;
			tail = p;
			head = p;
			total++;
		}
		else {
			Node* p = CreateNode(n);
			p->next = tail->next;
			tail->next = p;
			tail = p;
			total++;
		}
	}
	void nextList() {
		tail = tail->next;
	}
	void pop() {
		Node* temp = tail->next;
		tail->next = tail->next->next;
		cout << temp->data << " ";
		delete(temp);
 		total--;
	}
};

void solve() {
	List myList;
	int i = 0;
	int j = S;
	for (i = 0; i < N; i++) {
		myList.push_back(j++);
		if (j > N)
			j = 1;
	}
	for (i = 0; i < N; i++) {
		for (j = 1; j < M; j++) {
			myList.nextList();
		}
		myList.pop();
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