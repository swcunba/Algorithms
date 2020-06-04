#include <stdio.h>
int d = 0, jump = 0;
int d_cal(int x, int y)
{
	int m_dist = 1;
	jump = 0;
	d = y - x - 1; //마지막 점프는 1로 제한되므로 처음부터 -1
	while (1)
	{
		if (d > 0)
		{
			d -= m_dist;
			m_dist++;
			jump++;
		}
		else
			break;
	}
	jump += 1;
	return jump;
}
int main(void)
{
	int T, x, y, result;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &x, &y);
		result = d_cal(x, y);
		printf("%d\n", result);
	}
	return 0;
}