#include <stdio.h>
//Amirmahdi Tahmasebi
unsigned long long fib[90];
unsigned long long sum (unsigned long long n,unsigned long long m){
    return n+m;
}
void calculat(){
    fib[0] = fib[1] = 1;
    for(int i = 2; i < 90; i++){
        fib[i] = sum(fib[i-1], fib[i-2]);
    }
}
int main () {
    calculat();
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i =0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i =0; i < n; i++)
        printf("%llu\n", fib[arr[i]]);
    return 0;
}