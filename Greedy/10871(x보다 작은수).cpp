#include <iostream>
using namespace std;
int num[10001];
int main(void) {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < n; i++) {
		if (num[i] < x) {
			cout << num[i] << ' ';
		}
	}
	return 0;
}