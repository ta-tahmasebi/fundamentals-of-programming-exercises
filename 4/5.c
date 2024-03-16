#include <stdio.h>
#define ea11(A) ((A >> 48) & (65535))
#define ea12(A) ((A >> 32) & (65535))
#define ea21(A) ((A >>16) & (65535))
#define ea22(A) ((A >> 0) & (65535))

//Amirmahdi Tahmasebi

long long power(long long (mainM), long long (now)){
    long long ans;
    ans = (((((ea11(mainM)% 10000) * (ea11(now)% 10000) + (ea12(mainM)% 10000) * (ea21(now)% 10000) % 10000)) + 10000) % 10000) << 48;
    ans += (((((ea11(mainM)% 10000) * (ea12(now)% 10000) + (ea12(mainM)% 10000) * (ea22(now)% 10000) % 10000)) + 10000) % 10000) << 32;
    ans += (((((ea21(mainM)% 10000) * (ea11(now)% 10000) + (ea22(mainM)% 10000) * (ea21(now)% 10000) % 10000)) + 10000) % 10000) << 16;
    ans += (((((ea21(mainM)% 10000) * (ea12(now)% 10000) + (ea22(mainM)% 10000) * (ea22(now)% 10000) % 10000)) + 10000) % 10000) << 0;
    return ans;
}
long long power2(long long (now), int i){
    for(int j = 0; j < i; j++){
        now = power((now),(now));
    }
    return (now);
}
void print(long long M){
    printf("%lld %lld\n",ea11(M) , ea12(M));
    printf("%lld %lld",ea21(M) , ea22(M));
}
long long get(){
    long long mainM , a,b,c,d;
    scanf("%lld %lld",&a, &b);
    scanf("%lld %lld",&c, &d);
    mainM = ((a % 10000) + 10000) % 10000 << 48;
    mainM += ((b % 10000) + 10000) % 10000 << 32;
    mainM += ((c % 10000) + 10000) % 10000 << 16;
    mainM += ((d % 10000) + 10000) % 10000;
    return (mainM);
}
int main () {
    unsigned long long N;
    scanf("%llu", &N);
    long long i = 0;
    while((1llu << i) <= N)
        i++;
    long long arr[i];
    long long count = i;
    for (int j = 0; j < i; j++)
        arr[j] = -1;
    int j = 0;
    for(; i >= 0; i--){
        if((1llu << i) <= N){
            arr[j] = i;
            N -= (1llu<<i);
            j++;
        }
    }
    long long mainM = get();
    long long ans = 281474976710657;
    for(long long i = 0; i < count; i++){
        if(arr[i] != -1){
            ans = power(ans, power2((mainM),arr[i]));
        }
    }
    print(ans);
    return 0;
}