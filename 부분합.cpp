#include <iostream>
using namespace std;
int A;
int partial_sum(void)
{
	int n = 1;
	while (1)
	{
		int copy = n;
		int sum = n;

		while (copy)
		{
			sum += copy % 10; //10���� ������ �� ������ �� �����ִ� �� �ݺ�(�� ���ڸ������� ������)
			copy /= 10;//���� �ڸ������� �ϳ��� ���
		}
		if (n == A || sum == A)
			break;
		n++;
	}
	return n;
}

int main(void)
{
	int result = 0;
	cin >> A; 

	result = partial_sum();
	if (result == A)
		cout << 0 << endl;

	else
		cout << result << endl;

	return 0;
}

