#include <stdio.h>
int number, data[1000001];
//시간 제한 1초이므로 1억번 연산까지 가능
//N*log N 복잡도 이용해야함. 즉 병합정렬이나 퀵정렬 사용해야함

void quickSort(int* data, int start, int end) {
	if (start <= end) {//원소가 1개라면 그대로 둠
		return;
	}
	int key = start; //키 값(피벗)은 첫번째 원소로 둠
	int i = start + 1, j = end, temp;//i값을 시작값의 한 칸 옆으로 둠
	while (i <= j) {//i값이 j보다 작거나 같을 때까지(엇갈릴 때까지)
		while (data[i] <= data[key]) {//키 값보다 큰 값 만날 때까지
			i++;//시작점에서부터 끝방향으로 원소 탐색
		}
		while (data[j] >= data[key] && j > start) {//키 값보다 작은 값 만날 때까지
			j--;//끝에서부터 처음 방향으로 원소 탐색
		}
		if (i > j) {//엇갈렸다면
			temp = data[j];
			data[j] = data[key];
			data[j] = temp;//키 값을 교체
			data[key] = temp;
		} else {//엇갈리지 않았다면
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;//i와 j 교체
		}
	}
	quickSort(data, start, j - 1);//프로세스 한 사이클 돌고나면 피벗 값 기준으로 왼쪽과 오른쪽 정렬됨
	quickSort(data, j + 1, end);//따라서 왼쪽 오른쪽 각각 한 번 더 정렬시킴
}

int main(void) {
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}
	quickSort(data, 0, number - 1);//배열의 시작과 끝 원소 넣어줌
	for (int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	}
	return 0;
}//테스트 케이스가 추가되서 퀵 정렬로 안풀림. 최악의 경우 O(N^2)가 나옴
//따라서, C++에서 제공하는 알고리즘 STL라이브러리를 사용하여 해결
#include <stdio.h>
#include <algorithm>
int number, data[1000001];
int main(void) {
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}
	std::sort(data, data + number);
	for (int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	}
	return 0;

}