#include <stdio.h>
#include <stdlib.h>

//Amirmahdi Tahmasebi 402106178

void swap(double *row1, double *row2, int n){
    for(int k = 0; k < n; k++){
        double temp = *(row1 + k);
        *(row1 + k) = *(row2 + k);
        *(row2 + k) = temp;
    }
}
void action(double ** array, int i, int j , int n){
    double c = *(*(array + j) + i) / *(*(array + i) + i);
    for(int k = i; k < n; k++)
        *(*(array + j) + k) -= (c) * *(*(array + i) + k);
}
int main(){
    int n;
    scanf("%d", &n);
    double ** array = (double **)(malloc(sizeof(double *) * n));
    for(int i = 0; i < n; i++)
        *(array + i) = (double *)(malloc(sizeof(double) * n));
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", *(array + i) + j);
    for(int i = 0; i < n-1; i++){
        if(*(*(array + i) + i) > 0.000005 || *(*(array + i) + i) < -0.000005)
            for(int j = i+1; j < n; j++)
                action(array, i, j, n);
        else
            for(int j = i+1; j < n; j++)
                if(*(*(array + j) + i) > 0.000005 || *(*(array + j) + i) < -0.000005){
                    swap(*(array+i), *(array+j), n);
                    for(int k = i+1; k < n; k++)
                        action(array, i, k, n);
                    break;
                }
    }
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(*(*(array + i) + j) > 0.0005 || *(*(array + i) + j) < -0.0005)
                printf("%.2lf ", *(*(array + i) + j));
            else
                printf("0.00 ");
        }
        printf("\n");
    }
    return 0;
}