/*������ ������ k, �߷��� w�� �� ��, �� ������ �ɸ��� �߷��� w/k.
�������� ��ƿ �� �ִ� �߷� �Ѱ谡 ����.
k���� ������ ��� ����ϴ� ������ ���� �߷��� �� �� �ִ� ��������
�Ұ��س����鼭 �߷� ��ƿ �� �ִ��� Ȯ���ϴ� ���� �ݺ�.
������������ �����صθ� �տ������� ���� ���� �Ұ� ����.*/

#include <stdio.h>
#include <algorithm>
int N;
int ropes[10001];
int main(void) {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d\n", &ropes[i]);
	}
	std::sort(ropes, ropes + N);//���� ���� ������ ����
	int max = 0;//�ִ� �߷��� ����ϴ� ���� �� * ���� ���� ���� �� �� �ִ� ����
	for(int i = 0; i < N; i++) {
		if(max < ropes[i]*(N-i)) max = ropes[i] * (N - i);
	}
	printf("%d", max);
	return 0;
}