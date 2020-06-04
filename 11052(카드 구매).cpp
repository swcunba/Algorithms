/*
1. n의 약수 카드팩 사는 경우.(i * n/i) 
2. i번째 + n-i번쨰 카드팩 사는 경우.(인덱스 합 n) 
3. 1과 나머지 카드 수 채우는 카드팩 섞어사는 경우 
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
			price[i] = max(price[i], price[i-j] + cardpacks[j]);//인덱스의 합 i되는 모든 경우 탐색. 
		}
	}
	printf("%d\n", price[n]);	
	return 0;
}
