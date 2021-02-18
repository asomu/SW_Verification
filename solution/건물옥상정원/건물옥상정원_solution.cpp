#include <iostream>
using namespace std;

int N;//�ǹ� ��
int H[80010];//�ǹ� ����

int stack[80010];

void Input_Data(void){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> H[i];
	}
}

long long solve(){
	int sp = 0;
	long long sum = 0;
	for(int i=0; i<N ; i++){
		while(sp > 0){
			if(H[i] < stack[sp]) break;
			sp--;
		}
		sum += sp;
		stack[++sp] = H[i];
	}
	return sum;
}

int main(){
	long long ans = -1;
	Input_Data();
	ans = solve();
	cout << ans << endl;
	return 0;
}