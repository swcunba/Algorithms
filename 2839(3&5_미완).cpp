#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N, sack;
	cin >> N;
	if (N % 5 == 0)
	{
		sack = N / 5;
		printf("%d", sack);
	}
	if (N % 5 == 1)
	{
		if (N != 1)
		{
			sack = N / 5 + 1;
			printf("%d", sack);
		}
		else if (N == 1)
		{
			sack = -1;
			printf("%d", sack);
		}
	}
	if (N % 5 == 2)
	{
		if (N != 2 || N != 7)
		{
			sack = N / 5 + 2;
			printf("%d", sack);
		}
		else if (N == 2 || N==7)
		{
			sack = -1;
			printf("%d", sack);
		}
	}
	if (N % 5 == 3)
	{
			sack = N / 5 + 1;
			printf("%d", sack);
	}
	if (N % 5 == 4)
	{
		if (N != 4)
		{
			sack = N / 5 + 2;
			printf("%d", sack);
		}
		else if (N == 4)
		{
			sack = -1;
			printf("%d", sack);
		}
	}
	return 0;
}