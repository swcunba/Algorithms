#include <stdio.h>
int main(void)
{
	int M, N, cnt;
	scanf("%d %d", &M, &N);
	cnt = N - M;
	int *nums = new int[];
	int *div = new int[];
	for (int i = cnt; i <= M; i--) nums[i] = i;
	for (int i = 0; i <= N; i++) div[i] = i;
	return 0;
}