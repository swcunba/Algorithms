/*
섬 개수 문제와 유사.
상하좌우로 뭉쳐있는 배추 밀집 지역 개수를 파악하면 된다. 
*/

#include <iostream>
#include <cstring>
int map[50][50];
bool check[50][50];
int m, n, k;//m:가로, n:세로, k:배추 개수. 

int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isInMap(int y, int x){
	return ((y >= 0 && y < n) && (x >= 0 && x < m));
} 
void dfs(int y, int x){
    check[y][x] = true; //해당 지점 방문 표시


    for (int i = 0; i < 4; i++)
    {
        int newY = y + move[i][0];
        int newX = x + move[i][1];//다음 좌표 이동. 
		//다음 좌표의 값이 지도 안에 있으며 방문한 적이 없고, 값이 1인 지점이면 재귀적으로 dfs 수행. 
        if(isInMap(newY, newX) && !check[newY][newX] && map[newY][newX]) dfs(newY, newX); 
	}
}
int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d", &m, &n, &k);
		memset(check, false, sizeof(check));
		memset(map, 0, sizeof(map));
		for(int i = 0; i < k; i++){
			int c, r;
			scanf("%d %d", &c, &r);
			map[r][c] = 1;
		} 
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!check[i][j] && map[i][j]){
					dfs(i, j);//지도에서 1을 찾으면 dfs 시작. 
					cnt++;//dfs 시작 횟수가 곧 배추의 밀집 지역 개수. 
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
