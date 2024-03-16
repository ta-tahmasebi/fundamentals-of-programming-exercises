#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Amirmahdi Tahmasebi 402106178

char* concat(char *s1, char *s2) {
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
char* rev(char* txt){
    char * text = calloc(strlen(txt) + 1, sizeof(char));
    for(unsigned long long i = 0; i < strlen(txt); i++){
        text[i] = txt[i];
    }
    for(unsigned long long i = 0; i < strlen(text) / 2; i++){
        if(i != strlen(txt) - 1 - i){
            text[i] ^= text[strlen(txt) - 1 - i];
            text[strlen(txt) - 1 - i] ^= text[i];
            text[i] ^= text[strlen(txt) - 1 - i];
        }
    }
    return text;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int count = 0; count < n; count++){
        char name[200];
        scanf("%s", name);
        for(int o = 0; o < strlen(name); o++)
            if(name[o] == '\n' || name[o] == '\r')
                name[o] = 0;
        char* lastName = concat(rev(name), ".txt");
        char* firstName = concat(name, ".txt");
        FILE* firstFile = fopen(firstName, "r");
        FILE* lastFile = fopen(lastName, "w");
        char line[10000];
        char text[100];
        scanf("%s", text);
        while (fgets(line, 10000, firstFile) != NULL){
            for(unsigned long long i = 0; i < strlen(line) - strlen(text) + 1; i++){
                char check = 1;
                for(unsigned long long j = 0; j < strlen(text); j++){
                    if(line[i+j] != text[j]){
                        check = 0;
                        break;
                    }
                }
                if(check){
                    for(unsigned long long j = i; j <= (i+i+strlen(text)-1)/2; j++){
                        if(j != i+strlen(text)-1 - j + i){
                            line[j] ^= line[i+strlen(text)-1 - j + i];
                            line[i+strlen(text)-1 - j + i] ^= line[j];
                            line[j] ^= line[i+strlen(text)-1 - j + i];
                        }
                    }
                    i+=strlen(text);
                    i--;
                }
            }
            fprintf(lastFile, "%s", line);
        }
        fclose(firstFile);
        fclose(lastFile);
    }
    return 0;
}