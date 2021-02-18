#include <string>
#include <vector>
//���� 2���� ������ ������ �κ� �簢�� ���� ����.
//���簢�� �ѷ� ���̴� 2*(������ ����+���� ����)+2*(���� ���� + ������ ����).
using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long dp[81];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    answer = 2*(dp[N] + dp[N-1]) + 2*(dp[N-1] + dp[N-2]);
    return answer;
}
