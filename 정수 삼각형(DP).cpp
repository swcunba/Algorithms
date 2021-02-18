#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[501][501];
int solution(vector<vector<int>> triangle) {
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < triangle.size(); i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] = dp[i-1][j] + triangle[i][j];//�� ���� �͸� �ջ�.
            else if(i == j) dp[i][j] = dp[i-1][i-1] + triangle[i][j];//�� ������ �͸� �ջ�.
            else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];//�߰��� �ִ� ã�Ƽ� �ջ�.
        }
    }
    int answer = dp[triangle.size()-1][0];
    for(int i = 1; i < triangle[triangle.size()-1].size(); i++){
        if(answer < dp[triangle.size()-1][i]) answer = dp[triangle.size()-1][i];
    }
    return answer;
}
