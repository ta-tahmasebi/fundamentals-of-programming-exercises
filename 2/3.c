#include <stdio.h>
//Amirmahdi Tahmasebi 402106178
int main(){
    int masoud, saeed;
    scanf("%d %d",&masoud, &saeed);
    if(saeed > 31 || saeed < 1 || masoud > 31 || masoud < 1) {
        printf("invalid date");
    }
    else{
        saeed = saeed ^ masoud;
        masoud = saeed ^ masoud;
        saeed = saeed ^ masoud;
        printf("%d\n", masoud);
        printf("%d",saeed);
    }
    return 0;
}