#include <stdio.h>
//Amirmahdi Tahmasebi 402106178
int main(){
    int d,m,wd,D,M;
    scanf("%d %d  -> %d", &d, &m, &wd);
    scanf("%d %d", &D , &M);
    if(d>30 || d < 1 || D > 30 || D < 1 || m > 12 || m < 1 || M > 12 || M < 1|| wd > 6 || wd < 0){
        printf("Invalid Date!");
    }
    else{    
        int dis = M * 30 + D - m * 30 - d;
        int day = dis + wd;
        if(day % 7 == 0){printf("Saturday");}
        else if(day % 7 == 1 || day % 7 == -6){printf("Sunday");}
        else if(day % 7 == 2 || day % 7 == -5){printf("Monday");}
        else if(day % 7 == 3 || day % 7 == -4){printf("Tuesday");}
        else if(day % 7 == 4 || day % 7 == -3){printf("Wednesday");}
        else if(day % 7 == 5 || day % 7 == -2){printf("Thursday");}
        else if(day % 7 == 6 || day % 7 == -1){printf("Friday");}
    }
    return 0;
}