//자료형에 따른 연산 연습해보는 문제. 
#include <iostream>

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int students[1001];
		int sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &students[i]);
			sum += students[i];
		}

		double mean = (double)sum / n;
		int over_mean = 0;
		for(int i = 0; i < n; i++){
			if(students[i] > mean){
				over_mean++;
				//printf("%d ", students[i]);
			}
		}
		printf("%.3f%%\n", (double)over_mean / n * 100);//%%는 반올림 연산자. 
	}
	return 0;
}
