#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
//�ּ���, �ִ��� ��� -> �ִ� ���� �ִ������� ����, �ּڰ� ������ �ּ������� ����.
//�ִ񰪰� �ּڰ��� return�ϸ� ��.
priority_queue<int> min_q;
priority_queue<int> max_q;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    int cnt = 0;
    for(string op : operations){
        if(!cnt){
            //cnt = 0 -> ���߿켱���� ť�� ����ٴ� �ǹ�.
            while(!max_q.empty()) max_q.pop();
            while(!min_q.empty()) min_q.pop();
        }
        if(op[0] == 'I'){
            //����.
            int num = stoi(op.substr(2));
            min_q.push(-num);
            max_q.push(num);
            cnt++;
        }
        else if(op[0] == 'D'){
            //����.
            if(!cnt) continue;
            
            if(op[2] == '-') min_q.pop();
            else max_q.pop();
            cnt--;
        }
        if(cnt){
            answer[0] = max_q.top();
            answer[1] = -min_q.top();
        }
    }
    return answer;
}
