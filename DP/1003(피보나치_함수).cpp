//0과 1이 나오는 횟수 카운트하면 된다.
//하향식? 
#include <iostream>
int result_0[41];
int result_1[41];

int n;

void dp(int k){
	if(k > n) return;
	result_0[k] = result_0[k-1] + result_0[k-2];
	result_1[k] = result_1[k-1] + result_1[k-2];
	dp(k+1);
}

int main(void){
	int t;
	result_0[0] = 1;
	result_0[1] = 0;
	result_0[2] = 1;
	
	result_1[0] = 0;
	result_1[1] = 1;
	result_1[2] = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n > 2){
			dp(2);
		}
		printf("%d %d\n", result_0[n], result_1[n]);
	}
	return 0;
}
