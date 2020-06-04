#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int range = 1, barrier = 1, tmp = 1, N;
	cin >> N;

	while (1) {
		if (range >= N)
			break;
		tmp = 6 * (barrier++); //방 개수가 6의 배수로 늘어나므로 더해줄 변수를 이렇게 설정함.
		range += tmp;
	}//range(숫자 범위)가 N을 넘지 않는 선에서
	 //숫자를 6의 배수만큼 계속 늘려줌.
	 //barrier(겹겹이 쌓인 층 개수)가 곧 답임.
	cout << barrier;
	return 0;
}