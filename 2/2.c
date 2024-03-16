#include <stdio.h>
//Amirmahdi Tahmasebi 402106178
int main(){
    int input;
    scanf("%d", &input);
    int a33 = input % 10; input /= 10;
    int a32 = input % 10; input /= 10;
    int a31 = input % 10; input /= 10;
    int a23 = input % 10; input /= 10;
    int a22 = input % 10; input /= 10;
    int a21 = input % 10; input /= 10;
    int a13 = input % 10; input /= 10;
    int a12 = input % 10; input /= 10;
    int a11 = input % 10; input /= 10;
    if (a11 == a21 && a21 == a31 && a11 != 0){
        if(a11 == 2){printf("2");}
        else{printf("1");}
    }
    else if(a12 == a22 && a22 == a32 && a12 != 0){
        if(a12 == 2){printf("2");}
        else{printf("1");}
    }
    else if(a13 == a23 && a23 == a33 && a13 != 0){
        if(a13 == 2){printf("2");}
        else{printf("1");}
    }
    else if (a11 == a12 && a12 == a13 && a11 != 0){
        if(a11 == 2){printf("2");}
        else{printf("1");}
    }
    else if(a21 == a22 && a22 == a23 && a21 != 0){
        if(a21 == 2){printf("2");}
        else{printf("1");}
    }
    else if(a31 == a32 && a32 == a33 && a31 != 0){
        if(a31 == 2){printf("2");}
        else{printf("1");}
    }
    else if(a11 == a22 && a22 == a33 && a11 != 0) {
        if(a11 == 2){printf("2");}
        else{printf("1");}
    }
    else if(a13 == a22 && a22 == a31 && a31 != 0) {
        if(a13 == 2){printf("2");}
        else{printf("1");}
    }
    else{
        printf("0");
    }
    return 0;
}