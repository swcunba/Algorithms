/*
�����ٸ� ���� -> ���� ������ ���� �� �켱Ž��
���� ���� �ð��� ��� �����ϰ� 1.
����, ��������� ���� ���� ���� Ȯ��.
������� ���� ���� �߿����� ����ġ(���� ��)�� ���� ���� �켱 ����. 

�켱 ���� ť�� ��� �ڷ������� ����. ������� ���ٸ� ���� �� ���� �� ������� ��. 
<�������, ���� ��>���� �ΰ�, ������ο� - �ٿ��� ������� ���� �ֵ� ����. 
�ð��� 0�������� ����. 
--------------------------------------------------------------------------Ʋ��

�տ� ���ҵ��� �����ϴ°� �̵��� ��찡 ��� ���� �ʾ���.
����ġ ū ������ �����ϰ�, 
������� ������ο� �� �°� �۾� ��ġ ����.
���� ���� ��������� ���ٸ� �� �տ� ��ġ
 
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
		if(schedule[time_limit]){//�̹� ��ġ�� �۾��� �ִٸ�, 
			for(int i = time_limit-1; i > 0; i--){//�տ� �۾��� �� �ִ� �ð��� �ֳ� Ž��. 
				if(!schedule[i]){//���� ��ġ �ȵ� �����̸�, 
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
		q.push(pair<int, int>(milk, deadline));//������ο� -�ٿ��� ���� ������ ���� ���� �켱���� ť�� ������� ����. 
	}
	printf("%d\n", optimalMilking());
	return 0;
}
