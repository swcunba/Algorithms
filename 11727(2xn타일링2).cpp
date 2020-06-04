/*
2*n ũ���� ���簢���� 1s2, 2x1, 2x2 Ÿ�Ϸ� ä��� ����� ��
������� 10,007�� ���� ������ �� ���.

������ ĭ�� 2x1 ���� ���� 2x2 or 1x2 ���� ���� ���� �� ����.
2x1�� �������� �´ٸ� 2x(n-1)ĭ�� ä���ִ� ����� ���� ã���� �ǰ�,
2x2�� 1x2�� �������� �´ٸ� 2x(n-2)ĭ�� ä���ִ� ����� ��*2 ���� ã���� �ȴ�. 
*/

#include <iostream>

int dp[1001];

int tiling(int x){
	if(x==1) return 1;
	if(x==2) return 3;
	if(dp[x]!=0) return dp[x];
	return dp[x] = (tiling(x-1) + tiling(x-2)*2) % 10007;
}
int main(void){
	int n;
	scanf("%d", &n);
	printf("%d\n", tiling(n));
	return 0;
} 
