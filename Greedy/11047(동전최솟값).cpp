#include <iostream>
#include <vector> //�迭 ũ�⸦ ������ �ޱ� ����
using namespace std;
int main(void) {
	int N, K, i, result = 0;
	cin >> N >> K;
	vector<int> coins;
	for (i = 0; i < N; i++) {
		int x;
		cin >> x;
		coins.push_back(x);//x�� ���� ũ�� �Է� �޾Ƽ� �����̳ʿ� �߰�
	}
	for (i = coins.size() - 1; i >= 0; i--) {//������ �Լ��� �ȳ�Ÿ���� ���� �߻�(���� �𸣰���)
		if (K >= coins[i]) {
			result += K / coins[i];
			K -= coins[i] * (K / coins[i]); //��ȣ �Ⱦ��� ��еǼ� ��� ������
		}
	}
	cout << result;
	return 0;
}