/*
계단 오르기 문제와 유사하다.
3개 연속되면 안된다는 규칙만 존재한다.
몇 개를 지나치든 상관없고, 마지막거 무시해도 괜찮다.  
*/

#include <iostream>
#include <algorithm>
#define MAX 10003

using namespace std;

int wine[MAX] = { 0, };//각 잔에 들어있는 포도주의 양.
int values[MAX] = { 0, };//선택 결과들. 인덱스 - 1 = 지나친 잔의 개수. 

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
		values[i] = max(values[i-2] + wine[i], values[i-3] + wine[i-1] + wine[i]);//2번 연속 패스하는 경우 고려x. 
		values[i] = max(values[i-1], values[i]);//2번 연속 안먹는 경우가 더 클 수 있음. 
		printf("%d ", values[i]);
	}
	 
	//printf("%d\n", values[n+2]);
	return 0;
} 
 
