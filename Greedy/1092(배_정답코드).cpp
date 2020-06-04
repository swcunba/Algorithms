//내가 제출한 코드와의 차이점: 옮긴 박스에 대해서 check를 통한 추가적인 연산을 수행하지 않아도 되도록 짜여져있다.
//그리고 옮긴 박스를 자료구조에서 아예 삭제시켜버린다. 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
	int m, n; //m은 크레인 개수, n은 상자 갯수
	int num; //각 벡터의 요소
	int cnt = 0; //몇 분만에 옮겼는지
	vector<int> v1, v2; //v1은 크레인 정보, v2는 상자 정보
	
	//크래인 정보 입력
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		v1.push_back(num);
	}
	
	//박스 정보 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v2.push_back(num);
	}
 
	//내림차순으로 정렬
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());
 
	if (v2[0] > v1[0]) { //들 수 있는 최대 무게보다 무거운 상자가 있는 경우
		cout << -1;
	}
	else { //그 외의 경우
		while (v2.size()) { //상자의 갯수가 0이 되기 전까지 반복
			int index = 0; //크레인의 순서
			for (int i = 0; i < v2.size(); i++) { //박스를 반복하며 탐색
				if (index == v1.size()) { //크레인을 다 순회하여 박스를 담을 수 없는 경우
					break; //탈출
				}
				if (v1[index] >= v2[i]) { //크레인이 들 수 있는 무게의 박스이면, 
					index++; //해당 크레인에 박스를 할당하고, 크레인의 순서를 증가
					v2.erase(v2.begin() + i); //크레인으로 옮긴 상자를 삭제
					i = i - 1; //사라진 자리로 다음 상자가 이동하니까 인덱스를 하나 줄여야 인덱스 값 유지된다.
				}
			}
			cnt++; //옮긴 시간
		}
		cout << cnt;
	}
}
