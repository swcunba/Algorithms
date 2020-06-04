//시간제한 관련 tip: 1초에 1억번 정도의 연산
//선택정렬(오름차순 정렬하는 문제)
#include <stdio.h>
int array[1001];//1~1000까지지만 대개 1 여유둠. 
int main(void) {
	int number, i, j, min, index, temp;
	scanf("%d", &number);//입력받을 수의 개수 입력
	for (i = 0; i < number; i++) {//N 개수만큼 입력받아 배열에 저장
		scanf("%d", &array[i]);
	}
	for (i = 0; i < number; i++) {
		min = 1001;//최솟값을 일부러 최솟값이 될 수 없는 수로 잡음
		for (j = i; j < number; j++) {
			if (min > array[j]) {//그럼 배열의 첫번째 원소가 min이 될 것이고,
				min = array[j];//그보다 작은 값이 나올 때마다 min 값을 교체
				index = j;//최솟값의 배열 인덱스 저장
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;//임시변수 이용해 최솟값과 array[i]위치 변경
	}
	for (i = 0; i < number; i++) {
		printf("%d\n", array[i]);
	}
}//큰 반복문의 i 값 1씩 증가하니까 자연스럽게 살펴보는 원소 하나씩 줄어듦