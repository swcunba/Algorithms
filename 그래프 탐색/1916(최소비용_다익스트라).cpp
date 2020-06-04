#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;
int n, m;

vector < pair<int, int>  > tree[1001];//간선 정보, a[시작 정점](인접 정점, 비용)
int d[1001]; //최소 비용 정보 담을 배열

void dijkstra(int start) {
	d[start] = 0; //자기 자신으로 가는 비용은 0
	priority_queue<pair<int, int> > pq;//우선 순위 큐 사용해서 힙 형성(최대힙, 큰 값을 기준으로 최상단 노드 형성)
	pq.push(make_pair(start, 0));//시작 정점, 비용 큐에 삽입
	while (!pq.empty()) {
		int current = pq.top().first;//현재 노드를 큐의 최상단 노드라고 설정
		int distance = -pq.top().second;//작은 값이 최상단에 오도록 음수화했었으므로 다시 -붙여줌. 
		//printf("current = %d", current);
		pq.pop();//큐에서 최상단 꺼냄
		if (d[current] < distance) continue;//최단 거리 아닌 경우 스킵
		for (int i = 0; i < tree[current].size(); i++) {//인접 노드 하나씩 확인
			//선택된 노드의 인접 노드
			int next = tree[current][i].first;
			//printf("next = %d ", next); 
			//선택된 노드 거쳐서 인접 노드로 가는 총 비용(선택된 노드까지 드는 최소 비용 + 인접된 노드까지 가는 비용)
			int nextDistance = distance + tree[current][i].second;
			//기존 최소 비용보다 값이 더 작다면 최솟값을 교체
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));//작은 값 우선되도록 음수화
			}
		}
	}
}

int main(void){
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 1; i <= n; i++){
		d[i] = INF;
	}
	for(int i = 0; i < m; i++){
		int s, d, c;
		scanf("%d %d %d", &s, &d, &c);
		tree[s].push_back(make_pair(d, c));
	}
	int start, destination;
	scanf("%d %d", &start, &destination);
	
	dijkstra(start);
	printf("%d\n", d[destination]);
	return 0;
}


