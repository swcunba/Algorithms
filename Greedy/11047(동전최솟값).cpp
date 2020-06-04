#include <iostream>
#include <vector> //배열 크기를 변수로 받기 위함
using namespace std;
int main(void) {
	int N, K, i, result = 0;
	cin >> N >> K;
	vector<int> coins;
	for (i = 0; i < N; i++) {
		int x;
		cin >> x;
		coins.push_back(x);//x에 동전 크기 입력 받아서 컨테이너에 추가
	}
	for (i = coins.size() - 1; i >= 0; i--) {//사이즈 함수로 안나타내면 에러 발생(이유 모르겠음)
		if (K >= coins[i]) {
			result += K / coins[i];
			K -= coins[i] * (K / coins[i]); //괄호 안쓰면 약분되서 계산 오류남
		}
	}
	cout << result;
	return 0;
}