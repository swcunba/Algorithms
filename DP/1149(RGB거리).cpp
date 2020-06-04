#include <iostream>
#include <algorithm>

using namespace std;

int numbers[1001][3];
int ans[1001][3];

int main(void){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++) scanf("%d", &numbers[i][j]);
	}
	ans[0][0] = numbers[0][0];
	ans[0][1] = numbers[0][1];
	ans[0][2] = numbers[0][2];
	
	for(int i = 1; i < n; i++){
		ans[i][0] = min(ans[i-1][1], ans[i-1][2]) + numbers[i][0];
		ans[i][1] = min(ans[i-1][0], ans[i-1][2]) + numbers[i][1];
		ans[i][2] = min(ans[i-1][0], ans[i-1][1]) + numbers[i][2];
	}
	
	int result = 987654321;//엄청 큰 값으로 상정해두어야 정답 처리된다. 이유는 모르겠음. 
	for(int i = 0; i < 3; i++){
		if(result > ans[n-1][i]) result = ans[n-1][i];
	}
	printf("%d\n", result);
	return 0;
} 

