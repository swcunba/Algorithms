#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> q;
    
    int idx = 0;
    for(int i = 0; i < k; i++){//i: ���� ����.
        if(i == dates[idx]){//��¥�� ������������ �־���. �������� ��ġ�ϴ� ������ �ִٸ�,
            q.push(supplies[idx]);//�켱���� ť�� �ش� ���� ���޷� ����.
            idx++;
        }
        if(stock == 0){
            stock += q.top();
            q.pop();
            answer++;
        }
        stock--;
    }    
    return answer;
}
