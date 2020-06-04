/*n���� ������ �迭 a�� �־���.
b�迭�� ���Ұ� a�迭���� �����ϸ� 1���, �ƴ� ��� 0���.*/

#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int a[MAX];//A�迭. 
int b[MAX];//A�迭�� ���� �迭. 
 
void search(int start, int end, int target){//Ž�� ���� �ε���, �� �ε���, ã���� �ϴ� ��. 
	if(start > end){
	printf("0\n");
	return;
	//�������� �� �ε������� ũ�ٸ� �ش� ���� �������� �ʴ´ٴ� �ǹ�. 
	}
	int mid = (start + end) / 2;//�̺� Ž�� ���� �߰� �ε��� ����. 
	if(a[mid] == target){
		printf("1\n");
		return;
		//ã������ ���� �߰� ���ҿ��ٸ� �ٷ� ��ȯ��Ű�� ����. 
	}
	else if(a[mid] > target) return search(start, mid - 1, target);//ã������ ������ Ž������ �߰��� ��ġ�� ���� �� ũ�� Ž�� ������ �߰� �ε��� - 1 �κб����� ����.
	else return search(mid+1, end, target);//�߰����� ã������ ���� �ָ� ������ �߰� + 1 �������� �������� Ž��. 
} 

int main(void){
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}//�迭�� ���� �Է�. 
	sort(a, a+n);
	//�̺� Ž���� ���� �������� ����.
	for(int i = 0; i < m; i++){
		search(0, n-1, b[i]);
	}
	return 0;
}
