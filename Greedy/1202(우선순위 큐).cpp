/*n�� ����, k�� ����, ���濡�� ���� �ѵ� ����
�������� ���Կ� �����̶�� ����
���� ���� �ִ� ��
�ϴ� ������ �������� �������� �����ϰ� �뷮�� �ȳ�ġ�� ������ ����
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int bag[300001];
vector<pair <int, int> > jewel;
priority_queue<int> q;//max_heap ������� �ð� ���⵵ ���� �� ����. heap�� ���� Ʈ���� ����or������������ ������ ���¸� ���Ѵ�.
//ť�� ���Լ��������� �켱���� ť�� ���� ū �� �켱������ ����
//��Ƽ� ū ���� ���� ������. ��, �˾Ƽ� �������� ������ ��
int main(void) {
	int n, k, x, y;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		jewel.push_back(make_pair(x, y));
	}
	sort(jewel.begin(), jewel.end());//���� ���� ���� �������� ����
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	sort(bag, bag+k);//���� ���� �������� ����(������ ���� ������)
	long long result = 0;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && jewel[idx].first <= bag[i]) {
			//���� ���� �����ϴ� ���� �� ����(���� �����ź��� ��)
			q.push(jewel[idx++].second);//ť���� ���� ������ ����
		}
		//������ �켱���� ť�� �־����� ���� ���� ���� ��� ����
		if (!q.empty()) {
			result += q.top();
			q.pop();//�� ���� ���� ����(����), ������ϱ� ��� ���ϱ� ���ؼ�
		}
	}
	cout << result;
	return 0;
}//�ð� �ʰ�, ���� �����ִ°� �ƴ϶� ���̻� �Ⱥ��� �ǰ� ��������
