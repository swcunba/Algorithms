/*�ڷ� ������ -�ݾ� Ŀ���Ƿ� �ִ��� �������� 
�� ���� �ִ� ����� ������ �������Ѵ�.
���� �� ������ �� �� �ִ� ���*/

#include <iostream>
#include <algorithm>
using namespace std;
int p[100001];

int main(void) {
	int n;
	cin >> n;//��� ��
	for (int i = 0; i < n; i++) {
		cin >> p[i];//�ַ��� ��
	}
	sort(p, p + n);//�� �������� ����(���� �ִ� ��� �� �ڿ�)
	int minus = 0, temp = 0;//���, ���� �ݾ�
	long long result = 0;//���� �����÷ο� ���� ����(�̰� ���ؼ� Ʋ����)
	for (int i = n - 1; i >= 0; i--) {//�� �ں���
		temp = p[i] - minus;
		if (temp < 0) temp = 0;
		result += temp;
		minus++;
	}
	cout << result << '\n';
	return 0;
}