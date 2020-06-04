#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

stack <int> s;

int main(void){
	int k, result = 0;
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		int x;
		scanf("%d", &x);
		if(x == 0) s.pop();
		else s.push(x);
	}
	while(!s.empty()){
		result += s.top();
		s.pop();
	}
	printf("%d\n", result);
	return 0;
}
