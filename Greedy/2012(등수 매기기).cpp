#include <iostream>
#include <algorithm>
#define MAX 500001

using namespace std;
 
int pre[MAX];
int real[MAX];

int main(void){
	int n;
	long long result = 0;//������ ũ��. 
	scanf("%d", &n);
	for(int i =0; i < n; i++){
		scanf("%d", &pre[i]);
		real[i] = i+1;
	}
	sort(pre, pre + n);
	//���� ��� ��ġ�� ���� ����� ���� ����.
	//���� ���� ���� ��� - ���� ����� ���� ��. 
	for(int i = 0; i < n; i++){
		if(real[i] - pre[i] > 0) result += real[i] - pre[i];
		else result += -(real[i] - pre[i]);
	}
	printf("%ld\n", result);
	return 0;
}
