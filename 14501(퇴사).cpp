/*
dp�� Ǫ�°� �´°� ����.
��ȭ��: k�ϱ��� ���� ���� + n-k���ڿ� �����ϴ� �۾����� ��� ����.(���� �����ϴ�)
 
*/
#include <iostream>
#include <algorithm>

using namespace std;

int credit[17];//credit[i] = i���ڿ� �޴� ����. 
int time[17];
int price[17];

int main(void){
	int n, t, p, result = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &time[i], &price[i]);
	}
	for(int i=1; i<=n; i++){
        if(i+time[i] <=n+1){//i���� ��� ������ ���(n+1�� ������ �����ٴ� ���� ��). 
            credit[i+time[i]] = max(credit[i+time[i]], credit[i] + price[i]);
            result = max(result, credit[i+time[i]]); 
        }

        credit[i+1] = max(credit[i+1], credit[i]);//i���� ��� ������ ���. 
        result = max(result, credit[i+1]);//i���� ��� ������ ���� ������ ��� �� �ִ� ����. 
    }
    printf("%d\n", result);
	return 0;
} 

