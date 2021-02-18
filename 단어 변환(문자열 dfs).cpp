#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//�ѱ��ڸ� �ٸ� �ܾ�鳢�� ��� ����.
//target���� �̵�Ƚ�� ��ȯ.
//Ʈ���� ���̰� �� ��.
bool check[51] = { false, };
int answer = 51;
//����Ʈ �Ű�����: ����ڰ� �� �ȳ����� �ش� ���� �⺻������ �޼ҵ� ����.
void dfs(string begin, string target, vector<string> words, int depth = 0){
    for(int i = 0; i < words.size(); i++){
        int cnt = 0;
        for(int j = 0; j < words[i].length(); j++){
            if(!check[i] && begin[j] != words[i][j]) cnt++;//���� �ٸ� �κ� ã��.
        }
        if(cnt == 1){
            //�� ���� �ٸ��ٸ�(��ȯ�� �����ϴٸ�)
            if(target == words[i] && answer > depth + 1){
                answer = depth + 1;
                return;
            }
            //�湮 ǥ�����ص� ���, ��� ������(Ʈ�� ������ ������) �ٽ� �湮 ǥ�� ����.
            check[i] = true;
            dfs(words[i], target, words, depth + 1);
            check[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, words);
    if(answer == 51) return 0;
    return answer;
}
