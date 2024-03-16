#include <stdio.h>
#define forLoop(X) for(int i = 0; i < (X); i++)
#define solve(A,Number1,Number2,Number3,Number4) Number1 A Number2 A Number3 A Number4
//Amirmahdi Tahmaseni

int main() {
    int n;
    scanf("%d", &n);
    int max_score = -1e9;
    forLoop(n) {
        char x;
        int x1, x2, x3, x4;
        scanf(" %c%d%d%d%d", &x, &x1, &x2, &x3, &x4);
        int a, b, c, d;

        a = (x1 + x2 + x3 + x4) / 4;
        b = (x1 - x2 + x3 - x4) / 4;
        c = (x1 + x2 - x3 - x4) / 4;
        d = (x1 - x2 - x3 + x4) / 4;
        int s;
        if(x=='+')
            s = solve(+, a+b+c+d, a-b+c-d, a+b-c-d, a-b-c+d);
        else if(x=='-')
            s = solve(-, a+b+c+d, a-b+c-d, a+b-c-d, a-b-c+d);
        else if(x=='*')
            s = solve(*, a+b+c+d, a-b+c-d, a+b-c-d, a-b-c+d);
        else
            s = solve(%, a+b+c+d, a-b+c-d, a+b-c-d, a-b-c+d);

        if (s > max_score)
            max_score = s;
        }
    printf("%d\n", max_score);
    return 0;
}
