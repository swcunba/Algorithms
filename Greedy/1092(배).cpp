/*
n���� ũ����, �۾� ���� �ð� 1.
�� ũ���ο��� ���� ���� ����. �ڽ��� �� ���� �ϳ����� �̵�����.
��� ũ������ ���ÿ� ������. ��, 1 ���� �ð��� �ִ� n���� �ڽ� �ű� �� ����.
�����ϴٸ� ��� ũ������ �̿��� �� �ֵ��� �ϸ� ���̴�. 
�ڽ��� ���� m.
�ڽ� �ű�µ� �ɸ��� �ð��� �ּڰ�. 
�ű� �� ������ -1 ���.

�׳� �������� �������δ� ũ������ ���� ���Ѱ� �ڽ� ������ ���� �ּ�ȭ�Ͽ�
�ű�� ���� ������ �ʹ�. 
�켱���� ť ���� �ߺ��� ���� ����ϸ� ���ѷ��� �߻��ϴ� ���� ������. 
*/
#include <iostream>
#include <algorithm>

using namespace std;
 
int box[10001];
int crane[51];
int check[10001];
int n, m;

int desc(int x, int y){
	return (x > y);
}

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &crane[i]);
	scanf("%d", &m);
	for(int i = 0;  i < m; i++) scanf("%d", &box[i]);
	sort(crane, crane + n, desc);
	sort(box, box + m);
	int result = 0;
	if(crane[0] < box[m-1]){
		printf("-1");
		return 0;	
	}
	while(m){
		int idx = 0;
		for(int j = m-1; j >= 0; j--){
			if(box[j] <= crane[idx]){
				idx++; 
				m--;
				break;
			}
			if(idx == n) break; 	
		}
		result++;
	}
	printf("%d\n", result);
	return 0;
}
