#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[100001];
int n;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < a[i] * (n - i)) 
			max = a[i] * (n - 1);
	}
	cout << max;
	return 0;
}