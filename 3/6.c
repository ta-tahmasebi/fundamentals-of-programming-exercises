#include<stdio.h>
// Amirmahdi Tahmasebi 402106178
int main() {
    unsigned long long int n;
    scanf("%llu", &n);
    int m;
    scanf("%d", &m);
    int mm = 0;
    int t;
    scanf("%d", &t);
    unsigned long long int pool = 0;
    for (int i = 0; i < t; i++){
        int a;
        scanf("%d",&a);
        unsigned long long int uu = 1;
        for (int yy = 0; yy < a; yy++){
            uu *= 2;
        }
        if(uu <= n){
            pool += uu;
        }
    }
    char print = 1;
    while(pool % 2 == 0){
        if(n % 2 ==0){
            pool /= 2;
            n /= 2;
        }
        else {
            print = 0;
            break;
        }
    }
    while(pool > 1){
        unsigned long long  int pow = 1;
        int i,p;
        for(i = 0; (pool/pow)%2 != 1;i++)
            pow *= 2;
        unsigned long long int yy=1;
            for (int rr = 0; rr < i+1; rr++)
                yy *= 2;
        unsigned long long int pool2 = pool / yy;
        pow = 1;
        for(p = 0; (pool2/pow)%2 != 1;p++)
            pow *= 2;
        p = i + p + 1;
        unsigned long long int a = 0;
        unsigned long long int b = 0;
        for (int k = i; k < p; k++){
            unsigned long long int yy=1;
            for (int rr = 0; rr < k; rr++)
                yy *= 2;
            a += n&yy;
            b += pool&yy;
        }
        if(i!= 0){
            unsigned long long int yy=1;
            for (int rr = 0; rr < i; rr++)
                yy *= 2;
            a = a / yy;
            b = b / yy;
        }
        char can = 0;
        for (int j = 0; j <= m; j++){
            if(j*b == a){
                mm += j;
                can = 1;
            }
        }
        if(can){
            unsigned long long int yy=1;
            for (int rr = 0; rr < p; rr++)
                yy *= 2;
            n /= yy;
            pool /= (yy);
        }
        else{
            print = 0;
            break;
        }
    }
    char last = 0;
    for(int i = 0; i <= m; i++){
        if(pool * i == n){
            mm += i;
            last = 1;
        }
    }
    if (last == 0){
        print = 0;
    }
    printf("%d",print&&(mm <= m));
    return 0;
}