/*
1. n�� ��� ī���� ��� ���.(i * n/i) 
2. i��° + n-i���� ī���� ��� ���.(�ε��� �� n) 
3. 1�� ������ ī�� �� ä��� ī���� ������ ��� 
*/

#include <iostream>
#include <algorithm>
#define MAX 1001

using namespace std;

int cardpacks[MAX];
int price[MAX];

int main(void){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &cardpacks[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			price[i] = max(price[i], price[i-j] + cardpacks[j]);//�ε����� �� i�Ǵ� ��� ��� Ž��. 
		}
	}
	printf("%d\n", price[n]);	
	return 0;
}
