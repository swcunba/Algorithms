/*������ ������ 1, 2, 3���� 3�����̴�. �־��� n ���� ���� �ʴ� ������ 1~3���� ����� �� �� �ϳ��� ������ ������.
���� dp����ó�� ������ ����� �������� ����� �����غ���. �־��� n�� 1, 2, 3���� �ɰ��ٰ� �����غ���.
�������� ũ�Ⱑ �۾Ƽ� ����Լ��� �̿��غ��� ������ �� ����.
����� ������ n�� 3�� �������� ������ ������ 3�����̹Ƿ� ó���� 3������ ������. 
n�� 
1�� �� 1����.
2�� �� 2����.
3�� �� 4����.������ �⺻ ������ �ؼ� ���ķδ� n�� ����� ���� n-1, n-2, n-3 ����� ���� ���̴�. 
4�� �� 7����.
5�� �� 13����.
...
n = n -1, n - 2, n - 3���� �����ǹǷ� ���Լ��� ����� ����Ǵ� ť�� ���� �����ϸ� �� �� ����. 
*/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

queue <int> q;
int result, n, count, temp = 0;

void spliter(int target){//n�� ��ǥ����. 4 �̻��� ������ ������ �������. ���ÿ� n������ �� �׾��ִٰ� 3�� ������ �� �� ��� ���� ����. 
	int one = 1, two = 2, three = 4;
	q.push(one);
	q.push(two);
	q.push(three);
	temp = one + two + three;
	q.push(temp); 
	//ť�� 1, 2, 3, 4�� ������ ��. ���� 5 = 4+3+2, 6 = 5+4+3...�׾Ƴ����� ��. 
	
	while(n != count){
		if(n == 4){
			break;
		}
		else{
			q.pop(); //���� ���� 1, 2, 3 ������ �����.
			//ť�� �����ִ� 3���� ���ҵ��� ���� �ٽ� ť�� �������ָ� �ȴ�.
			for(int i = 0; i < 3; i++){
				if(i == 0) one = q.front();
				if(i == 1) two = q.front();//�ٽ� ť�� ������ n - 2�� �� ����.
				if(i == 2) three = q.front();//�ٽ� ť�� ������ n - 3�� �� ����.
				q.pop(); 
			}
			temp = one + two + three;
			q.push(one);
			q.push(two);
			q.push(three);
			q.push(temp);
			count++;
		}
	}
	//printf("%d %d %d ", one, two, three);
	for(int i = 0; i < 4; i++){
		q.pop();//ť �ʱ�ȭ. 
	}
	result = temp;  
}

int main(void){
	int t;
	scanf("%d", &t);
	
	while(t--){
		n = 0, count = 4, temp = 0;
		result = 0;
		scanf("%d", &n);
		if(n == 1){
			result = 1;
			printf("%d\n", result);
			continue;
		}
		if(n == 2){
			result = 2;
			printf("%d\n", result);
			continue;
		}
		if(n == 3){
			result = 4;
			printf("%d\n", result);
			continue;
		}
		else spliter(n);
		printf("%d\n", result);
	}
	return 0;
} 
