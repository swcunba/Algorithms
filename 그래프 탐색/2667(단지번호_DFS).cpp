/*
BFS와 DFS 모두 사용 가능한 문제이다.
DFS를 구현 많이 안해봤으니 DFS로 해보자. 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool map[25][25] = { false, };//탐색 여부 확인(미로). 
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
string arr[25];//문자열 배열은 원소의 각 자릿수 인덱스로 접근 가능. 결과적으로 2차원 배열과 동일해짐. 
vector <int> ans;
int n, cnt;

void dfs(int i, int j){//방문할 곳 인수로 받음. 
	map[i][j] =true;//방문 처리.
	cnt++;
	int k;
	for(k = 0; k < 4; k++){
		int next_y = i + dy[k];
		int next_x = j + dx[k];
	
		if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n)
			if(arr[next_y][next_x] == '1' && !map[next_y][next_x]) dfs(next_y, next_x);
	}
}

int main(void){
	int i, j;
	//scanf("%d", &n);
	cin >> n;//cin으로 입력하면 띄어쓰기 없이 입력된 수들을 '하나의' 수로 인식함. scanf를 사용하면서 하나의 수로 인식하게 하려면 "%1d"를 넣어주면 된다.  
	for(i = 0; i < n; i++) cin >> arr[i];
	//scanf("%d", &arr[i]);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(arr[i][j] == '1' && !map[i][j]){//아직 방문하지 않은 1이라면, 
				cnt = 0;//cnt 0으로 초기화하고, 
				dfs(i, j);//dfs수행한 후, 
				ans.push_back(cnt);//cnt를 정답 저장하는 배열에 저장. 
			}
		}
	}
	sort(ans.begin(), ans.end());//오름차순 정렬. 
	//printf("%d\n", ans.size()); //단지 개수 출력. 
	cout << ans.size() << '\n';
 	for(i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
	 //printf("%d\n", ans[i]);
	return 0;
}
