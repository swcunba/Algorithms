#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int range = 1, barrier = 1, tmp = 1, N;
	cin >> N;

	while (1) {
		if (range >= N)
			break;
		tmp = 6 * (barrier++); //�� ������ 6�� ����� �þ�Ƿ� ������ ������ �̷��� ������.
		range += tmp;
	}//range(���� ����)�� N�� ���� �ʴ� ������
	 //���ڸ� 6�� �����ŭ ��� �÷���.
	 //barrier(����� ���� �� ����)�� �� ����.
	cout << barrier;
	return 0;
}