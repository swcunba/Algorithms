#include <stdio.h>
int T, k, n, i, j, p[15][15];
int main(void)
{
	//���� ���̶�� ���� 2�� -> 2���� �迭 ���
	for (i = 1; i < 15; i++) p[0][i] = i;//0�� ��� ��
	for (i = 1; i < 15; i++)
	{
		for (j = 1; j < 15; j++)
			p[i][j] = p[i - 1][j] + p[i][j - 1]; //��ȭ�Ŀ� ���� �� ����
	}
	scanf("%d", &T);
	for (i=1; i<=T; i++) {
		scanf("%d %d", &k, &n);
		printf("%d\n", p[k][n]);
	}
	return 0;
}