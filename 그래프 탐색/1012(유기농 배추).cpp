/*
�� ���� ������ ����.
�����¿�� �����ִ� ���� ���� ���� ������ �ľ��ϸ� �ȴ�. 
*/

#include <iostream>
#include <cstring>
int map[50][50];
bool check[50][50];
int m, n, k;//m:����, n:����, k:���� ����. 

int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isInMap(int y, int x){
	return ((y >= 0 && y < n) && (x >= 0 && x < m));
} 
void dfs(int y, int x){
    check[y][x] = true; //�ش� ���� �湮 ǥ��


    for (int i = 0; i < 4; i++)
    {
        int newY = y + move[i][0];
        int newX = x + move[i][1];//���� ��ǥ �̵�. 
		//���� ��ǥ�� ���� ���� �ȿ� ������ �湮�� ���� ����, ���� 1�� �����̸� ��������� dfs ����. 
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
					dfs(i, j);//�������� 1�� ã���� dfs ����. 
					cnt++;//dfs ���� Ƚ���� �� ������ ���� ���� ����. 
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
