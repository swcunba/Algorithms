#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);//cin 입력 속도 개선, 단 stdio.h에서 제공하는 함수 사용 불가
	int N;
	cin >> N; // 몇번째 번호 출력하게 할건지 입력
	int num = 666; //첫 번째 종말의 숫자
	int turn = 1; //출력할 번호
	while (1)//완전 탐색
	{
		if (turn == N)//해당 숫자를 찾았다면
			break;
		num++; //666에서 시작해 1씩 증가시킴
		int copyNum = num;//해당 숫자를 저장하고
		string s; //문자열 변수 s 선언
		while (copyNum)
		{
			s += (copyNum % 10 + '0');//666에서부터 1씩 증가 되는 수의 1의 자리수에 0을 합침
			copyNum /= 10;
		}
		copyNum = stoi(s); //문자열을 다시 정수 형태로 변환(string to int)
		int six = 0;
		while (copyNum)//6이 연속으로 세개 있는지 확인
		{
			int temp = copyNum % 10;//1의 자리수부터 한 자리수씩 까면서 확인
			if (temp == 6)
				six++;// 6의 개수 세기
			else if (six < 3) //6의 개수가 3개보다 적으면
				six = 0; // 6개수 초기화
			copyNum /= 10; //
		}
		if (six >= 3)//조건을 만족한다면
			turn++; //출력할 번호 1증가
	}
	cout << num << "\n";
	return 0;
}