#include <iostream>
#include <algorithm>

using namespace std;

int INF = 987654321;
int cost[101][101];
int n, m;

void floydWarshall(){
	//결과 그래프 초기화.
	int d[n+1][n+1];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			d[i][j] = cost[i][j];//처음엔 기존 경로 비용 정보와 동일하게 시작. 
		}
	} 
	//k는 거쳐가는 노드를 나타낸다.
	for(int k = 0; k < n; k++){
		//i는 출발노드.
		 for(int i = 0; i < n; i++){
		 	//j는 도착노드.
			 for(int j = 0; j < n; j++){
			 	if(d[i][k] + d[k][j] < d[i][j]){//k를 거쳐가는 경우의 비용이 더 작다면 결과 그래프 값 바꿔줌. 
			 		d[i][j] = d[i][k] + d[k][j];
				 }
			 } 
		 }
	} 
	//결과 출력.
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", d[i][j]);
		}
		printf("\n");
	} 
} 
int main(void){
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if(cost[x][y]) cost[x][y] = min(cost[x][y], z);
		else cost[x][y] = z;
	}
	floydWarshall();
	return 0;
}
