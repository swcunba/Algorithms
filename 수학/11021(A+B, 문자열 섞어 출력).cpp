#include <iostream>

int main(void){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("Case #%d: %d + %d = %d\n", i, x, y, x+y);
	}
	return 0;
} 
