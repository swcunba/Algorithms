/*N개의 회의, 회의 끝과 동시에 시작 가능. 할 수 있는 회의 수
최댓값.
회의를 최대로 하려면 회의의 끝과 시간 간의 간격 최소화 해야함
빨리 끝나는 회의들만 보면 어떨까*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int> >meeting;
int mBegin[100000], mEnd[100000];//회의 시작, 끝 시간
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mBegin[i] >> mEnd[i];
		//회의 시작과 끝 시간 입력
	}
	for (int i = 0; i < n; i++) {
		meeting.push_back(make_pair(mEnd[i], mBegin[i]));//끝나는 시간을 오름차순 정렬하기 위해 앞에 끝나는 시간을 둠
	}
	int earliest = 0, selected = 0;//earliest는 다음 회의 시작 가능한 가장 빠른 시간, selected는 선택된 회의 수
	sort(meeting.begin(), meeting.end());//오름차순 정렬
	for (int i = 0; i < n; i++) {
		int meetingBegin = meeting[i].second, meetingEnd = meeting[i].first;
		if (earliest <= meetingBegin) {//earliest가 회의 시작 시간보다 이르거나 같으면
			earliest = meetingEnd;//earliest를 회의가 끝나는 시간으로 갱신
			selected++;
		}
	}
	cout << selected;
	return 0;
}