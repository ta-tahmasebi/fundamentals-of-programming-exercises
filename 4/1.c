#include <stdio.h>
//Amirmahdi Tahmasebi

int isOdd(unsigned long long n) {
    int count = 0;
    while(n > 0){
        if (n % 2 == 1)
            count++;
        n /= 2;
    }
    return (count % 2);
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        unsigned long long a;
        scanf("%llu", &a);
        isOdd(a)? printf("odd\n") : printf("even\n");
    }
    return 0;
}
