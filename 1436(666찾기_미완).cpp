#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);//cin �Է� �ӵ� ����, �� stdio.h���� �����ϴ� �Լ� ��� �Ұ�
	int N;
	cin >> N; // ���° ��ȣ ����ϰ� �Ұ��� �Է�
	int num = 666; //ù ��° ������ ����
	int turn = 1; //����� ��ȣ
	while (1)//���� Ž��
	{
		if (turn == N)//�ش� ���ڸ� ã�Ҵٸ�
			break;
		num++; //666���� ������ 1�� ������Ŵ
		int copyNum = num;//�ش� ���ڸ� �����ϰ�
		string s; //���ڿ� ���� s ����
		while (copyNum)
		{
			s += (copyNum % 10 + '0');//666�������� 1�� ���� �Ǵ� ���� 1�� �ڸ����� 0�� ��ħ
			copyNum /= 10;
		}
		copyNum = stoi(s); //���ڿ��� �ٽ� ���� ���·� ��ȯ(string to int)
		int six = 0;
		while (copyNum)//6�� �������� ���� �ִ��� Ȯ��
		{
			int temp = copyNum % 10;//1�� �ڸ������� �� �ڸ����� ��鼭 Ȯ��
			if (temp == 6)
				six++;// 6�� ���� ����
			else if (six < 3) //6�� ������ 3������ ������
				six = 0; // 6���� �ʱ�ȭ
			copyNum /= 10; //
		}
		if (six >= 3)//������ �����Ѵٸ�
			turn++; //����� ��ȣ 1����
	}
	cout << num << "\n";
	return 0;
}