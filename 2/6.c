#include <stdio.h>
//Amirmahdi Tahmasebi 402106178
int main(){
    /*In this program I will check that z index of "a cross b" isn't diffrent from next cross. this means that quadrilateral is convex*/
    /*After that, I check all the orders of points. Becuse points are not given in order*/
    int x1,x2,x3,x4,y1,y2,y3,y4;
    scanf("%d %d", &x1 , &y1);
    scanf("%d %d", &x2 , &y2);
    scanf("%d %d", &x3 , &y3);
    scanf("%d %d", &x4 , &y4);
    int possible = 0;
    if(((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) * ((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) <= 0) {}
    else if(((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) * ((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) <= 0) {}
    else if(((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) * ((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) <= 0) {}
    else if(((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) * ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) <= 0) {}
    else{possible = 1;}
    x3 ^= x4; y3 ^= y4;
    x4 ^= x3; y4 ^= y3;
    x3 ^= x4; y3 ^= y4;
    if(((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) * ((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) <= 0) {}
    else if(((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) * ((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) <= 0) {}
    else if(((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) * ((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) <= 0) {}
    else if(((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) * ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) <= 0) {}
    else{possible = 1;}
    x2 ^= x4; y2^= y4;
    x4 ^= x2; y4 ^= y2;
    x2 ^= x4; y2 ^= y4;
    if(((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) * ((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) <= 0) {}
    else if(((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) * ((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) <= 0) {}
    else if(((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) * ((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) <= 0) {}
    else if(((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) * ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) <= 0) {}
    else{possible = 1;}
    x3 ^= x4; y3 ^= y4;
    x4 ^= x3; y4 ^= y3;
    x3 ^= x4; y3 ^= y4;
    if(((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) * ((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) <= 0) {}
    else if(((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) * ((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) <= 0) {}
    else if(((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) * ((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) <= 0) {}
    else if(((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) * ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) <= 0) {}
    else{possible = 1;}
    x2 ^= x4; y2^= y4;
    x4 ^= x2; y4 ^= y2;
    x2 ^= x4; y2 ^= y4;
    if(((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) * ((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) <= 0) {}
    else if(((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) * ((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) <= 0) {}
    else if(((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) * ((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) <= 0) {}
    else if(((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) * ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) <= 0) {}
    else{possible = 1;}
    x3 ^= x4; y3 ^= y4;
    x4 ^= x3; y4 ^= y3;
    x3 ^= x4; y3 ^= y4;
    if(((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) * ((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) <= 0) {}
    else if(((x3 - x2)*(y4 - y2) - (x4 - x2)*(y3 - y2)) * ((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) <= 0) {}
    else if(((x4 - x3)*(y1 - y3) - (x1 - x3)*(y4 - y3)) * ((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) <= 0) {}
    else if(((x1 - x4)*(y2 - y4) - (x2 - x4)*(y1 - y4)) * ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) <= 0) {}
    else{possible = 1;}
    if(possible){printf("1");}
    else{printf("0");}
    return 0;
}