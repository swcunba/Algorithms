/*
1������ Ž��.
N���� ����, M���� ���.
�Է¿� ���� Ʈ�� �����ϰ�, ���ͽ�Ʈ�� �˰������� 1���� ��� ���� �ּ� ��� ����.
���� ū ���� ���� ��ȣ ���, ���� ��� ���� ��ȣ ���� ī��Ʈ. 
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
	priority_queue<pair<int, int> > pq;//��� ����, ����� ���� �켱���� ť ����. 
	pq.push(make_pair(start, 0));//���� ����, ��� ť�� ����
	while (!pq.empty()) {
		int current = pq.top().first;//���� ����. 
		int distance = -pq.top().second;//���� �������� ���� ���� ������� �� �� �ִ� �������� 
		pq.pop();
		if (d[current] < distance) continue;//�ִ� �Ÿ� �ƴ� ��� ��ŵ
		for (int i = 0; i < farm[current].size(); i++) {//���� ������ ���� ���� �ϳ��� Ȯ��
			int next = farm[current][i].first;//���� ����. 
			int nextDistance = distance + farm[current][i].second;//���� ������ ���ļ� next�� ���� �� ���(���� ������ ��� �ּ� ��� + next���� ���� ���)
			//���� �ּ� ��뺸�� ���� �� �۴ٸ� �ּڰ��� ��ü
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));//���� �� �켱�ǵ��� ����ȭ
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
		farm[x].push_back(make_pair(y, 1));//��� = ����ģ ���� �����̹Ƿ�. 
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
