#include <stdio.h>
#include <stdlib.h>

//Amirmahdi Tahmasebi 402106178


char* sort(char* str, int len){
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(*(str + i) < *(str + j)){
                char temp = *(str + i);
                *(str + i) = *(str + j);
                *(str + j) = temp;
            }
        }
    }
    return str;
}

int findLen (char* str){
    int i = 0;
    while(*(str + i) != ' ' && *(str + i) != '\t' && *(str + i) != '\0')
        i++;
    return i;
}

char* find (char* str, int* p){
    if(*(str + *p) == '\0')
        return NULL;
    while(*(str + *p) == ' ' || *(str + *p) == '\t')
        (*p) ++;
    return (str + *p);
}

void print(char* str, int len, char** final){
    if (!len) return;
    int index = 0;
    while(*(final + index))
        index++;
    char* a = (char*)calloc(300, sizeof(char));
    for(int i = 0; i < len; i++)
        a[i] = *(str + i);
    a[len] = '\0';
    *(final + index) = a;
}

void print2(char** str){
    int i = 0;
    while(*(str + i)){
        printf("%s ", *(str+i));
        i++;
    }
}

int getLen(char* a){
    int i = 0;
    while(*(a+i))
        i++;
    return i;
}

int compare(char* a, char* b){
    int lena = getLen(a);
    int lenb = getLen(b);
    int min = (lena < lenb)? lena : lenb;
    for(int i = 0; i < min; i++){
        if(*(a+i) > *(b+i))
            return 1;
        else if(*(a+i) < *(b+i))
            return 0;
    }
    if(lena > lenb)
        return 1;
    return 0;
}

char** sort2D(char** str){
    int len = 0;
    while(*(str + len)){
        len++;
    } 
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(compare(*(str + i), *(str + j))){
                char * temp = *(str + i);
                *(str + i) = *(str + j);
                *(str + j) = temp;
            }
        }
    }
    return str;
}

int main(){
    char ** finaladdress = (char**)calloc(300,sizeof(char*));
    char string[300];
    scanf("%[^\n]s", string);
    int p = 0;
    while(1){
        char* address = find(string, &p);
        if(!address) break;
        int len = findLen(address);
        p+= len;
        print(address, len, finaladdress);
    }
    sort2D(finaladdress);
    int index = 0;
    while(*(finaladdress + index)){
        *(finaladdress+index) = sort(*(finaladdress + index), getLen(*(finaladdress + index)));
        printf("%s ", *(finaladdress + index));
        index++;
    }
    return 0;
}