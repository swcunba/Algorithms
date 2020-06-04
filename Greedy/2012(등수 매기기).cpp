#include <iostream>
#include <algorithm>
#define MAX 500001

using namespace std;
 
int pre[MAX];
int real[MAX];

int main(void){
	int n;
	long long result = 0;//데이터 크기. 
	scanf("%d", &n);
	for(int i =0; i < n; i++){
		scanf("%d", &pre[i]);
		real[i] = i+1;
	}
	sort(pre, pre + n);
	//예상 등수 겹치면 실제 등수에 공백 생김.
	//공백 생긴 실제 등수 - 예상 등수의 합이 답. 
	for(int i = 0; i < n; i++){
		if(real[i] - pre[i] > 0) result += real[i] - pre[i];
		else result += -(real[i] - pre[i]);
	}
	printf("%ld\n", result);
	return 0;
}
