#include<stdio.h>
// Amirmahdi Tahmasebi 402106178
int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    int list[n][n];
    for(int i =0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &list[i][j]);
        }
    }
    for(int QQQ=0; QQQ<m; QQQ++){
        char function=10;
        do{
            scanf("%c",&function);
        }while(function == 10 || function == 32);
        if (function == 77){
            for(int i = 0; i< n; i++){
                for (int j =0; j< i; j++){
                    list [i][j] = list[i][j] ^ list[j][i];
                    list [j][i] = list[i][j] ^ list[j][i];
                    list [i][j] = list[i][j] ^ list[j][i];
                }
            }
        }
        if(function == 83){
            for(int i = 0; i<n;i++){
                for(int j =0; i + j < n-1;j++){
                    list[j][i] = list[(n-i-1)][(n-j-1)] ^ list[j][i];
                    list[n - i - 1][n - j - 1] = list[(n-i-1)][(n-j-1)] ^ list[j][i];
                    list[j][i] = list[(n-i-1)][(n-j-1)] ^ list[j][i];
                }
            }
        }
        if(function == 72){
            for(int i =0; i < n/2; i++){
                for(int j=0; j < n;j++){
                    list[(n-i-1)][j] = list[(n-i-1)][j] ^ list[i][j];
                    list[i][j] = list[(n-i-1)][j] ^ list[i][j];
                    list[(n-i-1)][j] = list[(n-i-1)][j] ^ list[i][j];
                }
            }
        }
        if(function == 86){
            for(int i =0; i < n; i++){
                for(int j=0; j < n/2;j++){
                    list[i][j] = list[i][(n - j - 1)] ^ list[i][j];
                    list[i][(n - j - 1)] = list[i][(n - j - 1)] ^ list[i][j];
                    list[i][j] = list[i][(n - j - 1)] ^ list[i][j];
                }
            }
        }
        if(function == 65){
            int help[n][n];
            for(int i =0; i < n; i++){
                for(int j=0; j < n;j++){
                    if(i != 0 && i != n - 1 && j != 0 && j != n -1) help[i][j] = (list[i][j+1] + list[i][j-1] + list[i+1][j] + list[i-1][j])/4;
                    else if(i == 0 && j != 0 && j != n -1)  help[0][j] = (list[0][j-1]+list[0][j+1]+list[1][j])/3;
                    else if(i == n-1 && j != 0 && j != n -1)    help[i][j] = (list[i][j+1]+list[i][j-1]+list[i-1][j])/3;
                    else if(i != 0 && i != n - 1 && j == 0) help[i][j] = (list[i][j+1] + list[i-1][j] + list[i+1][j])/3;
                    else if(i != 0 && i != n - 1 && j == n-1) help[i][j] = (list[i][j-1] + list[i-1][j] + list[i+1][j])/3;
                    else if(i == 0 && j ==0) help[0][0] = (list[0][1] + list[1][0])/2;
                    else if(i == n-1 && j ==0) help[i][j] = (list[i][j + 1] + list[i-1][j])/2; 
                    else if(i == 0 && j == n-1) help[0][j] = (list[i][j-1] + list[i+1][j])/2; 
                    else help[i][j] = (list[i][j-1] + list[i-1][j])/2; 
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j< n; j++)
                    list[i][j]= help[i][j];
            }
        }
        if(function == 85){
            int max = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(list[i][j] > max) max = list[i][j];
                }
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    list[i][j] = max - list[i][j];
                }
            }
        }
        if(function == 82){
            int i;
            scanf("%d" , &i);
            for(int o = 0; o<n; o++){
                for(int u = o + 1; u < n;u++){
                    if(list[i-1][u] < list[i-1][o]){
                        list[i-1][u] = list[i-1][u] ^ list[i-1][o];
                        list[i-1][o] = list[i-1][u] ^ list[i-1][o];
                        list[i-1][u] = list[i-1][u] ^ list[i-1][o];
                    }
                }
            }
        }
        if(function == 67){
            int j;
            scanf("%d" , &j);
            for(int o = 0; o<n; o++){
                for(int u = o + 1; u < n;u++){
                    if(list[u][j-1] < list[o][j-1]){
                        list[u][j-1] = list[u][j-1] ^ list[o][j-1];
                        list[o][j-1] = list[u][j-1] ^ list[o][j-1];
                        list[u][j-1] = list[u][j-1] ^ list[o][j-1];
                    }
                }
            }
        }
    }
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            printf("%d ", list[i][j]);
        }
        printf("\n");
    }
    return 0;
}