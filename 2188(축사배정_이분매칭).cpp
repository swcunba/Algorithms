/*
m개의 칸을 가진 축사.
한 칸에 최대 한 마리의 소만 들어갈 수 있음.
n마리의  소가 있고, 각 소는 희망하는 0~m개의 칸이 있다. 
*/
#include <stdio.h>
#include <vector>
#define MAX 201
using namespace std;

int n, m, s;
vector <int> cows[MAX];//소가 희망하는 축사 칸 정보.
int select[MAX];//~칸에 들어간 소가 몇 번 소인지. 
bool check[MAX];//확인 여부.
 
bool dfs(int x){//1번 소부터 n번 소 혹은 칸의 번호가 인수. 들어갈 수 있으면 true, 아니면 false. 
	//연결된 모든 노드에 대해서 들어갈 수 있는 시도.
	for(int i = 0; i < cows[x].size(); i++){//소들의 정보(인접 리스트) 모두 살피기. 
		int t = cows[x][i];//살펴보고 있는 소가 갈 수 있는  축사 칸 중 하나(노드). 
		if(check[t]) continue;//이미 처리한 칸은 더 이상 볼 필요가 없음.
		check[t] = true;//살펴본 소는 true.
		//선택되지 않은 칸이거나(==0), 점유 노드에 더 들어갈 공간이 있는 경우(또 다른 곳에 배정될 수 있으면 true를 반환하므로).
		if(select[t] == 0 || dfs(select[t])){//선택을 못받아 0이거나 해당 소가  다른 곳과 매칭 가능한지 확인. //dfs(select(t))함으로써 다른 칸 갈 수 있는지 확인. 
			select[t] = x;//소를 축사 칸에 배정함. 
			return true; //소가 칸에 배정되면 true를 반환. 
		} 
	} 
	return false;
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &s);
		for(int j = 1; j <= s; j++){
			int k;
			scanf("%d", &k);
			cows[i].push_back(k);
		}
	} 
	int count = 0;
	for(int i = 1; i <= n; i++){
		fill(check, check + MAX, false);//check 배열을 false로 다 채워넣고. 
		if(dfs(i)) count++;//dfs 함수가 true를 반환한다면(소가 들어갈 수 있다면), 카운트++. 
	}
	printf("%d\n", count);//배정될 수 있는 소가 몇 마리인지 출력된다. 
	return 0;
}
