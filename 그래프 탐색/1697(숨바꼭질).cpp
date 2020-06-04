/*
�ִܰ�� ����. bfs ���. 
*/
#include <iostream>
#include <cstdio>//������ ���� ������ �߰��� ��� ����. 
#include <queue>
#define MAX 100001//�ε����� 0���� �����ϴ� �� ������ 1 �߰�. 

using namespace std; 

bool check[MAX];//�湮 ���� Ȯ��. 
int loc[MAX];//��� Ȯ��. 
int move[3] = {-1, 1, 2};

int n, k;
bool isInMap(int x){//���� �ȿ� �ִ� ������ �Ǵ����ִ� �Լ�. 
	return (x >= 0 && x < MAX);
}

int bfs(int start){
	queue<int> q;
	q.push(start);
	check[start] = true;
	int current = start;
	int next;
	while(!q.empty()){
		if(current == k) break;
		current = q.front();
		q.pop();
		for(int i = 0; i < 3; i++){
			if(i == 2) next = current * move[i];
			else next = current + move[i];
			
			if(isInMap(next) && !check[next]){//���� �ȿ� �ִ� �����̸�, �湮�� �� ���ٸ�, 
				check[next] = true;//�湮 ǥ��. 
				q.push(next);//�湮�� �� ť�� ����. 
				loc[next] = loc[current] + 1;
			} 
		}
	}
	return loc[k];
}
int main(void){
	scanf("%d %d", &n, &k);
	printf("%d\n", bfs(n));
	return 0;
}
