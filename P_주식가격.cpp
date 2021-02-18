#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// prices_len은 배열 prices의 길이입니다.

int prices[5] = { 1, 2, 3, 2, 3};
int prices_len = 5;
int* solution(int prices[], size_t prices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*prices_len);
	int cnt = 0;
	for(int i = 0; i < prices_len; i++){
		int stock = prices[i];
		for(int j = cnt; j < prices_len; j++){
			if(stock >= prices[j]){
				answer[cnt]++;
			}
			else{
				break;
			}
		}
		cnt++;
	}
    return answer;
}

int main(void){
	printf("%d ", solution(prices, prices_len));
	return 0;
}
