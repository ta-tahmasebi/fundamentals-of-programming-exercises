#include<stdio.h>
// Amirmahdi Tahmasebi 402106178
int main() {
    int n;
    scanf("%d",&n);
    int a[n*n];
    for(int i = -1; i < n; i++){
        char k[4000];
        for(int mn =0; mn < 4000;mn++){
            k[mn]='.';
        }
        for(int mn = 0; mn < 4000; mn++){
            char c;
            scanf("%c", &c);
            if(c != '\n'){
                k[mn] = c;
            }
            else{
                break;
            }
        }
        int ans =0;
        int p =0;
        for(int mn = 0; mn<4000; mn++){
            char u;
            if(k[mn]!=' ' && k[mn] != '.'){
                u = 1;
                int l;
                switch (k[mn])
                {
                case '1': l = 1; break;
                case '2': l = 2; break;
                case '3': l = 3; break;
                case '4': l = 4; break;
                case '5': l = 5; break;
                case '6': l = 6; break;
                case '7': l = 7; break;
                case '8': l = 8; break;
                case '9': l = 9; break;
                case '0': l = 0; break;
                }
                ans = ans * 10 + l;
            } 
            else if (k[mn] == ' ' || u){
                a[n * i + p] = ans;
                ans = 0;
                p++;
                u=0;
            }
            else break;
        }
    }
    int ra[n-1];
    for(int i = 0; i < n-1; i++){
        int r = i;
        int token = 1;
        int ans = 0;
        for(int col = 0; col < n; col++){
            ans += a[col * n + r];
            r += token;
            if(r == n - 1){
                token = -1;
            }
        }
        ra[i] = ans;
    }
    int rl[n-1];
    for(int i = n-1; i > 0; i--){
        int r = i;
        int token = -1;
        int ans = 0;
        for(int col = 0; col < n; col++){
            ans += a[col * n + r];
            r += token;
            if(r == 0){
                token = 1;
            }
        }
        rl[n-i-1] = ans;
    }   
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(ra[i] > ans)
            ans = ra[i];
    }
    for(int i = 0; i < n - 1; i++){
        if(rl[i] > ans)
            ans = rl[i];
    }
    printf("%d",ans);
    return 0;
}