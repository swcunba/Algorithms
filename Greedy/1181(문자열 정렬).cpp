/*���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ ������ ���ǵ���
�����ϱ�
1. ���̰� ª�� ��
2. ���̰� ������ ���� ��
3. ���� �ܾ�� �� ���� ���
���� ª�� ���� �˰ڴµ� ���� �� ������ ��¼��*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a[20000];
int n;

bool compare(string a, string b) {
	//���� ª�� �ܾ� ����
	if (a.length() < b.length())
		return 1;//�켱���� ����
	else if (a.length() > b.length())
		return 0;//�켱���� ����
	//���� ������ ���� ��
	else
		return a < b;//�� ������ ������ �ڵ����� ���� ������ ��������
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		//���� �ܾ�� �н�
		if (i > 0 && a[i] == a[i - 1]) {
			continue;
		}
		else {
			cout << a[i] << '\n';
		}
	}
	return 0;
}