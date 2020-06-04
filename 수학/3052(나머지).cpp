#include <iostream>

int main(void){
	int num[10];
	for(int i = 0; i < 10; i ++){
		scanf("%d", &num[i]);
		num[i] %= 42;
	}
	int result = 10;
	for(int i = 0; i < 10; i++){
		for(int j = i+1; j < 10; j++){
			if(num[i] == num[j]){
				result--;
				break; 
			}
		}
	}
	printf("%d\n", result);
	return 0;
}
