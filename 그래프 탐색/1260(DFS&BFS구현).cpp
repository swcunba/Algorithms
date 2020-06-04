#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int c[10000];//�湮�� ��� �����̳�(dfs)
int d[10000]; //�湮�� ��� �����̳�(bfs)
vector<int> a[10000];//���� �׷��� ���� �����̳�
vector<int> b[10000];
queue<int> q;
void dfs(int x) {
	if (c[x]) return;//�湮�� ����� �Լ��� ��������
	c[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];//���� ��� �ϳ��� �湮, ���� �迭 �ȿ��� ���� ���� �� ��(���� ��� a[1]���� ����� ���� 2, 3 ���� �� �� ����) 
		dfs(y);//����Լ��� ���� ������ �����ǹǷ�(���� ����� y�� �ٽ� dfs �Լ��� �μ��� �� �湮�� ������ �迭�� c�� ���� ���� �ݺ�)
	}
}
void bfs(int start) {//ť���� �ϳ��� ��� ������, ���� ���� ������ ��� �� �湮���� ���� ��带 �湮�� �� ť�� ����. �׸��� �ٽ� ť���� ��� ������ ���� �ݺ�

	q.push(start);//�������� �μ��� �ް� �湮�� ��� �迭�� ����
	d[start] = true;//�������� �湮�� ������ ����
	while (!q.empty()) {//ť�� �� ������
		int x = q.front();//ť���� ���� ���� �ִ� ��� ����
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];//������ ���� �湮
			if (!d[y]) {//�湮 ���°� �ƴ϶��
				q.push(y);//ť�� �����
				d[y] = true;//����� �ڿ� �湮�� ������ ó��
			}
		}
	}
}

int main(void) {
	int n, m, v;//���� ������ ������ ����
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
		sort(b[y].begin(), b[y].end());//������ ��� �� ����� ���� ���� �湮�ϰ�
		//�ϱ� ���ؼ� �������� ���Ľ�Ŵ
	}
	
	dfs(v);//1�̶�� ��忡������ Ž�� ����
	cout << '\n';
	bfs(v);
	return 0;
}