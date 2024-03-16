#include<stdio.h>
// Amirmahdi Tahmasebi 402106178
int main() {
    int n;
    scanf("%d", &n);
    for (int i = n; i >= 1; i--){
        for(int j = 0; j < i; j++){
            printf("1");
        }
        printf("0");
    }
    return 0;
}