/*N명의 사람들이 줄을 선다. 사람들은 자기보다 큰 사람이 왼쪽에 몇
명 있었는지만 기억한다. 사람들의 키는 1~N까지이고 모두 다르다.
input) N을 입력받고, 키가 1인 사람부터 왼쪽에 자기보다 큰 사람 몇 명인지
입력 받음.
output) 줄을 선 순서대로 '키'를 출력.

단순하게 1~N까지의 사람들을 입력받은 왼쪽에 자기보다 큰 사람 수에
맞춰서 자기가 들어갈 자리로 들어가면 될 거 같다.
모든 사람이 왼쪽부터 하나씩 탐색하며 자신이 들어갈 위치 고름.
*/
#include <iostream>
using namespace std;
int N;
int people[11];

int main(void) {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int comp;
		cin >> comp;//왼쪽에 자기보다 큰 사람 수 입력(0~N-1)
		int count = 0; //왼쪽에 자기보다 큰 사람 수 카운트
		for (int j = 1; j <= N; j++) {
			if (count == comp && people[j] == 0) {//왼쪽에 자기보다 큰 사람 수가 입력받은 값과 일치하고, 원소의 값이 0이면
				people[j] = i;//원소의 값을 NULL에서 번호 부여
				break;
			}
			if (people[j] == 0) count++;//위 조건문 충족 안되고 값만 0이라면 count 증가, c++에서 0은 NULL 값이기도 함.
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << people[i] << " ";//출력 시 공백 안만들어주면 오답 처리함
	}
	return 0;
}