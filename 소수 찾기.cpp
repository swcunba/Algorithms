#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool primeNumberChecker(int n) {
    //�����佺�׳׽��� ü �˰��� ���� 2���� �ش� ������ �����ٱ����� ��� ���� �Ǻ�.
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
        //string number�� �ٷ� int �迭�� ������ �ƽ�Ű�ڵ� ������ ��.
        //-'0' ���ָ� �ǵ��� ���ڰ� ��.
        v.push_back(numbers[i] - '0');
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    // ��� ����� �� ã��
    do {
        for (int i = 0; i <= v.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                tmp = (tmp * 10) + v[j];
                ans.push_back(tmp);
            }
        }
        //next_permutation: �߰������� ���� ���� �����ϸ� true, �ƴ� ��� false ��ȯ.
    } while(next_permutation(v.begin(), v.end()));
    // �ߺ��� vector�� ����
    // unique�� ���ӵ� �ߺ� ���Ҹ� vector�� ���� �޺κ����� �����Ⱚ���� �����Ƿ� ���� �� ���.
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        if (primeNumberChecker(ans[i])) answer++;
    }
    return answer;
}



