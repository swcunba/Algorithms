/*5�ڸ����� ū ���� ����, +�� -�� �ִ� ���̰� �ִ� 50�� �Ŀ���
��ȣ�� ������ �ļ� �ּڰ��� ������.
-���Ŀ� ��ȣ�� �Ĺ����� ���� ������?*/
#include <iostream>
#include <string>
using namespace std;
string str;
int minResult(void)
{
	int result = 0;
	string temp = "";
	bool minus = false;//���̳ʽ� �÷��� ���� ����
	for (int i = 0; i <= str.size(); i++)
	{
		//�������� ���
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (minus)//-�� ������
				result -= stoi(temp);//���ڿ� ������ �ٲ㼭 -����
			else
				result += stoi(temp);//+����
			temp = ""; //�ʱ�ȭ
			if (str[i] == '-')//-�� ������
				minus = true;//�÷��� �� �ٲ��ְ�
			continue;//������ ������ �̵�
		}
		//�ǿ������� ���
		temp += str[i];//��� �̾�ٿ���
	}
	return result;
}
int main(void)
{
	cin >> str;
	cout << minResult() << endl;
	return 0;
}