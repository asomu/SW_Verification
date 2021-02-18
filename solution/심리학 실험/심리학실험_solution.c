#include <stdio.h>

int N;//후보자 수
int A[100000 + 10];

void InputData(){
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &A[i]);
}

int ABS(int x){ return (x < 0) ? -x : x; }

void solve(){
    int i = 0, j = N - 1, minsum = (int)(2e9 + 10), sum, minans, maxans;
    while (i < j){
        sum = A[i] + A[j];
        if (minsum > ABS(sum)){
            minsum = ABS(sum); minans = i; maxans = j;
        }
        if (sum > 0) j--;
        else if (sum < 0) i++;
        else break;
    }
    printf("%d %d\n", minans, maxans);
}

int main(){
    InputData();
    solve();
    return 0;
}
