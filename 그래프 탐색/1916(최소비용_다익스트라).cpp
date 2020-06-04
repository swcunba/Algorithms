#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;
int n, m;

vector < pair<int, int>  > tree[1001];//���� ����, a[���� ����](���� ����, ���)
int d[1001]; //�ּ� ��� ���� ���� �迭

void dijkstra(int start) {
	d[start] = 0; //�ڱ� �ڽ����� ���� ����� 0
	priority_queue<pair<int, int> > pq;//�켱 ���� ť ����ؼ� �� ����(�ִ���, ū ���� �������� �ֻ�� ��� ����)
	pq.push(make_pair(start, 0));//���� ����, ��� ť�� ����
	while (!pq.empty()) {
		int current = pq.top().first;//���� ��带 ť�� �ֻ�� ����� ����
		int distance = -pq.top().second;//���� ���� �ֻ�ܿ� ������ ����ȭ�߾����Ƿ� �ٽ� -�ٿ���. 
		//printf("current = %d", current);
		pq.pop();//ť���� �ֻ�� ����
		if (d[current] < distance) continue;//�ִ� �Ÿ� �ƴ� ��� ��ŵ
		for (int i = 0; i < tree[current].size(); i++) {//���� ��� �ϳ��� Ȯ��
			//���õ� ����� ���� ���
			int next = tree[current][i].first;
			//printf("next = %d ", next); 
			//���õ� ��� ���ļ� ���� ���� ���� �� ���(���õ� ������ ��� �ּ� ��� + ������ ������ ���� ���)
			int nextDistance = distance + tree[current][i].second;
			//���� �ּ� ��뺸�� ���� �� �۴ٸ� �ּڰ��� ��ü
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));//���� �� �켱�ǵ��� ����ȭ
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


