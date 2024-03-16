#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Amirmahdi Tahmasebi 402106178


char char_swap(unsigned char a, char k){
    a += k;
    if(a > 122)
        a -= 26;
    return a;
}
char* str_swap (char* str, char k){
    char* s = (char*)(calloc(500, sizeof(char)));
    int index = 0;
    while(str[index] != '\0'){
        s[index] = char_swap(str[index], k);
        index ++;
    }
    return s;
}
int check(char* str, char* s){
    int n = 0;
    int u = 0;
    while(1){
        char a[500];
        a[0] = '\0';
        sscanf(str + u, "%s", a);
        if(!strcmp(a, s)) n++;
        if(a[0] == '\0') break;
        u += strlen(a) + 1;
    }
    if(n) return 1;
    return 0;
}
int main(){
    char tempString[500];
    scanf("%[^\n]s", tempString);
    getchar();
    char* ramz = (char*)(calloc(500, sizeof(char)));
    scanf("%[^\n]s", ramz);
    int result = 0;
    for(int i = 0; i < 26; i++)
        result += check(tempString, str_swap(ramz, i));
    printf("%d", result);
    return 0;
}