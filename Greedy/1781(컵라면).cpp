/*
Milk Scheduling ������ ������ ����
��ǥ���� ����. ���� �˰��� ��� �����ҵ� -> �ð� �ʰ�.
 
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
		if(schedule[time_limit]){//�̹� Ǯ ������ ������ �����̸�, 
			for(int i = time_limit-1; i > 0; i--){
				if(!schedule[i]){//�ش� �۾� ������� ���� ���� �� ���� ���� ������ ��ġ. 
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
		q.push(pair<int, int>(reward, -deadline));//������ε� ���� ������ �����ؾ� �ð��ʰ� x. 
	}
	printf("%d\n", scheduling());
	return 0;
}
