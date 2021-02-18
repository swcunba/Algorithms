#include <string>
#include <vector>

using namespace std;
int answer=0;
//��ͷ� dfs ����, �Է����� �־����� �����Ϳ� ���� ���� ���� ���� ����� ���� ���ڷ� ����.
void dfs(vector<int> numbers, int target, int sum, int cnt){
    if(cnt >= numbers.size()){
        if(sum == target) answer++;
        return ;
    }
    //+, - ������ ���� ��� �غ�.
    dfs(numbers, target, sum+numbers[cnt], cnt+1);
    dfs(numbers, target, sum-numbers[cnt], cnt+1);
}
int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}
//��ó: https://chozzza-diary.tistory.com/85 
