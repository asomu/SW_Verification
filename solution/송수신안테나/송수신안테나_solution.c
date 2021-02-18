#include <stdio.h>

int N;//송수신 안테나 수
int H[100000 + 10];//송수신 안테나 높이

int stack[100000 + 10];
int sp;
void push(int h){
	stack[++sp] = h;
}
void pop(){
	sp--;
}
int top(){
	return stack[sp];
}
int size(){
	return sp;
}
int empty(){
	return sp == 0;
}

void InputData(){
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &H[i]);
}

int Solve(){
	int cnt = 0;
	int i;
	for (i = 0; i < N; i++){
		while (!empty() && (top() < H[i])){
			cnt++;
			pop();
		}
		if (!empty()) {
			cnt++;
			if (top() == H[i]) pop();
		}
		push(H[i]);
	}
	return cnt;
}

int main(){
	int ans = -1;
    InputData();//	입력 함수

	ans = Solve();//	코드를 작성하세요
	
	printf("%d\n", ans);//출력 
    return 0;
}
