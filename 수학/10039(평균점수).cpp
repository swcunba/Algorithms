#include <stdio.h>

int scores[5];//학생들 점수.

int main(void){
	int average = 0;
	for(int i = 0; i < 5; i++){
		scanf("%d", &scores[i]);
		if(scores[i] < 40) scores[i] = 40;
		average += scores[i];
	}
	average /= 5;
	printf("%d\n", average);
	return 0;
} 
