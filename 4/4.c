#include <stdio.h>
//Amirmahdi Tahmasebi

void print (int tavan[], double zarib[] , int n){
    char print0 = 1;
    for(int i = 0; i < n; i++){
        if(tavan[i] > 0 && zarib[i] != 0){
            print0 = 0;
            printf("%+.2lf*x^%d", zarib[i], tavan[i]);
        }
        else if(tavan[i] == 0 && zarib[i] != 0){
            print0 = 0;
            printf("%+.2lf", zarib[i]);
        }
    }
    if(print0){
        printf("0.00");
    }
}

double moshtagh(double zarib, int tavan, int martabe){
    if(martabe == 0){
        return zarib;
    }
    return moshtagh(zarib * tavan,tavan - 1, martabe -1);
}
int main() {
    int n,martabe;
    scanf("%d %d", &n, &martabe);
    double zarib[n];
    int tavan[n];
    for(int i = 0; i < n; i++){
        scanf("%lf*x^%d", &zarib[i], &tavan[i]);
    }    
    for(int i = 0; i<n; i++)
        for(int j = 0; j < i; j++){
            if(tavan[i] == tavan[j]){
                zarib[i] += zarib[j];
                zarib[j] = 0;
                tavan[j] = -1;
            }
        }
    for(int i = 0; i<n; i++)
        for(int j = 0; j < i; j++){
            if(tavan[i] > tavan[j]){
                tavan[j] ^= tavan[i];
                tavan[i] ^= tavan[j];
                tavan[j] ^= tavan[i];
                double k = zarib[j];
                zarib[j] = zarib[i];
                zarib [i] = k;
            }
        }
    double final_zarib[n];
    int final_tavan[n];
    for (int i = 0; i< n; i++)
        final_tavan[i] = -1;
    for(int i = 0; i < n; i++){
        final_tavan[i] = tavan[i] - martabe;
        final_zarib[i] = moshtagh(zarib[i], tavan[i], martabe);
    }
    print(final_tavan, final_zarib, n);
    return 0;
}
