#include <stdio.h>
//Amirmahdi Tahmasebi 402106178
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int k = a ^ b;
    int ans = 0;
    if(k >= 128){
        k -= 128;
        ans++;
    }
    if(k >= 64){
        k -= 64;
        ans++;
    }
    if(k >= 32){
        k -= 32;
        ans++;
    }
    if(k >= 16){
        k -= 16;
        ans++;
    }
    if(k >= 8){
        k -= 8;
        ans++;
    }
    if(k >= 4){
        k -= 4;
        ans++;
    }
    if(k >= 2){
        k -= 2;
        ans++;
    }
    if(k >= 1){
        k -= 1;
        ans++;
    }
    printf("%d", ans);
    return 0;
}