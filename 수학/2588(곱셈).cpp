#include <iostream>

int main(void){
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	int b_arr[4];
	b_arr[0] = b % 10;
	b_arr[1] = (b % 100) / 10 ;
	b_arr[2] = b / 100;
	b_arr[3] = b;
	for(int i = 0; i < 4; i++){
		printf("%d\n", a*b_arr[i]);
	}
	return 0;
}
