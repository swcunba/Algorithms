/*�����ϴµ� �ð��� ���� �ɸ��� ����� ������ ������ �ּڰ��� ����
����, �ҿ�ð��� ������������ ���Ľ�Ű�� ���� ���ϰ� �ϸ� �ǰڴ�.*/
#include <stdio.h>
#include <algorithm>
int N, time[1001];
int main(void) {
	scanf("%d", &N);//��� �� �Է�
	for (int i = 0; i < N; i++) {
		scanf("%d", &time[i]);//��� ����ŭ �� �ҿ�ð� �Է�
	}
	std::sort(time, time + N);//�ҿ�ð� �������� ����
	int result = 0;
	for (int i = 1; i < N; i++) {
		time[i] += time[i-1];//�ҿ�ð� �ջ�� �Ŷ� ��ħ
	}
	for (int i = 0; i < N; i++) {
		result += time[i];
	}
	printf("%d", result);
	return 0;
}
