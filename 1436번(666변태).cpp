//#include<iostream>
using namespace std;
int N, ord = 0;

int num_checker(int N)
{
	int tmp = 1;
	while (1)
	{
		if (tmp % 1000 == 666)
		{
			ord++;
			if (ord == N)
				break;
		}
		else if (tmp > 10)
			tmp /= 10;
		tmp++;
	}
	return tmp;
}
int main() 
{
	cin >> N;
	num_checker(N);
	
	return 0;
}
