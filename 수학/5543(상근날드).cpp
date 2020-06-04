#include <iostream>
#include <algorithm>
using namespace std;

int burgers[3];
int beverage[2];
int main(void){
	for(int i = 0; i < 3; i++){
		scanf("%d", &burgers[i]);
	}
	for(int i = 0; i <2; i++){
		scanf("%d", &beverage[i]);
	}
	sort(burgers, burgers+3);
	sort(beverage, beverage+2);
	printf("%d\n", burgers[0] + beverage[0] - 50);
}
