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
	for (int i = 0; i < n; i++) {
		plugged[i] = tools[i];//처음에 꽂혀있는 기구
	}
	int result = 0, count = 0;
	//뒤에 또 쓰이는 애들을 어떻게 골라낼까, 원소 개수 카운트?
	//뽑는 횟수 = k - n - 처음부터 꽂은거 중에서 쓰는 기구 개수
	for (int i = 0; i < n; i++) {
		for (int j = n; j < k; j++) {
			if (tools[j] == plugged[i]) count++;
		}
	}
	result = k - n - count;
	cout << result;
	return 0;
}