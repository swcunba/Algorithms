/*
인접 리스트 활용해서 1과 친구인 애들 찾기. 
*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[501];
bool friends[501] = { false, };//친구면 true. 
int main(void){
	int n, m, result = 0;
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);//트리는 방향 그래프를 제외하고 항상 상호 연결시킬것. 
	}
	//tree[1]에 있는 원소들은 일단 초대함.
	//tree[1]의 원소들의 친구 인원 수 찾으면 된다.

	for(int i = 0; i < tree[1].size(); i++){
		int link = tree[1][i];
		friends[link] = true;
	}
	for(int i = 0; i < tree[1].size(); i++){
		int link = tree[1][i];
		for(int j = 0; j < tree[link].size(); j++){
			if(!friends[tree[link][j]]){//친구의 친구. 
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
