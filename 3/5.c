#include<stdio.h>
// Amirmahdi Tahmasebi 402106178
int main() {
    int n;
    scanf("%d",&n);
    char ans[50];
    for(int i=0; i< 50; i++){
        ans[i] = '.';
    }
    int round=0;
    int m = n;
    for (int i = 2; i <= m; i++){
        if (n % i == 0){
            char k = 0;
            while(n%i==0){
                n/=i;
                k++;
            }
            ans[round]=k;
            round++;
        }
    }
    char yes = 1;
    for(int i=0; i< round; i++){
        if(ans[i] != ans[round -i - 1]){
            yes = 0;
        }
    }
    printf("%d\n",round);
    if(yes){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}