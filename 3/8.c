#include<stdio.h>
// Amirmahdi Tahmasebi 402106178
int main() {
    int n;
    scanf("%d", &n);
    int arr[200];
    int ans[200][200] = {{}};
    for(int i =0 ; i < n; i ++) scanf("%d",&arr[i]);
    for (int i = n; i < 200; i++) arr[i] = -1;
    int max = 0;
    for(int i =0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(i == 0 || i == n-1){
            ans[arr[i]][i] = 2; 
        }
        else{
            if((arr[i] > arr[i-1] && arr[i] > arr[i+1]) || (arr[i] < arr[i-1] && arr[i] < arr[i+1])){
                ans[arr[i]][i] = 2; 
            }
            else{
                ans[arr[i]][i] = 3; 
            }
        }
    }
    for(int i = max; i >= 0; i--){
        printf("%d ", i);
        for(int j = 0; j < n; j ++){
            if(ans[i][j] == 0){
                printf("  ");
            }
            else if(ans[i][j] == 2){
                printf("+ ");
            }
            else{
                printf("* ");
            }
        }
        printf("\n");
    }
    return 0;
}