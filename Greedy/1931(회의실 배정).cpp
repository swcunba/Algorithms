/*N���� ȸ��, ȸ�� ���� ���ÿ� ���� ����. �� �� �ִ� ȸ�� ��
�ִ�.
ȸ�Ǹ� �ִ�� �Ϸ��� ȸ���� ���� �ð� ���� ���� �ּ�ȭ �ؾ���
���� ������ ȸ�ǵ鸸 ���� ���*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> >meeting;
int mBegin[100000], mEnd[100000];//ȸ�� ����, �� �ð�
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mBegin[i] >> mEnd[i];
		//ȸ�� ���۰� �� �ð� �Է�
	}
	for (int i = 0; i < n; i++) {
		meeting.push_back(make_pair(mEnd[i], mBegin[i]));//������ �ð��� �������� �����ϱ� ���� �տ� ������ �ð��� ��
	}
	int earliest = 0, selected = 0;//earliest�� ���� ȸ�� ���� ������ ���� ���� �ð�, selected�� ���õ� ȸ�� ��
	sort(meeting.begin(), meeting.end());//�������� ����
	for (int i = 0; i < n; i++) {
		int meetingBegin = meeting[i].second, meetingEnd = meeting[i].first;
		if (earliest <= meetingBegin) {//earliest�� ȸ�� ���� �ð����� �̸��ų� ������
			earliest = meetingEnd;//earliest�� ȸ�ǰ� ������ �ð����� ����
			selected++;
		}
	}
	cout << selected;
	return 0;
}