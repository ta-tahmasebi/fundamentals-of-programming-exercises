#include <stdio.h>

//Amirmahdi Tahmasebi 402106178


int getLen (char *s){
    int i = 0;
    while(*(s+i)){
        i++;
    }
    return i;
}
void print(char* string, int len){
    for(int i = 0; i < len; i++){
        if(string[i] != -1)
            printf("%c", string[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d", &n);
    for(int term = 0; term<n ;term++){
        getchar();
        char string[20000];
        scanf("%[^\n]s", string);
        int len = getLen(string);
        for(int i = 0; i < len; i++){
            if(string[i] == '*'){
                string[i] = -1;
                for(int j = i-1; j>= 0; j --){
                    if(string[j] != -1){
                        string[i] = string[j];
                        break;
                    }
                }
            }
            else if(string[i] == '#'){
                string[i] = -1;
                for(int j = i-1; j>= 0; j --){
                    if(string[j] != -1){
                        string[i] = -1;
                        string[j] = -1;
                        break;
                    }
                }
            }
        }
        print(string, len);
    }
    return 0;
}