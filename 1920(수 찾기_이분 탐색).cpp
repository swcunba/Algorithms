/*n개의 정수가 배열 a로 주어짐.
b배열의 원소가 a배열에도 존재하면 1출력, 아닌 경우 0출력.*/

#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int a[MAX];//A배열. 
int b[MAX];//A배열과 비교할 배열. 
 
void search(int start, int end, int target){//탐색 시작 인덱스, 끝 인덱스, 찾고자 하는 값. 
	if(start > end){
	printf("0\n");
	return;
	//시작점이 끝 인덱스보다 크다면 해당 원소 존재하지 않는다는 의미. 
	}
	int mid = (start + end) / 2;//이분 탐색 위해 중간 인덱스 산출. 
	if(a[mid] == target){
		printf("1\n");
		return;
		//찾으려는 값이 중간 원소였다면 바로 반환시키고 종료. 
	}
	else if(a[mid] > target) return search(start, mid - 1, target);//찾으려는 값보다 탐색범위 중간에 위치한 값이 더 크면 탐색 범위를 중간 인덱스 - 1 부분까지로 줄임.
	else return search(mid+1, end, target);//중간보다 찾으려는 값이 멀리 있으면 중간 + 1 범위부터 끝까지만 탐색. 
} 

int main(void){
	int n, m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}//배열의 원소 입력. 
	sort(a, a+n);
	//이분 탐색을 위해 오름차순 정렬.
	for(int i = 0; i < m; i++){
		search(0, n-1, b[i]);
	}
	return 0;
}
