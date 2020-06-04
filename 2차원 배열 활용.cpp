#include <stdio.h>
int T, k, n, i, j, p[15][15];
int main(void)
{
	//층과 방이라는 변수 2개 -> 2차원 배열 사용
	for (i = 1; i < 15; i++) p[0][i] = i;//0층 사람 수
	for (i = 1; i < 15; i++)
	{
		for (j = 1; j < 15; j++)
			p[i][j] = p[i - 1][j] + p[i][j - 1]; //점화식에 따라 값 설정
	}
	scanf("%d", &T);
	for (i=1; i<=T; i++) {
		scanf("%d %d", &k, &n);
		printf("%d\n", p[k][n]);
	}
	return 0;
}