/*
m���� ĭ�� ���� ���.
�� ĭ�� �ִ� �� ������ �Ҹ� �� �� ����.
n������  �Ұ� �ְ�, �� �Ҵ� ����ϴ� 0~m���� ĭ�� �ִ�. 
*/
#include <stdio.h>
#include <vector>
#define MAX 201
using namespace std;

int n, m, s;
vector <int> cows[MAX];//�Ұ� ����ϴ� ��� ĭ ����.
int select[MAX];//~ĭ�� �� �Ұ� �� �� ������. 
bool check[MAX];//Ȯ�� ����.
 
bool dfs(int x){//1�� �Һ��� n�� �� Ȥ�� ĭ�� ��ȣ�� �μ�. �� �� ������ true, �ƴϸ� false. 
	//����� ��� ��忡 ���ؼ� �� �� �ִ� �õ�.
	for(int i = 0; i < cows[x].size(); i++){//�ҵ��� ����(���� ����Ʈ) ��� ���Ǳ�. 
		int t = cows[x][i];//���캸�� �ִ� �Ұ� �� �� �ִ�  ��� ĭ �� �ϳ�(���). 
		if(check[t]) continue;//�̹� ó���� ĭ�� �� �̻� �� �ʿ䰡 ����.
		check[t] = true;//���캻 �Ҵ� true.
		//���õ��� ���� ĭ�̰ų�(==0), ���� ��忡 �� �� ������ �ִ� ���(�� �ٸ� ���� ������ �� ������ true�� ��ȯ�ϹǷ�).
		if(select[t] == 0 || dfs(select[t])){//������ ���޾� 0�̰ų� �ش� �Ұ�  �ٸ� ���� ��Ī �������� Ȯ��. //dfs(select(t))�����ν� �ٸ� ĭ �� �� �ִ��� Ȯ��. 
			select[t] = x;//�Ҹ� ��� ĭ�� ������. 
			return true; //�Ұ� ĭ�� �����Ǹ� true�� ��ȯ. 
		} 
	} 
	return false;
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &s);
		for(int j = 1; j <= s; j++){
			int k;
			scanf("%d", &k);
			cows[i].push_back(k);
		}
	} 
	int count = 0;
	for(int i = 1; i <= n; i++){
		fill(check, check + MAX, false);//check �迭�� false�� �� ä���ְ�. 
		if(dfs(i)) count++;//dfs �Լ��� true�� ��ȯ�Ѵٸ�(�Ұ� �� �� �ִٸ�), ī��Ʈ++. 
	}
	printf("%d\n", count);//������ �� �ִ� �Ұ� �� �������� ��µȴ�. 
	return 0;
}
