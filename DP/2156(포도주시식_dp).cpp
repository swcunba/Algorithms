/*
��� ������ ������ �����ϴ�.
3�� ���ӵǸ� �ȵȴٴ� ��Ģ�� �����Ѵ�.
�� ���� ����ġ�� �������, �������� �����ص� ������.  
*/

#include <iostream>
#include <algorithm>
#define MAX 10003

using namespace std;

int wine[MAX] = { 0, };//�� �ܿ� ����ִ� �������� ��.
int values[MAX] = { 0, };//���� �����. �ε��� - 1 = ����ģ ���� ����. 

int main(void){
	int n; 
	scanf("%d", &n);
	for(int i = 3; i < n+3; i++){
		scanf("%d", &wine[i]);
	}
	//values[0] = wine[0];
	//values[1] = wine[0] + wine[1];
	//values[2] = max(wine[0] + wine[2], wine[1]);
	
	for(int i = 3; i < n+3; i++){
		values[i] = max(values[i-2] + wine[i], values[i-3] + wine[i-1] + wine[i]);//2�� ���� �н��ϴ� ��� ���x. 
		values[i] = max(values[i-1], values[i]);//2�� ���� �ȸԴ� ��찡 �� Ŭ �� ����. 
		printf("%d ", values[i]);
	}
	 
	//printf("%d\n", values[n+2]);
	return 0;
} 
 
