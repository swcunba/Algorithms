#include <iostream>
using namespace std;

int main()
{
	int N, M;
	int A[100];
	cin >> N >> M; //�ռ� ������ �� ���� ���� �� �Է�
	int result = 0;
	for (int i = 0; i < N; i++) cin >> A[i]; //A�迭�� ���������� ~

	for (int i = 0; i < N - 2; i++) //A�迭 ������ 3��°���� ~A[i]
	{
		for (int j = i + 1; j < N - 1; j++) //A�迭 ������ 2��°���� ~A[j]
		{
			for (int k = j + 1; k < N; k++) //A�迭 �� ������ ~A[k]
			{
				if (A[i] + A[j] + A[k] <= M && M - (A[i] + A[j] + A[k]) < M - result) //�迭���� ������ ������ ���� M�����̸鼭 M-������ ���� M-result���� �۴ٸ�
				{
					result = A[i] + A[j] + A[k];// result ����.
				}
			}
		}
	}
	cout << result;
}
