//문자는 작은 따옴표로 지정해야 에러 발생 안함. 문자열은 큰 따옴표. 
//조건 묶어놨더니 이상한 값 출력된다. 
//입력받을 때 %c앞에 스페이스를 넣었더니 해결되었다. 이유는 모르겠다. 
//scanf안에 공백을 넣으면 개행문자를 무시하게 된다. 
//따라서 입력에 공백이나 엔터가 들어간 경우엔 공백을 넣어 의도한 인덱스에 값이 들어가도록 해야한다. 
#include <iostream>

char board[8][8];
int result = 0;

int main(void){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			scanf(" %c", &board[i][j]);
		}
		"\n";
	}
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if((i+j)%2==0 && board[i][j] == 'F'){
				//printf("%d %d\n", i, j); 
				result++; 
			}
		}
	}
	printf("%d\n", result);
	return 0;
}
