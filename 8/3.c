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


int main() {
    int i, j;
    scanf("%d%d", &i, &j);
    FILE* first = fopen("input1.txt", "r");
    FILE* second = fopen("input2.txt", "r");
    char line1 [1000];
    char line2 [1000];
    for(int k = 0; k < i; k++)
        fgets(line1, 999, first);
    if(line1[strlen(line1) - 1] == '\n') line1[strlen(line1) - 1] = 0;
    for(int k = 0; k < j; k++)
        fgets(line2, 999, second);
    for(int o = 0; o < strlen(line1); o++){
      if(line1[o] == '\n' || line1[o] == '\r') line1[o] = 0;
    }
    for(int o = 0; o < strlen(line2); o++){
      if(line2[o] == '\n' || line2[o] == '\r') line2[o] = 0;
    }
    char ** token1 = delete_spaces(line1);
    char ** token2 = delete_spaces(line2);
    i = 0;
    char flag = 1;
    while(token1[i] != NULL){
        int j = 0;
        while (token2[j] != NULL){
            if(!strcmp(token1[i], token2[j])){
                flag = 0;
                printf("%s ", token1[i]);
            }
            j++;
        }       
        i++;
    }
    if(flag){
        printf("No matching words found!");
    }
    return 0;
}
