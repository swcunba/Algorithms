/*n�� ����, k�� ���, �����ǰ �̸��� ���ڷ� �־���
�÷��׸� �ּ������� �̴� Ƚ��
ó�� n�� ��ŭ�� �����ǰ�� ���� ä�� �����ؾ���.
�ּ������� �������� ���߿� �� ���� �����ǰ�� ���� ���ƾ���
*/

#include <iostream>

using namespace std;
int tools[100];
int plugged[100];//�����ִ� �����ǰ

int main(void) {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> tools[i];
	}
	for (int i = 0; i < n; i++) {
		plugged[i] = tools[i];//ó���� �����ִ� �ⱸ
	}
	int result = 0, count = 0;
	//�ڿ� �� ���̴� �ֵ��� ��� ��󳾱�, ���� ���� ī��Ʈ?
	//�̴� Ƚ�� = k - n - ó������ ������ �߿��� ���� �ⱸ ����
	for (int i = 0; i < n; i++) {
		for (int j = n; j < k; j++) {
			if (tools[j] == plugged[i]) count++;
		}
	}
	result = k - n - count;
	cout << result;
	return 0;
}