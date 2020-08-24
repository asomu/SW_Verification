#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
	string name;
	vector<Node*> edge;
	int checked = 0;
};

class MyQueue {
	Node* myNode[10];
	int rp = 0;
	int wp = 0;
public:
	void push(Node* n ) {
		myNode[wp++] = n;
	}
	void pop() {
		rp++;
	}
	Node* front() {
		return myNode[rp];
	}
	int empty() {
		return rp == wp;
	}
};

class MyStack {
private:
	Node* myNode[10];
	int idx = 0;
public:
	void pop() {
		idx--;
	}
	void push(Node* n) {
		myNode[++idx] = n;
	}
	Node* top() {
		return myNode[idx];
	}
	int emtpy() {
		return idx==0;
	}
};


void BFS(Node* start) {
	start->checked = 1;
	MyQueue q;
	q.push(start);
	while (!q.empty()) {
		auto currentQueue = q.front();
		q.pop();
		cout << currentQueue->name << endl;
		for (unsigned int i = 0; i < currentQueue->edge.size(); i++) {
			if (currentQueue->edge[i]->checked == 1)
				continue;
			q.push(currentQueue->edge[i]);
			currentQueue->edge[i]->checked = 1;
		}
	}

	
	
}

void DFS(Node* start) {
	start->checked = 1;
	std::cout << start->name << endl;
	for (unsigned int i = 0; i < start->edge.size(); i++) {
		DFS(start->edge[i]);
	}
}

void DFS_STACK(Node* start) {
	MyStack st;
	st.push(start);
	start->checked = 1;
	while (!st.emtpy()) {
		auto temp = st.top();
		st.pop();
		cout << temp->name << endl;
		for (unsigned int i = 0; i < temp->edge.size(); i++) {
			if (temp->edge[i]->checked)
				continue;
			st.push(temp->edge[i]);
			temp->edge[i]->checked = 1;
		}
	}
}


string myName[] = { "A", "B", "C", "D", "E", "F", "G", };



int main() {
	Node A, B, C, D, E, F, G;
	A.name = "A";
	B.name = "B";
	C.name = "C";
	D.name = "D";
	E.name = "E";
	F.name = "F";
	G.name = "G";
	A.edge.emplace_back(&B);
	A.edge.emplace_back(&C);
	B.edge.emplace_back(&D);
	B.edge.emplace_back(&E);
	B.edge.emplace_back(&A);
	C.edge.emplace_back(&F);
	C.edge.emplace_back(&G);
	C.edge.emplace_back(&A);
	D.edge.emplace_back(&B);
	D.edge.emplace_back(&E);
	E.edge.emplace_back(&B);
	E.edge.emplace_back(&D);
	F.edge.emplace_back(&C);
	F.edge.emplace_back(&G);
	G.edge.emplace_back(&C);
	G.edge.emplace_back(&F);
	BFS(&A);
}