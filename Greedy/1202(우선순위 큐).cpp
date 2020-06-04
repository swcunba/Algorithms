/*n개 보석, k개 가방, 가방에는 무게 한도 존재
보석에는 무게와 가격이라는 정보
보석 가격 최대 합
일단 가격을 기준으로 오름차순 정렬하고 용량이 안넘치는 선에서 선택
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int bag[300001];
vector<pair <int, int> > jewel;
priority_queue<int> q;//max_heap 사용으로 시간 복잡도 낮출 수 있음. heap은 이진 트리를 오름or내림차순으로 구성한 형태를 말한다.
//큐는 선입선출이지만 우선순위 큐는 값이 큰 걸 우선순위를 높게
//잡아서 큰 값을 먼저 내보냄. 즉, 알아서 내림차순 정렬을 함
int main(void) {
	int n, k, x, y;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		jewel.push_back(make_pair(x, y));
	}
	sort(jewel.begin(), jewel.end());//보석 무게 기준 오름차순 정렬
	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	sort(bag, bag+k);//가방 무게 오름차순 정렬(작은거 먼저 쓰도록)
	long long result = 0;
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && jewel[idx].first <= bag[i]) {
			//무게 기준 충족하는 보석 다 넣음(무게 작은거부터 들어감)
			q.push(jewel[idx++].second);//큐에는 가격 정보만 넣음
		}
		//가격을 우선순위 큐에 넣었으니 가장 위에 가장 비싼 보석
		if (!q.empty()) {
			result += q.top();
			q.pop();//맨 앞의 원소 삭제(꺼냄), 담았으니까 고려 안하기 위해서
		}
	}
	cout << result;
	return 0;
}//시간 초과, 값을 없애주는게 아니라 더이상 안봐도 되게 만들어야함
