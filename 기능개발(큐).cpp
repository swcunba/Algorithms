#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i = 0; i < progresses.size(); i++){
        int remain;
        if((100 - progresses[i]) % speeds[i] != 0){
            remain = (100 - progresses[i]) / speeds[i] + 1;
        }
        else remain = (100 - progresses[i]) / speeds[i];
        q.push(remain);
    }
    int cnt = 0;
    int cur = q.front();
    while(!q.empty()){
        q.pop();
        cnt++;
        if(cur < q.front() || q.empty()){
            //�� �۾� �ϼ��ñⰡ �� �۾����� ���� ��� �ٸ� �� ����.
            //(answer �迭�� ���� �־��ְ� ������ �Ǵ� �ϼ��ð� ��ü)
            //(answer[100]�� ���� �޸� ���� �Ҵ��� �迭 �ƴ϶� �ε��� ���� x)
            answer.push_back(cnt);
            cnt = 0;
            cur = q.front();
        }
        
    }
    return answer;
}
