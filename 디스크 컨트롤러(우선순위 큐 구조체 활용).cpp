#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//������ �����ε�
//�����ε��̶� ���� ���� ó���ϴ� �Լ�, ������ ���� �Ű������� ������ ���ݾ� �޸��Ͽ�, 
//�ϳ��� �̸����� �ۼ��� �� �ְ� ���ִ� ��
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
        //at()�� �迭 ���� ����� ���� ������. �ּ��� ����� ���� ������ Ŭ����.
    }
};
int solution(vector<vector<int>> jobs) {
    int answer = 0, idx = 0, t = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //cmp�� ���� �ι�° ���� �������� �ּ��� ����.
    sort(jobs.begin(), jobs.end());//��û���� ���� �������� ����.
    while(idx < jobs.size() || !pq.empty()){
         if (jobs.size() > idx && t >= jobs[idx][0]) {
             //�۾� �����ְ� ��û������ �����ִٸ� �ּ����� �۾� �߰�.
            pq.push(jobs[idx++]);
            continue;
        }
        
        if (!pq.empty()) {
            //��� ���� �۾��� �ִ� ���.
            t += pq.top()[1];//���� �۾� �Ϸ�������� �̵�(�۾��ð���ŭ �߰�).
            answer += t - pq.top()[0];//�Ϸ���� - ��û���� ���ؼ� ���ð� �ݿ�.
            pq.pop();//�۾� �Ϸ�.
        }
        else //ť�� ����ִٸ� �����۾� �ð����� �ѱ�
            t = jobs[idx][0];
    }
    answer /= jobs.size();
    return answer;
}
