#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Amirmahdi Tahmasebi 402106178

int ___findLen (char* str){ //only for deleting spaces
    int i = 0;
    while(*(str + i) != ' ' && *(str + i) != '\t' && *(str + i) != '\0')
        i++;
    return i;
}
char* ___find (char* str, int* p){ //only for deleting spaces
    if(*(str + *p) == '\0')
        return NULL;
    while(*(str + *p) == ' ' || *(str + *p) == '\t')
        (*p) ++;
    return (str + *p);
}
void ___print(char* str, int len, char** final){ //only for deleting spaces
    if (!len) return;
    int index = 0;
    while(*(final + index))
        index++;
    char* a = (char*)calloc(1000, sizeof(char));
    for(int i = 0; i < len; i++)
        a[i] = *(str + i);
    a[len] = '\0';
    *(final + index) = a;
}
char** delete_spaces (char* string){
    char ** finaladdress = (char**)calloc(1000,sizeof(char*));
    int p = 0;
    while(1){
        char* address = ___find(string, &p);
        if(!address) break;
        int len = ___findLen(address);
        p+= len;
        ___print(address, len, finaladdress);
    }
    return finaladdress;
}
char compare(char* a, char* b){
    if(strcmp(a, b)) return 0;
    return 1;
}

char check(char** dic, char* text){
    int i = 0;
    while(dic[i] != NULL){
        if(compare(dic[i], text)) return 1; 
        i++;
    }
    return 0;
}

int main() {
    FILE* dictionary = fopen("dic.txt", "r");
    char ** dic = (char **)calloc(90001, sizeof(char*));
    unsigned long long i = 0;
    char line[200];
    while(fgets(line, 199, dictionary)){
        dic[i] = (char *)calloc(strlen(line) + 1, sizeof(char));
        for(unsigned long long j = 0; j < strlen(line) - 1; j++)
            dic[i][j] = line[j];
        i++;
    }
    char * text = (char* )calloc(1000, sizeof(char));
    fgets(text, 999, stdin);
    for(int o = 0; o < strlen(text); o++) if(text[o] == '\n' || text[o] == '\r') text[o] = 0;
    char** Token = delete_spaces(text);
    int index = 0;
    int flag = 0;
    while(*(Token + index)){
        if(!check(dic, *(Token + index))){
            if(flag == 0){
                printf("misspelled word(s):\n");
                flag = 1;
            }
            printf("%s\n", *(Token + index));
        }
        index++;
    }
    if(flag == 0){
        printf("there is no misspelled word!");
    }
    return 0;
}
