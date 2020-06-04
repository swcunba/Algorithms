/*기타줄을 사는 선택지는 6개 패키지, 낱개 두 가지이다.
낱개로 살 때 가장 싼 가격과 6개 패키지 중 가장 싼
값을 파악하면 될 거 같다.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int single[100], bundle[100];//낱개 가격과 세트 가격 담을 컨테이너
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> bundle[i] >> single[i];
		//기타줄 가격 입력
	}
	//세트 가격 기준으로 오름차순 정렬
	sort(single, single + m);
	sort(bundle, bundle + m);
	int b_cheap = bundle[0], s_cheap = single[0], charge = 0;//b_cheap: 패키지 중 가장 싼 가격, s_cheap: 낱개 중 가장 싼 가격
	//페어 자료형으로 선언하고 정렬하니 왜인지는 모르겠으나 오름차순 정렬이 되지 않음
	//cout << s_cheap << b_cheap << '\n';
	//패키지 가장 싼 가격과 낱개 가장 싼 가격 선정.
	//n%6 == 0이고, 패키지가 더 싸다면 패키지로 모두 구매
	if (b_cheap < s_cheap * 6 && n % 6 == 0) {
		charge = b_cheap * n / 6;
	}
	/*패키지가 낱개보다 싸더라도
	끊어진 기타줄의 수가 6으로 나누어떨어지지 않고,
	6으로 나눈 나머지만큼 낱개로 산 가격이 패키지 값보다 작다면
	패키지와 낱개 섞어 사야함.*/
	else if (b_cheap < s_cheap * 6 && n % 6 != 0 && (n % 6) * s_cheap <= b_cheap) {
		charge = (n / 6) * b_cheap + (n % 6) * s_cheap;
	}
	/*기타줄의 수가 6으로 나누어떨어지지 않고 패키지 가격이 더 싼데
	n%6만큼 낱개로 산 가격이 패키지 값보다 크다면 패키지로만 사면 된다.*/
	else if (b_cheap < s_cheap * 6 && n % 6 != 0 && (n % 6) * s_cheap > b_cheap) {
		charge = (n / 6) * b_cheap + b_cheap;
	}
	//낱개로 사는게 가장 싼 경우 그냥 낱개로 사면 됨
	else{
		charge = s_cheap*n;
	}
	cout << charge;
	return 0;
}