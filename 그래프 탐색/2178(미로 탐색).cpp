#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int row, col;

bool map[100][100];//0과 1. 
int check[100][100];//지나온 길(거쳐간 경로의 수) 기록할 배열.
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//움직이는 경우의 수(위, 아래, 오른쪽, 왼쪽).


bool isInMap(int y, int x){//미로 안에 있는 값인지 판단해주는 함수. 
	return (y >= 0 && y < row) && (x >= 0 && x < col);
}

int bfs(){
	queue<pair<int, int> >q;//큐 선언.
	int current_x = 0, current_y = 0;//시작점 설정. 
	q.push(pair<int, int>(current_y, current_x));//시작점 큐에 삽입. 
	check[current_y][current_x] = 1;//시작점 방문 처리(1로 시작함). 
	while(!q.empty()){
		current_y = q.front().first; 
		current_x = q.front().second;//직교 좌표에 빗대어 위치 표현. 
		q.pop();
		
		if(current_y == row - 1 && current_x == col - 1) break;//도착하면 반복 중단. 
		
		for(int i = 0; i < 4; i++){
			int next_x = current_x + move[i][1];
			int next_y = current_y + move[i][0];//다음 위치 탐색. 
			
			if(isInMap(next_y, next_x) && check[next_y][next_x] == 0 && map[next_y][next_x]){//미로 안에 있는 지점이며, 방문한 적 없고 1인 구역이라면, 
				check[next_y][next_x] = check[current_y][current_x] + 1;//방문 표시. 
				q.push(pair<int, int>(next_y, next_x));//방문한 곳 큐에 삽입. 
			} 
		}
	}

	return check[row-1][col-1]; 
}

int main(void){
	scanf("%d %d", &row, &col);
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			int value;
			scanf("%1d", &value);
			if(value == 1) map[i][j] = true;//값이 1이면 true표시해둠. 
		}
	}
	printf("%d\n", bfs());
	return 0; 
}
