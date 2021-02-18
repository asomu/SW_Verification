#include <stdio.h>
#include <malloc.h>

char str[100000 + 10];//초기 문자열
char cmd[500000 + 10];//명령어 문자열
char sol[600000 + 10];

struct NODE{
    char ch; struct NODE *prev, *next;
};
struct NODE *head, *tail, *cur;

void insert(char ch){//cur 앞에 삽입
    struct NODE *p = (struct NODE *)malloc(sizeof(struct NODE));
    p->ch = ch; p->prev = cur->prev; p->next = cur; p->prev->next = cur->prev = p;
}

void left(){
    if(cur->prev != head) cur = cur->prev;
}

void right(){
    if (cur != tail) cur = cur->next;
}

void del(){
    if (cur->prev != head) {
        cur->prev = cur->prev->prev; free(cur->prev->next); cur->prev->next = cur;
    }
}

void solve(){
    int i;
    head = (struct NODE *)calloc(1, sizeof(struct NODE));
    cur = tail = (struct NODE *)calloc(1, sizeof(struct NODE));
    head->next = tail; tail->prev = head;
	for (i = 0; str[i]; i++) insert(str[i]);

    for (i = 0; cmd[i]; i++){
        switch (cmd[i]){
        case 'B'://제거
            del();
            break;
        case 'L'://커서 왼쪽으로 이동
            left();
            break;
        case 'R'://커서 오른쪽으로 이동
            right();
            break;
        default://삽입
            insert(cmd[i]);
        }
    }
}

void InputData(){
    scanf("%s", str);
	scanf("%s", cmd);
}

void OutputData(){
    int i = 0;
    for (cur = head->next; cur != tail; cur = cur->next) sol[i++] = cur->ch;
    sol[i] = 0;
    printf("%s\n", sol);
}

int main(){
    InputData();
    solve();
    OutputData();
    return 0;
}
