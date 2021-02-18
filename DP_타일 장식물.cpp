#include <string>
#include <vector>
//이전 2개의 원소의 합으로 부분 사각형 길이 나옴.
//직사각형 둘레 길이는 2*(마지막 원소+이전 원소)+2*(이전 원소 + 이이전 원소).
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
