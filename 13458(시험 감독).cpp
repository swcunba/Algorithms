#include <iostream>
#define MAX 1000001

using namespace std;

int people[MAX];//응시자.
 
int main(void){
	int n, a, b;//a: 총감독관이 관리 가능한 응시생 수, b: 부감독관 관리 가능치.
	long long result = 0; 
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &people[i]);
	}
	scanf("%d %d", &a, &b);
	for(int i = 0; i < n; i++){
		people[i] -= a;
		result++;//총 감독관은 무조건 한 명 들어가니까 +1. 
		if(people[i] > 0){
			if(people[i] % b == 0){
				result += people[i] / b;
			}
			else{
				result += people[i] / b + 1;
			}	
		}
	}
	printf("%lli\n", result);
	return 0;
}//처음에 음수 되는 경우 고려안해서 틀렸음. 
