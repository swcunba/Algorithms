#include <stdio.h>
int main(void)
{
	int A, B, V, cnt = 0;
	scanf("%d %d %d", &A, &B, &V);
	cnt = (V-B-1) / (A - B) + 1; //�Ϸ翡 A-B��ŭ �ö󰡰�
	printf("%d", cnt);//A��ŭ �ö󰡴� ������ ���� ������ �����Ƿ� (A-B)��ŭ �ö󰣴ٰ� ����
}