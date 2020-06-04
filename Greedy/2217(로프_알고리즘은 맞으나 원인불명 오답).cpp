/*로프의 개수를 k, 중량을 w라 할 때, 각 로프에 걸리는 중량은 w/k.
로프마다 버틸 수 있는 중량 한계가 존재.
k개의 로프를 모두 사용하는 경우부터 적은 중량을 들 수 있는 로프부터
소거해나가면서 중량 버틸 수 있는지 확인하는 과정 반복.
오름차순으로 정렬해두면 앞에서부터 약한 로프 소거 가능.*/

#include <stdio.h>
#include <algorithm>
int N;
int ropes[10001];
int main(void) {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d\n", &ropes[i]);
	}
	std::sort(ropes, ropes + N);//약한 로프 순으로 정렬
	int max = 0;//최대 중량은 사용하는 로프 수 * 가장 약한 줄이 들 수 있는 무게
	for(int i = 0; i < N; i++) {
		if(max < ropes[i]*(N-i)) max = ropes[i] * (N - i);
	}
	printf("%d", max);
	return 0;
}