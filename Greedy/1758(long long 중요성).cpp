/*뒤로 갈수록 -금액 커지므로 최댓값을 얻으려면 
팁 많이 주는 사람을 앞으로 보내야한다.
따라서 팁 정렬한 후 팁 최댓값 계산*/

#include <iostream>
#include <algorithm>
using namespace std;
int p[100001];

int main(void) {
	int n;
	cin >> n;//사람 수
	for (int i = 0; i < n; i++) {
		cin >> p[i];//주려는 팁
	}
	sort(p, p + n);//팁 오름차순 정렬(많이 주는 사람 맨 뒤에)
	int minus = 0, temp = 0;//결과, 차감 금액
	long long result = 0;//스택 오버플로우 방지 위함(이거 안해서 틀렸음)
	for (int i = n - 1; i >= 0; i--) {//맨 뒤부터
		temp = p[i] - minus;
		if (temp < 0) temp = 0;
		result += temp;
		minus++;
	}
	cout << result << '\n';
	return 0;
}