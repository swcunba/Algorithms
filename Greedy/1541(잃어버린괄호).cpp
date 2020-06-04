/*5자리보다 큰 수는 없고, +와 -만 있는 길이가 최대 50인 식에서
괄호를 적절히 쳐서 최솟값을 만들어라.
-이후에 괄호를 쳐버리면 되지 않을까?*/
#include <iostream>
#include <string>
using namespace std;
string str;
int minResult(void)
{
	int result = 0;
	string temp = "";
	bool minus = false;//마이너스 플래그 변수 선언
	for (int i = 0; i <= str.size(); i++)
	{
		//연산자일 경우
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (minus)//-가 나오면
				result -= stoi(temp);//문자열 정수로 바꿔서 -연산
			else
				result += stoi(temp);//+연산
			temp = ""; //초기화
			if (str[i] == '-')//-가 나오면
				minus = true;//플래그 값 바꿔주고
			continue;//루프의 끝으로 이동
		}
		//피연산자일 경우
		temp += str[i];//계속 이어붙여줌
	}
	return result;
}
int main(void)
{
	cin >> str;
	cout << minResult() << endl;
	return 0;
}