/*N칸의 공간, M칸의 바구니, j개의 사과
최소한의 움직임으로 사과를 바구니에 넣으려면 바구니의 끝부분이
사과가 떨어지는 위치에 오게 하면 된다.
바구니의 끝부분만 저장*/
#include <iostream>

using namespace std;

int apple[21];
int basket[2];
int main(void) {
	int N, M, j, i, distance = 0;
	cin >> N >> M;//공간 크기, 바구니 크기
	cin >> j;//사과 개수
	for (i = 0; i < j; i++) {
		cin >> apple[i];//사과 낙하위치
	}
	//바구니의 범위
	basket[0] = 1;//바구니 왼쪽 끝
	basket[1] = M;//바구니 오른쪽 끝
	
	for (i = 0; i < j; i++) {
		int move = 0;
		if (apple[i] > basket[1]) {//오른쪽 끝보다 더 오른쪽이면
			distance += (apple[i] - basket[1]);
			basket[0] += (apple[i] - basket[1]);
			basket[1] += (apple[i] - basket[1]);
			move += 1;
			//cout << distance << endl;
		}
		else if (apple[i] < basket[0] && move == 0) {//왼쪽 끝보다 더 왼쪽이면
			distance += (basket[0] - apple[i]);
			basket[1] -= (basket[0] - apple[i]);
			basket[0] -= (basket[0] - apple[i]);
			//cout << distance << endl;
		}
		else if(apple[i] == basket[0] || apple[i] == basket[1] && move == 0){
			//cout << distance << endl;
			continue;
		}
	}
	cout << distance;
	return 0;
}