#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int c[10000];//방문한 노드 컨테이너(dfs)
int d[10000]; //방문한 노드 컨테이너(bfs)
vector<int> a[10000];//정점 그래프 담을 컨테이너
vector<int> b[10000];
queue<int> q;
void dfs(int x) {
	if (c[x]) return;//방문한 노드라면 함수를 끝내버림
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];//인접 노드 하나씩 방문, 벡터 배열 안에는 여러 개의 값 들어감(예를 들어 a[1]에는 연결된 정점 2, 3 등이 들어갈 수 있음) 
		dfs(y);//재귀함수가 스택 구조로 구현되므로(인접 노드인 y가 다시 dfs 함수에 인수로 들어가 방문한 노드들의 배열인 c에 들어가는 과정 반복)
	}
}
void bfs(int start) {//큐에서 하나의 노드 꺼내고, 꺼낸 노드와 인접한 노드 중 방문하지 않은 노드를 방문한 뒤 큐에 삽입. 그리고 다시 큐에서 노드 꺼내는 과정 반복

	q.push(start);//시작점을 인수로 받고 방문한 노드 배열에 삽입
	d[start] = true;//시작점은 방문한 것으로 시작
	while (!q.empty()) {//큐가 빌 때까지
		int x = q.front();//큐에서 가장 위에 있는 노드 꺼냄
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];//인접한 노드들 방문
			if (!d[y]) {//방문 상태가 아니라면
				q.push(y);//큐에 담아줌
				d[y] = true;//담아준 뒤엔 방문한 것으로 처리
			}
		}
	}
}

int main(void) {
	int n, m, v;//간선 개수와 시작할 정점
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
		b[x].push_back(y);
		b[y].push_back(x);
		sort(a[x].begin(), a[x].end());
		sort(b[x].begin(), b[x].end());
		sort(a[y].begin(), a[y].end());
		sort(b[y].begin(), b[y].end());//인접한 노드 중 가까운 정점 먼저 방문하게
		//하기 위해서 오름차순 정렬시킴
	}
	
	dfs(v);//1이라는 노드에서부터 탐색 시작
	cout << '\n';
	bfs(v);
	return 0;
}