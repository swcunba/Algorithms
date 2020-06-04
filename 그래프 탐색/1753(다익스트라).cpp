/*�Է�: ���� ���� v�� ������ ���� e�� �־���. ��� �������� 1���� v������ ��ȣ
�� �Ű�����. ��° �ٿ��� ���� ������ ��ȣ�� �־���. ��° �ٺ��� e���� �ٿ� ����
�� ������ ��Ÿ���� �� ���� ����(���� ���, ���� ���, ���) �־���.
���� �ٸ� �� ���� ���̿� ���� ���� ���� ������ �� �ִ�.

���: v���� �ٿ� ���� ���������κ��� �� i�� ���������� �ִ� ��ΰ��� ���
��� ���ٸ� INF ���. 

����� �˰���: ���ͽ�Ʈ�� �˰���
���� ���: �켱���� ť�� ���� Ʈ���� �����ϰ�, �迭�� �ּ� ��� ���� ���� ��. 
�켱 ���� ť�� ����� �� pair ���̶�� <1, 2>�� 1�� ���� ���ϹǷ� ����� �����ؾ� �ϴ� ���� 1�� �ξ�� �ð� ���ѿ� �ɸ��� ���� �� �ִ�. 
*/
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;
#define INF 987654321
#define MAX_V 20004
vector < pair<int, int> > e_info[MAX_V];//���� ���� ���� �����̳�. ���� �ε����� ���� ����, <���, ������> ���� ����. 
int result[MAX_V];//�ִ� ��� ��� ���� �迭. 

void dijkstra(int start){//�μ��� ���� ������ �޴´�. 
	result[start] = 0;//�ڱ� �ڽ����� ���� ����� 0.
	priority_queue<pair<int, int> > pq;//�켱 ���� ť ����ؼ� �� ����(�ִ���, ū ���� �������� �ֻ�� ��� ����)
	pq.push(make_pair(0, start));//���, ������ ť�� ����
	while (!pq.empty()) {
		int current = pq.top().second;//���� ��带 ť�� �ֻ�� ����� ����. ������ ����. 
		int distance = -pq.top().first;//����� ���� ���� �ֻ�ܿ� ������ ����ȭ(-���̱� ������ ū ������ ���� ����. -���̸� ���� ū �ֵ��� �۾����Ƿ� ������ ������).
		pq.pop();//ť���� �ֻ�� ����. 
		if (result[current] < distance) continue;//�ִ� �Ÿ� �ƴ� ��� ��ŵ.
		for (int i = 0; i < e_info[current].size(); i++) {//���� ��� �ϳ��� Ȯ��.
			//���õ� ����� ���� ���
			int next = e_info[current][i].second;
			//���õ� ��� ���ļ� ���� ���� ���� �� ���(���õ� ������ ��� �ּ� ��� + ������ ������ ���� ���)
			int nextDistance = distance + e_info[current][i].first;
			//���� �ּ� ��뺸�� ���� �� �۴ٸ� �ּڰ��� ��ü
			if (nextDistance < result[next]) {
				result[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));//���� �� �켱�ǵ��� ����ȭ
			}
		}
	} 
}

int main(void){
	int v, e, s;//���� ����, ���� ����, ������. 
	int u, d, w;//���� ����, ���� ����, ���. 
	scanf("%d %d %d", &v, &e, &s);//���� ������ ���� ���� �Է�.//���� ���� �Է�.
	for(int i = 1; i <= v; i++){
		result[i] = INF;//����� �� ������ INF. 
	}
	for(int i = 0; i < e; i++){
		scanf("%d %d %d", &u, &d, &w);
		e_info[u].push_back(make_pair(w, d));//�����, ������, ��� ���� �Է� 
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
