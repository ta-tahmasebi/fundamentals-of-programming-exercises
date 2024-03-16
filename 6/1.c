#include <stdio.h>

//Amirmahdi Tahmasebi 402106178

char check(char c){
    if(c >= '0'  && c <= '9')
        return 1;
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int term = 0; term<=n ;term++){
        char string[2000000];
        fgets(string, 2000000, stdin);
        int i = 0;
        while(string[i] != '\0'){
            if(string[i] == '+' || string[i] == '-'){
                char flag = 1;
                while(check(string[i+1])){
                    if(flag){
                        printf("%c", string[i]);
                        flag = 0;
                    }
                    printf("%c", string[i+1]);
                    i++;
                }
                printf("\n");
            }
            else if(check(string[i])){
                printf("%c", string[i]);
                while(check(string[i+1])){
                    printf("%c", string[i+1]);
                    i++;
                }
                printf("\n");
            }
            i++;
        }
    }
    return 0;
}