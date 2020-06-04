#include <stdio.h>
int main(void)
{
	int A, B, V, cnt = 0;
	scanf("%d %d %d", &A, &B, &V);
	cnt = (V-B-1) / (A - B) + 1; //하루에 A-B만큼 올라가고
	printf("%d", cnt);//A만큼 올라가는 시점에 정상 찍으면 끝나므로 (A-B)만큼 올라간다고 설정
}