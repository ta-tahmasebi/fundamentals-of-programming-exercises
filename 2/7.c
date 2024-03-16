#include <stdio.h>
//Amirmahdi Tahmasebi 402106178
int main(){
    int wk,bk,bq,br;
    scanf("%d %d", &wk, &bk);
    scanf("%d", &bq);
    scanf("%d", &br);
    if (br % 10 == wk % 10){printf("Rook");}
    else if(br / 10 == wk / 10){printf("Rook");}
    else if (bq % 10 == wk % 10){printf("Queen");}
    else if(bq / 10 == wk / 10){printf("Queen");}
    else if (bq / 10 + bq % 10 == wk / 10 + wk % 10){printf("Queen");}
    else if (bq / 10 - bq % 10 == wk / 10 - wk % 10){printf("Queen");}
    else{printf("No One!");}
    return 0;
}