#include <iostream>
#define MAX 1000001

using namespace std;

int people[MAX];//������.
 
int main(void){
	int n, a, b;//a: �Ѱ������� ���� ������ ���û� ��, b: �ΰ����� ���� ����ġ.
	long long result = 0; 
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &people[i]);
	}
	scanf("%d %d", &a, &b);
	for(int i = 0; i < n; i++){
		people[i] -= a;
		result++;//�� �������� ������ �� �� ���ϱ� +1. 
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
}//ó���� ���� �Ǵ� ��� ������ؼ� Ʋ����. 
