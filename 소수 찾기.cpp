#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool primeNumberChecker(int n) {
    //에라토스테네스의 체 알고리즘에 따라 2부터 해당 숫자의 제곱근까지만 약수 여부 판별.
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
 
int solution(string numbers) {
    int answer = 0;
    vector<int> v;
    for (int i = 0; i < numbers.size(); i++) {
        //string number을 바로 int 배열에 넣으면 아스키코드 값으로 들어감.
        //-'0' 해주면 의도한 숫자가 들어감.
        v.push_back(numbers[i] - '0');
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    // 모든 경우의 수 찾기
    do {
        for (int i = 0; i <= v.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp = (tmp * 10) + v[j];
                ans.push_back(tmp);
            }
        }
        //next_permutation: 추가적으로 조합 생성 가능하면 true, 아닌 경우 false 반환.
    } while(next_permutation(v.begin(), v.end()));
    // 중복된 vector값 제외
    // unique는 연속된 중복 원소를 vector의 제일 뒷부분으로 쓰레기값으로 보내므로 정렬 후 사용.
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (primeNumberChecker(ans[i])) answer++;
    }
    return answer;
}



