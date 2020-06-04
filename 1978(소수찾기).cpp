#include <stdio.h>
int main(void)
{
	int N, cnt = 0, prime = 0, div = 1;
	scanf("%d", &N);
	int *nums = new int[N];
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	for (int i = 0; i < N; i++)
	{
		for (div = 1; div <= nums[i]; div++)
		{
			if (nums[i] % div == 0)
				cnt++;
			if (div == nums[i] && cnt == 2)
			{
				prime++;
				cnt = 0;
			}
			else if (div == nums[i])
				cnt = 0;
		}
	}
	printf("%d", prime);
	return 0;
}