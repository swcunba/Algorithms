#include <iostream>
using namespace std;
int main(void) {
	int price, change, result = 0;
	int coins[6] = { 500, 100, 50, 10, 5, 1 };
	cin >> price;
	change = 1000 - price;
	for (int i = 0; i < 6; i++) {
		if (coins[i] <= change) {
			result += change / coins[i];
			change -= coins[i]*(change/coins[i]);
		}
	}
	cout << result;
	return 0;
}