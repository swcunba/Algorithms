//������ ������ ��� ������ ����.

#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

long long arr[MAX];//1,000,000���� ���� �־����Ƿ� ���� �����Ϸ��� long long. 

int main(void){
	int n;
	long long result = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	//������ ���, ���� ���ҿ��� ���� 0�̻��̸� ����. 0�̸��̸� �ش� ���� �����ְ� ��. 
	for(int i = 0; i < n; i++){
		if(arr[i] > 0) break;
		if(i+1 == n){
			result += arr[i];
			break;
		}	
		else if(arr[i] * arr[i+1] >= 0){
			result += arr[i]*arr[i+1];
			i++;
			continue;
		}
		else result += arr[i];
		
	}
	for(int j = n-1; j >= 0; j--){
		if(arr[j] < 0) break;
		else if(arr[j]*arr[j-1] > 0 && arr[j]*arr[j-1] > arr[j]+arr[j-1]){
			result += arr[j]*arr[j-1];
			j--;
			continue;
		}
		else result += arr[j];
	}
	printf("%lld\n", result);
	return 0;
}

 
