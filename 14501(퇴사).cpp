/*
dp로 푸는게 맞는거 같다.
점화식: k일까지 얻은 이익 + n-k일자에 시작하는 작업으로 얻는 이익.(조건 충족하는)
 
*/
#include <iostream>
#include <algorithm>

using namespace std;

int credit[17];//credit[i] = i일자에 받는 수익. 
int time[17];
int price[17];

int main(void){
	int n, t, p, result = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &time[i], &price[i]);
	}
	for(int i=1; i<=n; i++){
        if(i+time[i] <=n+1){//i일의 상담 수행한 경우(n+1일 이전에 끝난다는 전제 하). 
            credit[i+time[i]] = max(credit[i+time[i]], credit[i] + price[i]);
            result = max(result, credit[i+time[i]]); 
        }

        credit[i+1] = max(credit[i+1], credit[i]);//i일의 상담 포기한 경우. 
        result = max(result, credit[i+1]);//i일자 상담 수행한 경우와 포기한 경우 중 최댓값 선택. 
    }
    printf("%d\n", result);
	return 0;
} 

