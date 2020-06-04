#include <iostream>
using namespace std;
int A;
int partial_sum(void)
{
	int n = 1;
	while (1)
	{
		int copy = n;
		int sum = n;

		while (copy)
		{
			sum += copy % 10; //10으로 나눴을 때 나머지 값 더해주는 것 반복(맨 끝자리서부터 더해짐)
			copy /= 10;//일의 자리수부터 하나씩 떼어냄
		}
		if (n == A || sum == A)
			break;
		n++;
	}
	return n;
}

int main(void)
{
	int result = 0;
	cin >> A; 

	result = partial_sum();
	if (result == A)
		cout << 0 << endl;

	else
		cout << result << endl;

	return 0;
}

