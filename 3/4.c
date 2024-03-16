#include<stdio.h>
// Amirmahdi Tahmasebi 402106178
int main() {
    int base, m;
    unsigned long long int nb;
    scanf("%d %llu %d", &base, &nb, &m);
    int list[m];  
    for(int i=0; i<m; i++) {
        int k;
        scanf("%d",&k);
        list[i] = k;
    }
    int n=0;
    int pow = 1;
    while(nb > 0){
        n += (nb% 10) * pow;
        nb /= 10;
        pow *= base;
    }
    unsigned long long int ans[n];
    int index = 0;
    for(int i = 1; i <= n; i++){
        if (n% i == 0){
            int show = 1;
            unsigned long long int ib=0;
            unsigned long long int pow = 1;
            int j = i;
            while(j > 0){
                ib += (j % base) * pow;
                int is = 0;
                for(int o=0; o<m; o++){if (j % base == list[o]) is = 1;}
                if(is == 0) show = 0;
                pow *= 10;
                j /= base;
            }
            if(show) {
                ans[index] = ib;
                index++;
            }
        }
    }
    for(int i = 0; i< index; i++){
        printf("%llu\n",ans[i]);
    }
    return 0;
}