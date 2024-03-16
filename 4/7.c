#include <stdio.h>
//Amirmahdi Tahmasebi
int a[100];
void print(int i, int n) {
    if(n == -1){
        printf("\n");
        return;
    }
    if((i>>n) & 1)
        printf("+");
    else
        printf("-");
    print(i,n-1);
}
int check(int a[], int i, int n){
    if(n == -1)
        return 0;
    if(i%2)
        return a[n] + check(a,i/2,n-1);
    return -a[n] + check(a,i/2,n-1);
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int r;
    scanf("%d", &r);
    for(int i = (1<<n) - 1; i >= 0; i--){
        if(check(a,i,n-1) == r)
            print(i,n-1);
    }
}
