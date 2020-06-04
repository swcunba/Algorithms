/*연산의 종류는 1, 2, 3으로 3가지이다. 주어진 n 값을 넘지 않는 선에서 1~3가지 경우의 수 중 하나를 선택해 나간다.
저번 dp문제처럼 역으로 결과를 만들어나가는 방법을 생각해보자. 주어진 n을 1, 2, 3으로 쪼갠다고 생각해보자.
데이터의 크기가 작아서 재귀함수를 이용해봐도 괜찮을 거 같다.
경우의 수들은 n이 3인 순간부터 연산의 종류가 3가지이므로 처음에 3갈래로 나뉜다. 
n은 
1일 때 1가지.
2일 때 2가지.
3일 때 4가지.까지를 기본 값으로 해서 이후로는 n의 경우의 수는 n-1, n-2, n-3 경우의 수의 합이다. 
4일 때 7가지.
5일 때 13가지.
...
n = n -1, n - 2, n - 3으로 구성되므로 선입선출 방식이 적용되는 큐를 통해 구현하면 될 거 같다. 
*/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

queue <int> q;
int result, n, count, temp = 0;

void spliter(int target){//n이 목표값임. 4 이상인 값부터 들어오게 만들었음. 스택에 n값까지 값 쌓아주다가 3개 꺼내고 그 값 모두 합할 거임. 
	int one = 1, two = 2, three = 4;
	q.push(one);
	q.push(two);
	q.push(three);
	temp = one + two + three;
	q.push(temp); 
	//큐에 1, 2, 3, 4의 값까지 들어감. 이후 5 = 4+3+2, 6 = 5+4+3...쌓아나가야 함. 
	
	while(n != count){
		if(n == 4){
			break;
		}
		else{
			q.pop(); //먼저 들어온 1, 2, 3 순으로 사라짐.
			//큐에 남아있는 3개의 원소들의 합을 다시 큐에 삽입해주면 된다.
			for(int i = 0; i < 3; i++){
				if(i == 0) one = q.front();
				if(i == 1) two = q.front();//다시 큐에 삽입할 n - 2의 값 저장.
				if(i == 2) three = q.front();//다시 큐에 삽입할 n - 3의 값 저장.
				q.pop(); 
			}
			temp = one + two + three;
			q.push(one);
			q.push(two);
			q.push(three);
			q.push(temp);
			count++;
		}
	}
	//printf("%d %d %d ", one, two, three);
	for(int i = 0; i < 4; i++){
		q.pop();//큐 초기화. 
	}
	result = temp;  
}

int main(void){
	int t;
	scanf("%d", &t);
	
	while(t--){
		n = 0, count = 4, temp = 0;
		result = 0;
		scanf("%d", &n);
		if(n == 1){
			result = 1;
			printf("%d\n", result);
			continue;
		}
		if(n == 2){
			result = 2;
			printf("%d\n", result);
			continue;
		}
		if(n == 3){
			result = 4;
			printf("%d\n", result);
			continue;
		}
		else spliter(n);
		printf("%d\n", result);
	}
	return 0;
} 
