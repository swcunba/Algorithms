/*
주어지는 수의 배열에서 위치상으로 연속되는 수만 뽑아서 최댓값 만들기
모든 수가 음수인 경우 가장 작은 수 하나만 선택.
정렬은 이용할 수 없을거 같다.

주어진 수들 다 더한 후 원소 하나씩 양 끝에서 빼나가는 방식? 
데이터 크기 100,000이고 시간제한 1초. O(log n) 알고리즘 써야함.

양수인 경우 당연히 선택하고,
음수인 경우 해당 음수 나오기 이전까지의 누적합이 해당 음수보다 크고, 뒤에 더해질 양수들의 합이 해당 음수보다 커야함. 
*/

#include <iostream>

#define MAX 100001

using namespace std;

int numbers[MAX];
int values[MAX]; 

int main(void){
	int n, sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &numbers[i]);
	}//수열 입력.
	
	for(int i = 0; i < n; i++){
		if(numbers[i] > 0){
			
		}
	}
	
}



