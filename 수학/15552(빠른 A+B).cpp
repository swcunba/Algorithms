#include <iostream>

int main(void){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", x+y);
	}
	return 0;
}
