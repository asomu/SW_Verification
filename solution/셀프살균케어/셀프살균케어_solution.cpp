#include <iostream>
using namespace std;

#define MIN(x,y) ((x)<(y)?(x):(y))
int y[110];		//	��մ���� y ��ǥ �迭
int x[110];		//	��մ���� x ��ǥ �迭
int N;				//	���� �� ���� ũ��
int L;				//	LED�� ����(����) 
int M;				//	��մ���� ����
int sol;			//	����

void Input(void){
	cin >> N >> L >> M;
	for (int i = 0; i < M; i++)		cin >> y[i] >> x[i];
}

int main(void){
	int i, j, k, si, sj, t, h, w;
	
	Input();

	for (h = 1; h < L / 2; h++){		//	���α����� ���� ����
		w = L / 2 - h;							//	���α��̿� ���� ���α��� ����
		for (i = 0; i < M; i++){			//	������ ��մ���� ��� ����
			for (j = i; j < M; j++){
				t = 0;
				si = MIN(y[i], y[j]);		//	��չ����� ���� y, x��ǥ ���
				sj = MIN(x[i], x[j]);
				for (k = 0; k < M; k++){
					//	��չ������� ��մ���� ������� ī��Ʈ ����)
					if (si <= y[k] && y[k] <= si + h && sj <= x[k] && x[k] <= sj + w)   t++;
				}
				if (sol < t) sol = t;			//	���� �ִ밪���� Ŭ ��� ���� ����
			}
		}
	}

	//	�������
	printf("%d", sol);

	return 0;
}