/*N명의 학생을 키 순서대로 줄 세우려고 함. 비교해서 정렬 시도할건데 매번 2명씩 비교하고 두 학생의 순서가 결정됨. 
줄을 세운 결과를 출력해야함(여러 방법으로 세울 수 있으면 아무거나 출력)
즉 순서를 결정해주는 알고리즘 문제.
위상정렬 사용(순서가 정해져 있는 그래프의 순서를 정해주는 알고리즘. 1을 수행해야 2를 수행할 수 있는 구조의 그래프).
큐를 통해 구현.
비교한 학생들끼리 연결.*/

#include <stdio.h>
#include <vector>
#include <queue>
 
#define MAX 32001//학생 수 범위 1부터 32000. 
using namespace std;

int n, inDegree[MAX];//inDegree: 진입 차수 정보.
vector<int> a[MAX];//그래프 구현할 인접 리스트. 
//학생들을 세운 줄을 그래프로 표현 ex) 1 -> 2 -> 3. 

void topologySort(){
	int result[MAX];
	queue <int> q;
	//진입 차수가 0인 노드를 큐에 삽입. 
	for(int i = 1; i <= n; i++){
		if(inDegree[i] == 0) q.push(i);
	}
	//정렬이 완전히 수행되려면 정확히 n개의 노드를 방문해야함.
	for(int i = 1; i<=n; i++){
		//n개를 방문하기 전에 큐가 비어버리면 사이클이 발생한 것.
		int x = q.front();//x에 큐의 가장 앞 원소 저장하고 
		q.pop();//삭제. (연결된 모든 간선 제거 과정). 
		result[i] = x;
		for(int j =0; j < a[x].size(); j++){
			int y = a[x][j];
			//새롭게 진입차수가 0이 된 정점을 큐에 삽입.
			if(--inDegree[y]==0) q.push(y);//--는 간선 제거하였으므로 진입차수 줄여주기 위함. 
		}
	} 
	for (int i = 1; i <=n; i++){
		printf("%d ", result[i]);
	}
} 
//진입차수: 해당 노드에 들어갈 수 있는 경로의 수(이산수학에서 배움). 
int main(void){
	int m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		inDegree[y]++;//진입차수 1씩 증가시켜줌. 
	}//비교하는 학생 입력. 
	topologySort();
}

 
