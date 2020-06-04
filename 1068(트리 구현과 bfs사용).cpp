/*�׷��� �Է����� �־����� �� �Է����� �־����� �������� ��忡
���� ���� ����� ���� ���
Ʈ���� �����ϴ� �Ϳ� �����غ���
Ʈ�� �������� ���� ����Ʈ�� ���� ���ȴ�.
bfsŽ���� ���� Ʈ���� Ž���ϸ� ���� ��带 ������*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> tree[51];//���� �迭 ����, ���� ����Ʈ�� �� �ε����� ���� ���� ������ �� �����Ƿ� Ʈ�� ������ �����ϴ�.
int root_node, result = 0;
int num;
bool check[51];//�湮 ���� ǥ���� ��

void bfs(int start) {
	check[start] = true;//������ �湮 ǥ��
	queue<int> q;//bfs�� ť�� ������(���Լ��� ���)
	q.push(start);//ť�� �湮�� ���(����) ����

	while (!q.empty()) {//ť�� �� ������ �ݺ�, ť�� ��� 1��ȯ �ϴϱ� !q.empty()�� ť�� �� �� 0 ��ȯ, �ݺ� �ߴ� �ȴ�.
		int node = q.front();//ť���� ���� ���� ���� ��
		q.pop();//ť���� ���� ���� ���� �� ����
		int child_cnt = 0;//�ڽ� ��� �� ����
		for (int i = 0; i < tree[node].size(); i++) {//tree[node]: ť���� ������ Ž���ϰ� �ִ� ��
			int next = tree[node][i];//���� ����Ʈ���� ���� ������ ������ �迭�� ����
			if (!check[next]) {//��: ���� 1�̶�� ��忡 2, 3, 4��� ����Ǿ� �ִٸ�
				child_cnt++;//[1][0]�� 2, [1][1]�� 3 �̷� ���̴�.
				check[next] = true;
				q.push(next);//ť�� �湮�� ��� ����
			}
		}//check[next]�� �̹湮 �����̰ų� �������� �ʴ´ٸ� false�� ���̹Ƿ� !�ٿ��� �ռ� ���� ��Ȳ�̸� ����Ǵ� ���ǹ�
		if (child_cnt == 0) result++;//�ڽ� ��� ������ ���� ��� �߰�
	}
}
int main(void) {
	int n, k;//n: ��� ����, k: ���� ��� ��ȣ
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num != -1) {//��Ʈ ��尡 �ƴ϶��
			tree[num].push_back(i);
			tree[i].push_back(num);//���� ����Ʈ�� ����� �� ǥ��
		}
		else {
			root_node = i;
		}
	}
	cin >> k;//���� ��� ��ȣ �Է�
	check[k] = true;//����Ŵϱ� �湮ó���ؼ� Ž������ ������

	if (!check[root_node]) bfs(root_node);//��Ʈ ��带 ����� �ƴϸ� Ž�� ����
	cout << result;
	return 0;
}