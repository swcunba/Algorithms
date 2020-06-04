/*입력: 정점 개수 v와 간선의 개수 e가 주어짐. 모든 정점에는 1부터 v까지의 번호
가 매겨진다. 둘째 줄에는 시작 정점의 번호가 주어짐. 셋째 줄부터 e개의 줄에 걸쳐
각 간선을 나타내는 세 개의 정수(시작 노드, 도착 노드, 비용) 주어짐.
서로 다른 두 정점 사이에 여러 개의 간선 존재할 수 있다.

출력: v개의 줄에 걸쳐 시작점으로부터 각 i번 정점으로의 최단 경로값을 출력
경로 없다면 INF 출력. 

사용할 알고리즘: 다익스트라 알고리즘
구현 방법: 우선순위 큐를 통해 트리를 구현하고, 배열에 최소 비용 정보 담을 것. 
우선 순위 큐를 사용할 때 pair 형이라면 <1, 2>중 1을 먼저 비교하므로 결과로 도출해야 하는 값을 1에 두어야 시간 제한에 걸리지 않을 수 있다. 
*/
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
#define INF 987654321
#define MAX_V 20004
vector < pair<int, int> > e_info[MAX_V];//간선 정보 담을 컨테이너. 원소 인덱스가 시작 정점, <비용, 도착점> 으로 구성. 
int result[MAX_V];//최단 경로 비용 담을 배열. 

void dijkstra(int start){//인수로 시작 정점을 받는다. 
	result[start] = 0;//자기 자신으로 가는 비용은 0.
	priority_queue<pair<int, int> > pq;//우선 순위 큐 사용해서 힙 형성(최대힙, 큰 값을 기준으로 최상단 노드 형성)
	pq.push(make_pair(0, start));//비용, 시작점 큐에 삽입
	while (!pq.empty()) {
		int current = pq.top().second;//현재 노드를 큐의 최상단 노드라고 설정. 시작점 먼저. 
		int distance = -pq.top().first;//비용이 작은 값이 최상단에 오도록 음수화(-붙이기 전에는 큰 값들이 위에 있음. -붙이면 절댓값 큰 애들이 작아지므로 밑으로 내려감).
		pq.pop();//큐에서 최상단 꺼냄. 
		if (result[current] < distance) continue;//최단 거리 아닌 경우 스킵.
		for (int i = 0; i < e_info[current].size(); i++) {//인접 노드 하나씩 확인.
			//선택된 노드의 인접 노드
			int next = e_info[current][i].second;
			//선택된 노드 거쳐서 인접 노드로 가는 총 비용(선택된 노드까지 드는 최소 비용 + 인접된 노드까지 가는 비용)
			int nextDistance = distance + e_info[current][i].first;
			//기존 최소 비용보다 값이 더 작다면 최솟값을 교체
			if (nextDistance < result[next]) {
				result[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));//작은 값 우선되도록 음수화
			}
		}
	} 
}

int main(void){
	int v, e, s;//정점 개수, 간선 개수, 시작점. 
	int u, d, w;//시작 정점, 도착 정점, 비용. 
	scanf("%d %d %d", &v, &e, &s);//정점 개수와 간선 개수 입력.//시작 정점 입력.
	for(int i = 1; i <= v; i++){
		result[i] = INF;//연결된 거 없으면 INF. 
	}
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &u, &d, &w);
		e_info[u].push_back(make_pair(w, d));//출발점, 도착점, 비용 정보 입력 
	}
	dijkstra(s);
	for(int i = 1; i <= v; i++){
		if (result[i] == INF){
			printf("%s\n", "INF");
		}
		else printf("%d\n", result[i]);
	}
	return 0;
} 
