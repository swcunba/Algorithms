/*��Ÿ���� ��� �������� 6�� ��Ű��, ���� �� �����̴�.
������ �� �� ���� �� ���ݰ� 6�� ��Ű�� �� ���� ��
���� �ľ��ϸ� �� �� ����.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int single[100], bundle[100];//���� ���ݰ� ��Ʈ ���� ���� �����̳�
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> bundle[i] >> single[i];
		//��Ÿ�� ���� �Է�
	}
	//��Ʈ ���� �������� �������� ����
	sort(single, single + m);
	sort(bundle, bundle + m);
	int b_cheap = bundle[0], s_cheap = single[0], charge = 0;//b_cheap: ��Ű�� �� ���� �� ����, s_cheap: ���� �� ���� �� ����
	//��� �ڷ������� �����ϰ� �����ϴ� �������� �𸣰����� �������� ������ ���� ����
	//cout << s_cheap << b_cheap << '\n';
	//��Ű�� ���� �� ���ݰ� ���� ���� �� ���� ����.
	//n%6 == 0�̰�, ��Ű���� �� �δٸ� ��Ű���� ��� ����
	if (b_cheap < s_cheap * 6 && n % 6 == 0) {
		charge = b_cheap * n / 6;
	}
	/*��Ű���� �������� �δ���
	������ ��Ÿ���� ���� 6���� ����������� �ʰ�,
	6���� ���� ��������ŭ ������ �� ������ ��Ű�� ������ �۴ٸ�
	��Ű���� ���� ���� �����.*/
	else if (b_cheap < s_cheap * 6 && n % 6 != 0 && (n % 6) * s_cheap <= b_cheap) {
		charge = (n / 6) * b_cheap + (n % 6) * s_cheap;
	}
	/*��Ÿ���� ���� 6���� ����������� �ʰ� ��Ű�� ������ �� �ѵ�
	n%6��ŭ ������ �� ������ ��Ű�� ������ ũ�ٸ� ��Ű���θ� ��� �ȴ�.*/
	else if (b_cheap < s_cheap * 6 && n % 6 != 0 && (n % 6) * s_cheap > b_cheap) {
		charge = (n / 6) * b_cheap + b_cheap;
	}
	//������ ��°� ���� �� ��� �׳� ������ ��� ��
	else{
		charge = s_cheap*n;
	}
	cout << charge;
	return 0;
}