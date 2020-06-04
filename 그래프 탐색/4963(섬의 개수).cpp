/*
���� ���� = 1�� ������ �ִ� �͵��� ���� = �׷����� ������ ����. 
*/
#include <iostream>
#include <cstring>
using namespace std;

int w, h;//w: �� ����, h: �� ����. 
bool check[50][50];
int map[50][50];
int move[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

bool isInMap(int y, int x){
	return ((y >= 0 && y < h) && (x >= 0 && x < w));
} 
void dfs(int y, int x){
	if (!map[y][x] || check[y][x])
        return;
       
    check[y][x] = true; //�ش� ���� �湮 ǥ��


    for (int i = 0; i < 8; i++)
    {
        int newY = y + move[i][0];

        int newX = x + move[i][1];
                 //���� �ȿ� ������ �� �ְ� �湮���� ���� ������ ��쿡�� ���ƴٴѴ�

        if (isInMap(newY, newX))
            dfs(newY, newX);
        }
}

int main(void){
	while(1){
		cin >> w >> h;
		if(w == 0 && h == 0) break;
		memset(check, false, sizeof(check));

		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(!check[i][j] && map[i][j]){
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
