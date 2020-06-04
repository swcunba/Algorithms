#include <stdio.h>
int number, data[1000001];
//�ð� ���� 1���̹Ƿ� 1��� ������� ����
//N*log N ���⵵ �̿��ؾ���. �� ���������̳� ������ ����ؾ���

void quickSort(int* data, int start, int end) {
	if (start <= end) {//���Ұ� 1����� �״�� ��
		return;
	}
	int key = start; //Ű ��(�ǹ�)�� ù��° ���ҷ� ��
	int i = start + 1, j = end, temp;//i���� ���۰��� �� ĭ ������ ��
	while (i <= j) {//i���� j���� �۰ų� ���� ������(������ ������)
		while (data[i] <= data[key]) {//Ű ������ ū �� ���� ������
			i++;//�������������� ���������� ���� Ž��
		}
		while (data[j] >= data[key] && j > start) {//Ű ������ ���� �� ���� ������
			j--;//���������� ó�� �������� ���� Ž��
		}
		if (i > j) {//�����ȴٸ�
			temp = data[j];
			data[j] = data[key];
			data[j] = temp;//Ű ���� ��ü
			data[key] = temp;
		} else {//�������� �ʾҴٸ�
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;//i�� j ��ü
		}
	}
	quickSort(data, start, j - 1);//���μ��� �� ����Ŭ ������ �ǹ� �� �������� ���ʰ� ������ ���ĵ�
	quickSort(data, j + 1, end);//���� ���� ������ ���� �� �� �� ���Ľ�Ŵ
}

int main(void) {
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &data[i]);
	}
	quickSort(data, 0, number - 1);//�迭�� ���۰� �� ���� �־���
	for (int i = 0; i < number; i++) {
		printf("%d\n", data[i]);
	}
	return 0;
}//�׽�Ʈ ���̽��� �߰��Ǽ� �� ���ķ� ��Ǯ��. �־��� ��� O(N^2)�� ����
//����, C++���� �����ϴ� �˰��� STL���̺귯���� ����Ͽ� �ذ�
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