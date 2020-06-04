/*n개 공간, k번 사용, 전기용품 이름이 숫자로 주어짐
플러그를 최소한으로 뽑는 횟수
처음 n개 만큼의 전기용품이 꽂힌 채로 시작해야함.
최소한으로 뽑으려면 나중에 또 쓰일 전기용품을 뽑지 말아야함
*/

#include <iostream>

using namespace std;
int tools[100];
int plugged[100];//꽂혀있는 전기용품

int main(void) {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> tools[i];
	}
	int result = 0;
	for (int i = 0; i < k; i++) {
		bool plug = false;
		for (int j = 0; j < n; j++)
			if (plugged[j] == tools[i]) {
				plug = true;//꽂혀있으면 true
				break;
			}
		if (plug) continue;//꽂혀있으면 패스
		for (int j = 0; j < n; j++) {
			if (!plugged[j]) {//빈 값(구멍)있다면
				plugged[j] = tools[i];//다음 기기 꽂아주고
				plug = true;
				break;
			}
			//가장 나중 혹은 사용되지 않는 기기 찾기
			int idx, deviceidx = -1;
			for (int j = 0; j < n; j++) {
				int lastidx = 0;
				for (int K = i + 1; K < k; K++) {
					if (plugged[j] == tools[K]) break;
					lastidx++;
				}

				if (lastidx > deviceidx) {
					idx = j;
					deviceidx = lastidx;
				}
			}
			result++;
			plugged[idx] = tools[i];//기기 바꿔 꽂음
		}
		
	}
	cout << result << '\n';
	return 0;
}