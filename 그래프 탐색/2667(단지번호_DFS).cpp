/*
BFS�� DFS ��� ��� ������ �����̴�.
DFS�� ���� ���� ���غ����� DFS�� �غ���. 
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool map[25][25] = { false, };//Ž�� ���� Ȯ��(�̷�). 
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
string arr[25];//���ڿ� �迭�� ������ �� �ڸ��� �ε����� ���� ����. ��������� 2���� �迭�� ��������. 
vector <int> ans;
int n, cnt;

void dfs(int i, int j){//�湮�� �� �μ��� ����. 
	map[i][j] =true;//�湮 ó��.
	cnt++;
	int k;
	for(k = 0; k < 4; k++){
		int next_y = i + dy[k];
		int next_x = j + dx[k];
	
		if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n)
			if(arr[next_y][next_x] == '1' && !map[next_y][next_x]) dfs(next_y, next_x);
	}
}

int main(void){
	int i, j;
	//scanf("%d", &n);
	cin >> n;//cin���� �Է��ϸ� ���� ���� �Էµ� ������ '�ϳ���' ���� �ν���. scanf�� ����ϸ鼭 �ϳ��� ���� �ν��ϰ� �Ϸ��� "%1d"�� �־��ָ� �ȴ�.  
	for(i = 0; i < n; i++) cin >> arr[i];
	//scanf("%d", &arr[i]);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(arr[i][j] == '1' && !map[i][j]){//���� �湮���� ���� 1�̶��, 
				cnt = 0;//cnt 0���� �ʱ�ȭ�ϰ�, 
				dfs(i, j);//dfs������ ��, 
				ans.push_back(cnt);//cnt�� ���� �����ϴ� �迭�� ����. 
			}
		}
	}
	sort(ans.begin(), ans.end());//�������� ����. 
	//printf("%d\n", ans.size()); //���� ���� ���. 
	cout << ans.size() << '\n';
 	for(i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
	 //printf("%d\n", ans[i]);
	return 0;
}
