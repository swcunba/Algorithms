#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//���ǻ���: ������ �ƴ϶� �����̴�.
vector<pair <int, int> > score;

int main(void) {
	int n, t;
	cin >> t;
	for (int i = 0; i < t; i++) {//�׽�Ʈ ���̽���ŭ �ݺ�
		cin >> n;
		score.clear();//�ʱ�ȭ
		int x, y;
		for (int j = 0; j < n; j++) {
			cin >> x >> y;
			score.push_back(make_pair(x, y));//��� �ڷ����� �� ���� ���� �Է¹���
		}
		sort(score.begin(), score.end());//���� �������� ����
		int temp = score[0].second, result = 1;//���� 1�� ���� ���, ���� 1���� ������ �հ��̶� 1�� ����.
		for (int j = 0; j < n; j++) {
			//���� 1���� ������ �հ�
			//���� 2���� ���� 1��� ���� ��� ���ƾ���
			//���� 3���� ���� 2��� ���� ��� ���ƾ���...���� �ݺ�
			if (temp > score[j].second) {//���� 1�� ���� ������� ���ٸ�,
				temp = score[j].second;//������� 1�� �߰��ϰ�, �հ��� �� �ִ� ���� ��� ���� ����. 
				result += 1;
			}
		}
		cout << result << "\n";
	}
	return 0;
}
