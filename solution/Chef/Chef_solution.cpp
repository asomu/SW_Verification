#include <iostream>
using namespace std;

int N;//손님 수
int P[10000 + 10];//음식 값
int T[10000 + 10];//예약 희망 시간
int rev[10000 + 10];//예약 확정 시간

void InputData(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> P[i];
		cin >> T[i];
	}
}

int solve(void){
	int i, j, price, temp, sum = 0;
	for(i = 0; i < N; i++){
		price = P[i];
		for(j = T[i]; j > 0; j--){
			if(rev[j] == 0){//예약 없음
				rev[j] = price;
				break;
			}
			else if(rev[j] < price){
				temp = price; price = rev[j]; rev[j] = temp;
			}
		}
	}
	for(i = 1; i <= 10000 ; i++){
		sum += rev[i];
	}
	return sum;
}

int main(){
	int ans = -1;
	InputData();
	ans = solve();
	cout << ans << endl;
	return 0;
}