/*
���� ����Ʈ Ȱ���ؼ� 1�� ģ���� �ֵ� ã��. 
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[501];
bool friends[501] = { false, };//ģ���� true. 
int main(void){
	int n, m, result = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);//Ʈ���� ���� �׷����� �����ϰ� �׻� ��ȣ �����ų��. 
	}
	//tree[1]�� �ִ� ���ҵ��� �ϴ� �ʴ���.
	//tree[1]�� ���ҵ��� ģ�� �ο� �� ã���� �ȴ�.

	for(int i = 0; i < tree[1].size(); i++){
		int link = tree[1][i];
		friends[link] = true;
	}
	for(int i = 0; i < tree[1].size(); i++){
		int link = tree[1][i];
		for(int j = 0; j < tree[link].size(); j++){
			if(!friends[tree[link][j]]){//ģ���� ģ��. 
				friends[tree[link][j]] = true;
			}
		}
	}
	for(int i = 2; i <= n; i++){
		if(friends[i]) result++;
	}
	printf("%d\n", result);
	return 0;
} 
