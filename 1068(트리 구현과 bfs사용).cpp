/*그래프 입력으로 주어졌을 때 입력으로 주어지는 지워지는 노드에
따라 리프 노드의 개수 출력
트리를 구현하는 것에 집중해보자
트리 구현에는 인접 리스트가 자주 사용된다.
bfs탐색을 통해 트리를 탐색하며 리프 노드를 세보자*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> tree[51];//벡터 배열 선언, 인접 리스트는 각 인덱스에 여러 값을 저장할 수 있으므로 트리 구현에 적절하다.
int root_node, result = 0;
int num;
bool check[51];//방문 여부 표시할 곳

void bfs(int start) {
	check[start] = true;//시작점 방문 표시
	queue<int> q;//bfs는 큐로 구현됨(선입선출 방식)
	q.push(start);//큐에 방문한 노드(시작) 삽입

	while (!q.empty()) {//큐가 빌 때까지 반복, 큐가 비면 1반환 하니까 !q.empty()는 큐가 빌 때 0 반환, 반복 중단 된다.
		int node = q.front();//큐에서 가장 먼저 들어온 애
		q.pop();//큐에서 가장 먼저 들어온 애 꺼냄
		int child_cnt = 0;//자식 노드 셀 변수
		for (int i = 0; i < tree[node].size(); i++) {//tree[node]: 큐에서 꺼내서 탐색하고 있는 애
			int next = tree[node][i];//인접 리스트에서 성분 접근은 이차원 배열과 동일
			if (!check[next]) {//예: 만약 1이라는 노드에 2, 3, 4노드 연결되어 있다면
				child_cnt++;//[1][0]은 2, [1][1]은 3 이런 식이다.
				check[next] = true;
				q.push(next);//큐에 방문한 노드 삽입
			}
		}//check[next]가 미방문 상태이거나 존재하지 않는다면 false일 것이므로 !붙여서 앞서 말한 상황이면 실행되는 조건문
		if (child_cnt == 0) result++;//자식 노드 없으면 리프 노드 추가
	}
}
int main(void) {
	int n, k;//n: 노드 개수, k: 지울 노드 번호
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num != -1) {//루트 노드가 아니라면
			tree[num].push_back(i);
			tree[i].push_back(num);//인접 리스트로 연결된 것 표현
		}
		else {
			root_node = i;
		}
	}
	cin >> k;//지울 노드 번호 입력
	check[k] = true;//지울거니깐 방문처리해서 탐색에서 배제함

	if (!check[root_node]) bfs(root_node);//루트 노드를 지운게 아니면 탐색 시작
	cout << result;
	return 0;
}