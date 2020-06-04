/*
Milk Scheduling 문제와 동일한 조건
목표값도 동일. 같은 알고리즘 사용 가능할듯 -> 시간 초과.
 
*/
#include <iostream>
#include <queue>

using namespace std;

int n, result = 0;
bool schedule[200001] = { false, }; 
priority_queue<pair<int, int> >q;

int scheduling(){
	while(!q.empty()){
		int ramyeon = q.top().first;
		int time_limit = -q.top().second;
		q.pop();
		if(schedule[time_limit]){//이미 풀 문제가 정해진 시점이면, 
			for(int i = time_limit-1; i > 0; i--){
				if(!schedule[i]){//해당 작업 데드라인 이전 시점 중 가장 늦은 시점에 배치. 
					schedule[i] = true;
					result += ramyeon;
					break;
				}
			}
		}
		else{
			schedule[time_limit] = true;
			result += ramyeon;
		} 
	}
	return result;
}

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int deadline, reward;
		scanf("%d %d", &deadline, &reward); 
		q.push(pair<int, int>(reward, -deadline));//데드라인도 빠른 순으로 정렬해야 시간초과 x. 
	}
	printf("%d\n", scheduling());
	return 0;
}
