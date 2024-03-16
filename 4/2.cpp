#include "grader.h"
#include <stdio.h>
#include <stdarg.h>
//Amirmahdi Tahmasebi

long long MOD (int n, ...) {
    long long ans = 0;
    va_list list;
    int i = 0;
    va_start(list, n);
    for(i = 1; i <= n; i++){
        int a = va_arg(list,int);
        if(!(a % i))
            ans += 1;
        if(i != n)
            ans *= 2;
    }
    va_end(list);
    return ans;
}