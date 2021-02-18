#include <string>
#include <vector>

using namespace std;
int answer=0;
//재귀로 dfs 구현, 입력으로 주어지는 데이터와 연산 통해 나온 값과 계산한 개수 인자로 받음.
void dfs(vector<int> numbers, int target, int sum, int cnt){
    if(cnt >= numbers.size()){
        if(sum == target) answer++;
        return ;
    }
    //+, - 가능한 연산 모두 해봄.
    dfs(numbers, target, sum+numbers[cnt], cnt+1);
    dfs(numbers, target, sum-numbers[cnt], cnt+1);
}
int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}
//출처: https://chozzza-diary.tistory.com/85 
