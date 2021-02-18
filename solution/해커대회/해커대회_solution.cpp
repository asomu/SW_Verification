#include <iostream>
using namespace std;

char str[100000 + 10];
char cmd[500000 + 10];
char sol[600000 + 10];

struct NODE{
    char ch; NODE *prev, *next;
    NODE(){ ch = 0; prev = next = NULL; }
    NODE(char nc, NODE *p){//뒤에서 앞에 삽입
        ch = nc; next = p; prev = p->prev; prev->next = this;
    }
    ~NODE(){ delete next; }
    void selfdel(){
        prev->next = next; next->prev = prev; next = NULL; delete this;
    }
};

struct LINE{
    NODE *head, *tail, *cur;
    LINE(){
        head = new NODE(); cur = tail = new NODE(); head->next = tail; tail->prev = head;
    }
    ~LINE(){ delete head; }
    void insert(char ch){
        cur->prev = new NODE(ch, cur);
    }
    void left(){
        if(cur->prev != head) cur = cur->prev;
    }
    void right(){
        if (cur != tail) cur = cur->next;
    }
    void del(){
        if (cur->prev != head) cur->prev->selfdel();
    }
    void PRT(){
		int i = 0;
        for (cur = head->next; cur != tail; cur = cur->next) sol[i++] = cur->ch;
		sol[i] = 0;
        cout << sol << endl;
    }
};
LINE *line;

void InputData(){
    cin >> str;
	cin >> cmd;
}

void solve(){
    delete line; line = new LINE();
	for (int i = 0; str[i]; i++) line->insert(str[i]);
	
    for (int i = 0; cmd[i]; i++){
        switch (cmd[i]){
        case 'B'://제거
            line->del();
            break;
        case 'L'://커서 왼쪽으로 이동
            line->left();
            break;
        case 'R'://커서 오른쪽으로 이동
            line->right();
            break;
        default://삽입
            line->insert(cmd[i]);
        }
    }
}

void OutputData(){
    line->PRT();
}

int main(){
    InputData();
    solve();
    OutputData();
    return 0;
}
