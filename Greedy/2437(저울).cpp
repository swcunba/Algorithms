#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000000 + 1;
int N;
vector<int> v;
int main(void)

{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin ����ӵ� ���
	cin >> N;
	v.resize(N);//�迭�� ���� ���� N���� ���� �������� ����Ʈ 0���� ä���� 
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	//1�� ���ٸ� 1�� �ּڰ�
	if (v[0] != 1)
		cout << 1 << "\n";
	else
	{//1�� �ִٸ�
		int sum = 1; //������ 1�� ����
					 //��������� �� + 1 ���� ū ���� ���� �ε����� ����� �����
					 //������ �ߵ�� ���Ը� ���� �� ����
		for (int i = 1; i < N; i++)
		{
			if (v[i] > sum + 1)
				break;
			sum += v[i];
		}
		cout << sum + 1 << "\n";
	}
	return 0;
}
//�پ��� ����� ���ø� �� �ֵ��� ���� ���غ����Ѵ�.