#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> q;
    
    int idx = 0;
    for(int i = 0; i < k; i++){//i: 현재 시점.
        if(i == dates[idx]){//날짜는 오름차순으로 주어짐. 현시점과 일치하는 공급일 있다면,
            q.push(supplies[idx]);//우선순위 큐에 해당 일자 공급량 삽입.
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
