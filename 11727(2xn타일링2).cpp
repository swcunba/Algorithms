/*
2*n 크기의 직사각형의 1s2, 2x1, 2x2 타일로 채우는 방법의 수
결과값은 10,007로 나눈 나머지 값 출력.

마지막 칸이 2x1 오는 경우와 2x2 or 1x2 오는 경우로 나눌 수 있음.
2x1이 마지막에 온다면 2x(n-1)칸을 채워넣는 경우의 수를 찾으면 되고,
2x2나 1x2가 마지막에 온다면 2x(n-2)칸을 채워넣는 경우의 수*2 값을 찾으면 된다. 
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
