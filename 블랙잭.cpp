#include <iostream>
using namespace std;

int main()
{
	int N, M;
	int A[100];
	cin >> N >> M; //앞서 선언한 두 개의 변수 값 입력
	int result = 0;
	for (int i = 0; i < N; i++) cin >> A[i]; //A배열에 순차적으로 ~

	for (int i = 0; i < N - 2; i++) //A배열 끝에서 3번째까지 ~A[i]
	{
		for (int j = i + 1; j < N - 1; j++) //A배열 끝에서 2번째까지 ~A[j]
		{
			for (int k = j + 1; k < N; k++) //A배열 끝 값까지 ~A[k]
			{
				if (A[i] + A[j] + A[k] <= M && M - (A[i] + A[j] + A[k]) < M - result) //배열에서 가져온 값들의 합이 M이하이면서 M-값들의 합이 M-result보다 작다면
				{
					result = A[i] + A[j] + A[k];// result 갱신.
				}
			}
		}
	}
	cout << result;
}
