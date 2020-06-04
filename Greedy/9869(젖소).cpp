/*
스케줄링 문제 -> 종료 시점이 빠른 것 우선탐색
우유 추출 시간은 모두 동일하게 1.
따라서, 데드라인이 빠른 젖소 먼저 확인.
데드라인 빠른 젖소 중에서도 가중치(우유 양)가 높은 젖소 우선 선택. 

우선 순위 큐를 페어 자료형으로 선언. 데드라인 같다면 우유 양 많은 게 상단으로 옴. 
<데드라인, 우유 양>으로 두고, 데드라인에 - 붙여서 데드라인 빠른 애들 위로. 
시간은 0에서부터 시작. 
--------------------------------------------------------------------------틀림

앞에 젖소들을 포기하는게 이득인 경우가 고려 되지 않았음.
가중치 큰 순으로 정렬하고, 
데드라인 데드라인에 딱 맞게 작업 배치 시작.
다음 소의 데드라인이 같다면 그 앞에 배치
 
*/

#include <iostream>
#include <queue> 

using namespace std;

int n, result = 0;
bool schedule[10001]; 
priority_queue<pair<int, int> >q;

int optimalMilking(){
	while(!q.empty()){
		int time_limit = q.top().second;
		int milking = q.top().first;
		q.pop();
		if(schedule[time_limit]){//이미 배치된 작업이 있다면, 
			for(int i = time_limit-1; i > 0; i--){//앞에 작업할 수 있는 시간이 있나 탐색. 
				if(!schedule[i]){//아직 배치 안된 지점이면, 
					schedule[i] = true;
					result += milking; 
					break;
				}
			}
		}
		else{
			schedule[time_limit] = true;
			result += milking;
		}
	} 
	return result;
}

int main(void){
	scanf("%d", &n);
	for(int i =0; i < n; i++){
		int milk, deadline;
		scanf("%d %d", &milk, &deadline);
		q.push(pair<int, int>(milk, deadline));//데드라인에 -붙여서 가장 참을성 없는 젖소 우선순위 큐의 상단으로 보냄. 
	}
	printf("%d\n", optimalMilking());
	return 0;
}
