#include <iostream>

int main(void){
    int num[9];
    for(int i = 0; i < 9; i++){
        scanf("%d", &num[i]);
    }
    int maximum = num[0];
    int idx = 1;
    for(int i = 0; i < 9; i++){
        if(maximum < num[i]){
            maximum = num[i];
            idx = i+1;
        }
    }
    printf("%d\n%d\n", maximum, idx);
    return 0;
}
