#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//연산자 오버로딩
//오버로딩이란 같은 일을 처리하는 함수, 연산자 등의 매개변수의 형식을 조금씩 달리하여, 
//하나의 이름으로 작성할 수 있게 해주는 것
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
        //at()은 배열 범위 벗어나면 예외 던져줌. 최소힙 만들기 위한 연산자 클래스.
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0, idx = 0, t = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //cmp를 통해 두번째 원소 기준으로 최소힙 형성.
    sort(jobs.begin(), jobs.end());//요청시점 기준 오름차순 정렬.
    while(idx < jobs.size() || !pq.empty()){
         if (jobs.size() > idx && t >= jobs[idx][0]) {
             //작업 남아있고 요청시점이 지나있다면 최소힙에 작업 추가.
            pq.push(jobs[idx++]);
            continue;
        }
        
        if (!pq.empty()) {
            //대기 중인 작업이 있는 경우.
            t += pq.top()[1];//현재 작업 완료시점으로 이동(작업시간만큼 추가).
            answer += t - pq.top()[0];//완료시점 - 요청시점 더해서 대기시간 반영.
            pq.pop();//작업 완료.
        }
        else //큐가 비어있다면 다음작업 시간으로 넘김
            t = jobs[idx][0];
    }
    answer /= jobs.size();
    return answer;
}
