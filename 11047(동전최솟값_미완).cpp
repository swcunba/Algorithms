#include <stdio.h>
#include <iostream>
using namespace std;

int N[10], K, i;
int m = 0;
int coin_num(void)
{
	

	for (i = 9; i <= 0; i--)
	{
		m += K / N[i]; //���������� ������ �����θ� �� ������ Ư�� �̿�
		K %= N[i];
	}
	return m;
}
int main(void)
{
	cin >> K;
	int result;
	for (i = 0; i < 10; i++)
	{
		N[0] = 1;
		if (i != 0)
		{
			if (i % 2 != 0)
				N[i] = 5 * N[i - 1];

			else
				N[i] = 2 * N[i - 1];
		}
		//printf("%d\n", N[i]);
	}
	coin_num();
	printf("%d", m);
	return 0;
}