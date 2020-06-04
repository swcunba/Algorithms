/*2명의 여학생과 1명의 남학생으로 대회 팀을 구성해야함
N명의 여학생 M명의 남학생이 있고 이 중 K명은 인턴쉽에 참가해야함
인턴쉽 참가하면 대회엔 참가 불가

시간 제한 1초, 데이터 크기는 400, 연산 좀 많아져도 괜찮을거 같다.
N, M, K가 주어질 때 만들 수 있는 '최대 팀의 수'

인턴을 보내는 학생을 고르는 기준을 정하는게 핵심
여학생의 수가 남학생보다 2배 이상 많은 경우는 남학생 수에 의해
팀의 수 결정되고 이외의 경우는 n/2로 팀의 수가 정해진다.
따라서 전자의 경우는 여학생을 인턴 보내고 후자의 경우 남자를
인턴 보낸다.*/
#include <iostream>
using namespace std;
int main(void) {
	int n, m, k;
	cin >> n >> m >> k;
	int team = 0;
	while (k) {
		if (n >= 2 * m) {
			n--;
			k--;
		}
		else {
			m--;
			k--;
		}
		if (k == 0) {
			if (n >= 2 * m) team = m;
			else team = n / 2;
		}
	}
	cout << team;
	return 0;
}
//오답이다(이유는 모르겠다)

/*해답은 다음과 같다.*/
#include <iostream>
using namespace std;
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	int max = 0;
	while (N >= 2 && M >= 1) {//팀을 만들 최소한의 인원이 있다면
		N -= 2;
		M--;
		max++;//팀 만들고 팀 최대수 1증가
	}
	while (N + M < K) {//학생의 수가 k보다 작다면
		N += 2;
		M++;
		max--;//팀을 해체시키고 여학생 2명 남학생 1명씩 돌려받음
	}
	cout << max << endl;
	return 0;
}