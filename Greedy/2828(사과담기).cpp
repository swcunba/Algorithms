/*Nĭ�� ����, Mĭ�� �ٱ���, j���� ���
�ּ����� ���������� ����� �ٱ��Ͽ� �������� �ٱ����� ���κ���
����� �������� ��ġ�� ���� �ϸ� �ȴ�.
�ٱ����� ���κи� ����*/
#include <iostream>

using namespace std;

int apple[21];
int basket[2];
int main(void) {
	int N, M, j, i, distance = 0;
	cin >> N >> M;//���� ũ��, �ٱ��� ũ��
	cin >> j;//��� ����
	for (i = 0; i < j; i++) {
		cin >> apple[i];//��� ������ġ
	}
	//�ٱ����� ����
	basket[0] = 1;//�ٱ��� ���� ��
	basket[1] = M;//�ٱ��� ������ ��
	
	for (i = 0; i < j; i++) {
		int move = 0;
		if (apple[i] > basket[1]) {//������ ������ �� �������̸�
			distance += (apple[i] - basket[1]);
			basket[0] += (apple[i] - basket[1]);
			basket[1] += (apple[i] - basket[1]);
			move += 1;
			//cout << distance << endl;
		}
		else if (apple[i] < basket[0] && move == 0) {//���� ������ �� �����̸�
			distance += (basket[0] - apple[i]);
			basket[1] -= (basket[0] - apple[i]);
			basket[0] -= (basket[0] - apple[i]);
			//cout << distance << endl;
		}
		else if(apple[i] == basket[0] || apple[i] == basket[1] && move == 0){
			//cout << distance << endl;
			continue;
		}
	}
	cout << distance;
	return 0;
}