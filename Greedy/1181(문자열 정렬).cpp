/*알파벳 소문자로 이루어진 N개의 단어가 들어오면 다음의 조건따라
정렬하기
1. 길이가 짧은 것
2. 길이가 같으면 사전 순
3. 같은 단어는 한 번만 출력
길이 짧은 순은 알겠는데 사전 순 정렬은 어쩌지*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a[20000];
int n;

bool compare(string a, string b) {
	//길이 짧은 단어 먼저
	if (a.length() < b.length())
		return 1;//우선순위 높임
	else if (a.length() > b.length())
		return 0;//우선순위 낮춤
	//길이 같으면 사전 순
	else
		return a < b;//비교 연산자 넣으면 자동으로 사전 순으로 정렬해줌
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		//동일 단어는 패스
		if (i > 0 && a[i] == a[i - 1]) {
			continue;
		}
		else {
			cout << a[i] << '\n';
		}
	}
	return 0;
}