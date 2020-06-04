#include <stdio.h>
#include <iostream>
using namespace std;
int main(void)
{
	int A, B, C, sell;
	scanf("%d %d %d", &A, &B, &C);
	cin >> sell;
	if (C-B <= 0)
	{
		sell = -1;
		printf("%d", sell);
	}
	else
	{
		sell = A / (C - B) + 1;
		printf("%d", sell);
	return 0;
}