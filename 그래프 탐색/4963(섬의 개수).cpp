/*
섬의 개수 = 1이 인접해 있는 것들의 개수 = 그래프의 연결요소 개수. 
*/
#include <iostream>
#include <cstring>
using namespace std;

int w, h;//w: 열 개수, h: 행 개수. 
bool check[50][50];
int map[50][50];
int move[8][2] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

bool isInMap(int y, int x){
	return ((y >= 0 && y < h) && (x >= 0 && x < w));
} 
void dfs(int y, int x){
	if (!map[y][x] || check[y][x])
        return;
       
    check[y][x] = true; //해당 지점 방문 표시


    for (int i = 0; i < 8; i++)
    {
        int newY = y + move[i][0];

        int newX = x + move[i][1];
                 //범위 안에 움직일 수 있고 방문하지 않은 지점일 경우에만 돌아다닌다

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
