/*
1번부터 탐색.
N개의 정점, M개의 경로.
입력에 따라 트리 생성하고, 다익스트라 알고리즘으로 1부터 모든 정점 최소 비용 산출.
제일 큰 값의 정점 번호 출력, 같은 비용 정점 번호 개수 카운트. 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector < pair <int, int> > farm [20001];
int d[20001];
int n, m;
int INF = 987654321; 

void dijkstra(int start){
	d[start] = 0;
	priority_queue<pair<int, int> > pq;//출발 정점, 비용을 담을 우선순위 큐 선언. 
	pq.push(make_pair(start, 0));//시작 정점, 비용 큐에 삽입
	while (!pq.empty()) {
		int current = pq.top().first;//현재 정점. 
		int distance = -pq.top().second;//현재 정점에서 가장 작은 비용으로 갈 수 있는 정점으로 
		pq.pop();
		if (d[current] < distance) continue;//최단 거리 아닌 경우 스킵
		for (int i = 0; i < farm[current].size(); i++) {//현재 정점의 인접 정점 하나씩 확인
			int next = farm[current][i].first;//인접 정점. 
			int nextDistance = distance + farm[current][i].second;//현재 정점을 거쳐서 next로 가는 총 비용(현재 노드까지 드는 최소 비용 + next까지 가는 비용)
			//기존 최소 비용보다 값이 더 작다면 최솟값을 교체
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));//작은 값 우선되도록 음수화
			}
		}
	}
}

int main(void){
	int cnt = 1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) d[i] = INF;
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		farm[x].push_back(make_pair(y, 1));//비용 = 지나친 길의 개수이므로. 
		farm[y].push_back(make_pair(x, 1));
	}
	dijkstra(1);
	int result = d[1];
	int idx = 1;
	for(int i = 1; i <= n; i++){
		if(result < d[i]){
			result = d[i];
			cnt = 1;
			idx = i;
		}
		else if(result == d[i]) cnt++;
	}
	printf("%d %d %d\n", idx, result, cnt);
	return 0;
}
