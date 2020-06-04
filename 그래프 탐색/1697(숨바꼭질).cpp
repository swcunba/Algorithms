/*
최단경로 문제. bfs 사용. 
*/
#include <iostream>
#include <cstdio>//컴파일 에러 때문에 추가한 헤더 파일. 
#include <queue>
#define MAX 100001//인덱스가 0에서 시작하는 것 때문에 1 추가. 

using namespace std; 

bool check[MAX];//방문 여부 확인. 
int loc[MAX];//경로 확인. 
int move[3] = {-1, 1, 2};

int n, k;
bool isInMap(int x){//범위 안에 있는 값인지 판단해주는 함수. 
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
			
			if(isInMap(next) && !check[next]){//범위 안에 있는 지점이며, 방문한 적 없다면, 
				check[next] = true;//방문 표시. 
				q.push(next);//방문한 곳 큐에 삽입. 
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
