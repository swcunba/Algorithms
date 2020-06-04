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
	int result = 0;
	for (int i = 0; i < k; i++) {
		bool plug = false;
		for (int j = 0; j < n; j++)
			if (plugged[j] == tools[i]) {
				plug = true;//���������� true
				break;
			}
		if (plug) continue;//���������� �н�
		for (int j = 0; j < n; j++) {
			if (!plugged[j]) {//�� ��(����)�ִٸ�
				plugged[j] = tools[i];//���� ��� �Ⱦ��ְ�
				plug = true;
				break;
			}
			//���� ���� Ȥ�� ������ �ʴ� ��� ã��
			int idx, deviceidx = -1;
			for (int j = 0; j < n; j++) {
				int lastidx = 0;
				for (int K = i + 1; K < k; K++) {
					if (plugged[j] == tools[K]) break;
					lastidx++;
				}

				if (lastidx > deviceidx) {
					idx = j;
					deviceidx = lastidx;
				}
			}
			result++;
			plugged[idx] = tools[i];//��� �ٲ� ����
		}
		
	}
	cout << result << '\n';
	return 0;
}