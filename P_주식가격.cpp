#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// prices_len�� �迭 prices�� �����Դϴ�.

int prices[5] = { 1, 2, 3, 2, 3};
int prices_len = 5;
int* solution(int prices[], size_t prices_len) {
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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
