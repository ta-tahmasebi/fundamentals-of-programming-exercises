#include<stdio.h>
// Amirmahdi Tahmasebi 402106178
int main() {
    int n;
    scanf("%d", &n);
    int a[1001] = {1,2};
    for(int j = 2; j < n; j++){
        int ans = 0;
        for(int i = (j+1) / 2; i <= j; i++){
            ans += (a[i-1])%10000;
        }
        a[j] = ans%10000;
    }
    for(int i = 0; i <n; i++);
    printf("%d",a[n-1]%10000);
    return 0;
}