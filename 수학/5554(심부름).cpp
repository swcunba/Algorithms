#include <iostream>

int main(void){
	int sec[4];
	int sec_sum = 0;
	for(int i = 0; i < 4; i++){
		scanf("%d", &sec[i]);
		sec_sum += sec[i];
	}
	int minute = sec_sum / 60;
	int second = sec_sum % 60;
	printf("%d\n%d\n", minute, second);
	return 0;
}
