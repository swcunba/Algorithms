#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
//최소힙, 최대힙 사용 -> 최댓값 삭제 최대힙에서 수행, 최솟값 삭제는 최소힙에서 수행.
//최댓값과 최솟값만 return하면 됌.
priority_queue<int> min_q;
priority_queue<int> max_q;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    int cnt = 0;
    for(string op : operations){
        if(!cnt){
            //cnt = 0 -> 이중우선순위 큐가 비었다는 의미.
            while(!max_q.empty()) max_q.pop();
            while(!min_q.empty()) min_q.pop();
        }
        if(op[0] == 'I'){
            //삽입.
            int num = stoi(op.substr(2));
            min_q.push(-num);
            max_q.push(num);
            cnt++;
        }
        else if(op[0] == 'D'){
            //삭제.
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
