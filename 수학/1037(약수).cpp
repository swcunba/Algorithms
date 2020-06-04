/*
약수는 대칭성을 갖는 특징이 있다.
예) 8의 약수 = 1, 2, 4, 8 -> 1 * 8 = 8, 2 * 4 = 8 
33의 약수 = 1, 3, 11, 33 
*/

#include <iostream>
#include <algorithm>

using namespace std;

int dividers[51];

int main(void){
	int n, idx;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){ 
		scanf("%d", &dividers[i]);
	}
	sort(dividers, dividers + n);
	int result = dividers[0]*dividers[n-1];
	printf("%d\n", result); 
} 
