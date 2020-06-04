#include <iostream>
#include <algorithm>

using namespace std;

int INF = 987654321;
int cost[101][101];
int n, m;

void floydWarshall(){
	//��� �׷��� �ʱ�ȭ.
	int d[n+1][n+1];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			d[i][j] = cost[i][j];//ó���� ���� ��� ��� ������ �����ϰ� ����. 
		}
	} 
	//k�� ���İ��� ��带 ��Ÿ����.
	for(int k = 0; k < n; k++){
		//i�� ��߳��.
		 for(int i = 0; i < n; i++){
		 	//j�� �������.
			 for(int j = 0; j < n; j++){
			 	if(d[i][k] + d[k][j] < d[i][j]){//k�� ���İ��� ����� ����� �� �۴ٸ� ��� �׷��� �� �ٲ���. 
			 		d[i][j] = d[i][k] + d[k][j];
				 }
			 } 
		 }
	} 
	//��� ���.
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
