/*
n개의 크레인, 작업 단위 시간 1.
각 크레인에는 무게 제한 존재. 박스는 한 번에 하나씩만 이동가능.
모든 크레인은 동시에 움직임. 즉, 1 단위 시간에 최대 n개의 박스 옮길 수 있음.
가능하다면 모든 크레인을 이용할 수 있도록 하면 답이다. 
박스의 개수 m.
박스 옮기는데 걸리는 시간의 최솟값. 
옮길 수 없으면 -1 출력.

그냥 떠오르는 생각으로는 크레인의 무게 제한과 박스 무게의 차를 최소화하여
옮기면 되지 않을까 싶다. 
우선순위 큐 사용시 중복된 원소 사용하면 무한루프 발생하는 문제 깨달음. 
*/
#include <iostream>
#include <algorithm>

using namespace std;
 
int box[10001];
int crane[51];
int check[10001];
int n, m;

int desc(int x, int y){
	return (x > y);
}

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &crane[i]);
	scanf("%d", &m);
	for(int i = 0;  i < m; i++) scanf("%d", &box[i]);
	sort(crane, crane + n, desc);
	sort(box, box + m);
	int result = 0;
	if(crane[0] < box[m-1]){
		printf("-1");
		return 0;	
	}
	while(m){
		int idx = 0;
		for(int j = m-1; j >= 0; j--){
			if(box[j] <= crane[idx]){
				idx++; 
				m--;
				break;
			}
			if(idx == n) break; 	
		}
		result++;
	}
	printf("%d\n", result);
	return 0;
}
