#include <iostream>

int arr[300][300];
int n, m, k;
int r, c, x, y;
int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d ", &arr[i][j]);
		}
		"\n";
	}
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d %d %d %d", &r, &c, &x, &y);
		int result = 0;
		for(int j = r-1; j < x; j++){
			for(int l = c-1; l < y; l++){
				result += arr[j][l];
			}
		}
		printf("%d\n", result);
	}
	return 0;
}
