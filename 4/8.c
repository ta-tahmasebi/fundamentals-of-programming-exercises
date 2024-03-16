#include <stdio.h>
#define MAX(A, B) (A >= B)? A : B
//Amirmahdi Tahmasebi

int sarbaz[2000][2000]; 
int doshman[2000][2000];
int rah[2000][2000];
int n;
void f(int i, int j) {
    if(j!=0){
        if(i == 0){
            if(rah[0][j-1] >= doshman[0][j])
                rah[0][j] = rah[0][j-1] + sarbaz[0][j];
        }
        else
            if(rah[i-1][j] >= doshman[i][j] || rah[i][j-1] >= doshman[i][j]){
                rah[i][j] = ((MAX(rah[i-1][j], rah[i][j-1])) + sarbaz[i][j]);
            }
        if(j != n-1)
            f(i,j+1);
        else if(i != n-1)
            f(i+1, 0);
        else    
            return;
    }
    else{
        if(rah[i-1][0] >= doshman[i][0])
            rah[i][0] = rah[i-1][0] + sarbaz[i][0];
        f(i,1);
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d%d" ,&sarbaz[i][j] , &doshman[i][j]);
            rah[i][j] = -1;
        }
    rah[0][0] = sarbaz[0][0];
    f(0,1);
    int answer = rah[n-1][n-1];
    if(answer != -1)
        printf("YES\n%d", answer);
    else
        printf("NO");
    return 0;
}