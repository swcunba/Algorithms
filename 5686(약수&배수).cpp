#include <stdio.h>
int main(void)
{
	int a, b;
	while (1)
	{
		scanf("%d %d", &a, &b);
		if (a == 0 && b == 0) //���ѷ��� Ż�� ��츦 �� �տ� �־� ���� �Ȼ���
			break;
		if (b%a == 0)
			printf("factor\n");
		else if (a%b == 0)
			printf("multiple\n");
		else
			printf("neither\n");
	}
	return 0;
}