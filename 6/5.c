#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Amirmahdi Tahmasebi 402106178

char* cap(char* str){
    for(int index = 0; str[index]!= '\0'; index++)
        if(str[index] <= 'Z' && str[index] >= 'A')
            str[index] = str[index] - 'A' + 'a';
    return str;
}

char* correct_url(char* url){
    int k;
    char* string = (char*)malloc(2000);
    int index = 0;
    for(k = 0; url[k] != '\0'; k++){
        if(k == 0 && url[k] == 'h' && url[k+1] == 't' && url[k+2] == 't' && url[k+3] == 'p' && url[k+4] == ':' && url[k+5] == '/' && url[k+6] == '/')
            k+= 6;
        else if(k == 0 && url[k] == 'h' && url[k+1] == 't' && url[k+2] == 't' && url[k+3] == 'p' && url[k+4] == 's' && url[k+5] == ':' && url[k+6] == '/' && url[k+7] == '/')
            k += 7;
        else if((k == 0 || k == 7 || k == 8) && url[k] == 'w' && url[k+1] == 'w' && url[k+2] == 'w' && url[k+3] == '.')
            k += 3;
        else if(url[k] == '/')
            break;
        else{
            string[index++] = url[k];
        }
    }
    string[index] = '\0';
    return string;
}

void add(char* url, char*  ip, char** urls, char** ips){
    for(int i = 0; i < 2000; i++){
        if(*(urls[i]) == 0 || !strcmp(urls[i], url)){
            strcpy(urls[i], url);
            strcpy(ips[i], ip);
            break;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char** urls = (char**)calloc(2000, sizeof(char*));
    for(int i = 0; i < n; i++)
        urls[i] = (char*)calloc(2000, sizeof(char));
    char** ips = (char**)calloc(2000, sizeof(char*));
    for(int i = 0; i < n; i++)
        ips[i] = (char*)calloc(2000, sizeof(char));
    for(int count = 0; count < n; count++){
        getchar();
        char string[20000];
        scanf("%[^\n]s", string);
        if(!strcmp(strtok(string, " "), "add")){
            char * URL = strtok(NULL, " ");
            char * IP = strtok(NULL, " ");
            add(correct_url(cap(URL)), IP, urls, ips);
        }
        else if(!strcmp(strtok(string, " "), "lookup")){
            char * a = string + 7;
            char * URL = correct_url(cap(a));
            char flag = 1;
            for(int i = 0; *(urls[i]) != 0; i++){
                if(!strcmp(URL, urls[i])){
                    printf("%s\n", ips[i]);
                    flag = 0;
                    break;
                }
            }
            if(flag){
                printf("URL not found\n");
            }
        }
    }
    return 0;
}