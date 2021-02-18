#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//한글자만 다른 단어들끼리 노드 연결.
//target까지 이동횟수 반환.
//트리의 깊이가 곧 답.
bool check[51] = { false, };
int answer = 51;
//디폴트 매개변수: 사용자가 값 안넣으면 해당 값을 기본값으로 메소드 수행.
void dfs(string begin, string target, vector<string> words, int depth = 0){
    for(int i = 0; i < words.size(); i++){
        int cnt = 0;
        for(int j = 0; j < words[i].length(); j++){
            if(!check[i] && begin[j] != words[i][j]) cnt++;//글자 다른 부분 찾기.
        }
        if(cnt == 1){
            //한 곳만 다르다면(변환이 가능하다면)
            if(target == words[i] && answer > depth + 1){
                answer = depth + 1;
                return;
            }
            //방문 표시해준뒤 재귀, 재귀 끝나면(트리 형성이 끝나면) 다시 방문 표시 해제.
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
