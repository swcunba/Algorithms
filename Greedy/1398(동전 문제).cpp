#include <iostream>

long coins[23];

int main(void){
	int t;
	coins[0] = 1;
	coins[1] = 10;
	coins[2] = 25;
	for(int i = 3; i < 23; i++){
		if(i%3 == 2 && i <= 20){
			coins[i] = coins[i-2]*25;
		}
		else if(i%3 == 0){
			coins[i] = coins[i-2]*10; 
		}
		else{
			coins[i] = coins[i-1]*10;
		}
	}
	scanf("%d", &t); 
	//1 25 100 1000 2500 10000 100000 250000... �ε��� 3������ 100�� ������. 100���� ū ���� �־����� 100������ ���� �� ������ 100���� �������..
	//ex) 3072 -> ������θ� 2500, 100*5, 72 => 72�� �ּڰ����ٰ�  3000�� �׳� ū ������ �ɰ������� �ȴ�. 100���� �������� �� �������� ��������. 
	while(t--){
		long p;
		int result = 0;
		scanf("%ld", &p);
		for(int i = 22; i >= 0; i--){
			if(p >= coins[i]){
				if(p <= 100){
					if(coins[i] == 25 && p % 10 < 5){
					result += p / coins[i-1];
					p -= coins[i-1]*(p / coins[i-1]);
					} 
					else{
						result += p / coins[i];
						p -= coins[i]*(p/coins[i]);
					}
				}
				else{
					result += p/coins[i];
					p -= coins[i]*(p/coins[i]);
				}
				
			}
		}
		printf("%d\n", result);
	}
	return 0;
} 
