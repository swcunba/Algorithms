//�ð����� ���� tip: 1�ʿ� 1��� ������ ����
//��������(�������� �����ϴ� ����)
#include <stdio.h>
int array[1001];//1~1000�������� �밳 1 ������. 
int main(void) {
	int number, i, j, min, index, temp;
	scanf("%d", &number);//�Է¹��� ���� ���� �Է�
	for (i = 0; i < number; i++) {//N ������ŭ �Է¹޾� �迭�� ����
		scanf("%d", &array[i]);
	}
	for (i = 0; i < number; i++) {
		min = 1001;//�ּڰ��� �Ϻη� �ּڰ��� �� �� ���� ���� ����
		for (j = i; j < number; j++) {
			if (min > array[j]) {//�׷� �迭�� ù��° ���Ұ� min�� �� ���̰�,
				min = array[j];//�׺��� ���� ���� ���� ������ min ���� ��ü
				index = j;//�ּڰ��� �迭 �ε��� ����
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;//�ӽú��� �̿��� �ּڰ��� array[i]��ġ ����
	}
	for (i = 0; i < number; i++) {
		printf("%d\n", array[i]);
	}
}//ū �ݺ����� i �� 1�� �����ϴϱ� �ڿ������� ���캸�� ���� �ϳ��� �پ��