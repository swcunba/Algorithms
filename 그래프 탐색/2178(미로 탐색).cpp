#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int row, col;

bool map[100][100];//0�� 1. 
int check[100][100];//������ ��(���İ� ����� ��) ����� �迭.
int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};//�����̴� ����� ��(��, �Ʒ�, ������, ����).


bool isInMap(int y, int x){//�̷� �ȿ� �ִ� ������ �Ǵ����ִ� �Լ�. 
	return (y >= 0 && y < row) && (x >= 0 && x < col);
}

int bfs(){
	queue<pair<int, int> >q;//ť ����.
	int current_x = 0, current_y = 0;//������ ����. 
	q.push(pair<int, int>(current_y, current_x));//������ ť�� ����. 
	check[current_y][current_x] = 1;//������ �湮 ó��(1�� ������). 
	while(!q.empty()){
		current_y = q.front().first; 
		current_x = q.front().second;//���� ��ǥ�� ����� ��ġ ǥ��. 
		q.pop();
		
		if(current_y == row - 1 && current_x == col - 1) break;//�����ϸ� �ݺ� �ߴ�. 
		
		for(int i = 0; i < 4; i++){
			int next_x = current_x + move[i][1];
			int next_y = current_y + move[i][0];//���� ��ġ Ž��. 
			
			if(isInMap(next_y, next_x) && check[next_y][next_x] == 0 && map[next_y][next_x]){//�̷� �ȿ� �ִ� �����̸�, �湮�� �� ���� 1�� �����̶��, 
				check[next_y][next_x] = check[current_y][current_x] + 1;//�湮 ǥ��. 
				q.push(pair<int, int>(next_y, next_x));//�湮�� �� ť�� ����. 
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
			if(value == 1) map[i][j] = true;//���� 1�̸� trueǥ���ص�. 
		}
	}
	printf("%d\n", bfs());
	return 0; 
}
