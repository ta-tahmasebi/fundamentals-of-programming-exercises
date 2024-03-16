#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

//Amirmahdi Tahmasebi 402106178

int* aggregator(int* a, int* b)  {
    long long sum = 0;  
    int sizeOfA = 0;
    int sizeOfB = 0;
    if(*a == 0)
        sizeOfA = 0;
    else{
        do{
            sum += *(a+sizeOfA);
            sizeOfA++;
        } while(sum != *(a+sizeOfA));
    }
    sum = 0;
    if(*b == 0)
        sizeOfB = 0;  
    else{
        do{
            sum += *(b+sizeOfB);
            sizeOfB++;
        } while(sum != *(b+sizeOfB));
    }
    sizeOfA++;
    sizeOfB++;
    int na = sizeOfA;
    int nb = sizeOfB;
    int *c = (int *)malloc((sizeOfA + sizeOfB) * sizeof(int));
    
        int k = (na > nb)? nb : na;
    for(int i = 0; i < 2*k; i++){
        if(!(i % 2))
            *(c + i) = *(a + i/2);
        else
            *(c+i) = *(b + i/2);
    }
    if(na > nb){
        k = na - nb;
        for(int j = 0; j < k; j++)
            *(c + 2*nb + j) = *(a + nb + j);
    }
    else{
        k = nb - na;
        for(int j = 0; j < k; j++)
            *(c + 2*na + j) = *(b + na + j);
    }

    return c;
}