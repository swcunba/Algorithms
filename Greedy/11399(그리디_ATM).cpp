/*인출하는데 시간이 적게 걸리는 사람을 앞으로 보내면 최솟값이 나옴
따라서, 소요시간을 오름차순으로 정렬시키고 합을 구하게 하면 되겠다.*/
#include <stdio.h>
#include <algorithm>
int N, time[1001];
int main(void) {
	scanf("%d", &N);//사람 수 입력
	for (int i = 0; i < N; i++) {
		scanf("%d", &time[i]);//사람 수만큼 각 소요시간 입력
	}
	std::sort(time, time + N);//소요시간 오름차순 정렬
	int result = 0;
	for (int i = 1; i < N; i++) {
		time[i] += time[i-1];//소요시간 앞사람 거랑 합침
	}
	for (int i = 0; i < N; i++) {
		result += time[i];
	}
	printf("%d", result);
	return 0;
}
