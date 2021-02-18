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
            //앞 작업 완성시기가 뒷 작업보다 빠른 경우 다른 날 배포.
            //(answer 배열에 값을 넣어주고 기준이 되는 완성시간 교체)
            //(answer[100]과 같이 메모리 직접 할당한 배열 아니라 인덱스 접근 x)
            answer.push_back(cnt);
            cnt = 0;
            cur = q.front();
        }
        
    }
    return answer;
}
