#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//유의사항: 성적이 아니라 순위이다.
vector<pair <int, int> > score;

int main(void) {
	int n, t;
	cin >> t;
	for (int i = 0; i < t; i++) {//테스트 케이스만큼 반복
		cin >> n;
		score.clear();//초기화
		int x, y;
		for (int j = 0; j < n; j++) {
			cin >> x >> y;
			score.push_back(make_pair(x, y));//페어 자료형에 각 전형 점수 입력받음
		}
		sort(score.begin(), score.end());//서류 오름차순 정렬
		int temp = score[0].second, result = 1;//서류 1등 면접 등수, 서류 1등은 무조건 합격이라 1로 시작.
		for (int j = 0; j < n; j++) {
			//서류 1등은 무조건 합격
			//서류 2등은 서류 1등보다 면접 등수 높아야함
			//서류 3등은 서류 2등보다 면접 등수 높아야함...과정 반복
			if (temp > score[j].second) {//서류 1등 면접 등수보다 높다면,
				temp = score[j].second;//결과값에 1을 추가하고, 합격할 수 있는 면접 등수 기준 갱신. 
				result += 1;
			}
		}
		cout << result << "\n";
	}
	return 0;
}
