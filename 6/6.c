#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Amirmahdi Tahmasebi 402106178


void GETcommands1(char* string);
void GETcommands2(char* string);
int GETcountOfPossibleCHAR(char* string, int neshangar){
    int count = 0;
    while(string[neshangar] != '\0'){
        if(string[neshangar] != -1)
            count++;
        neshangar++;
    }
    return count;
}
int GETcountOfPossibleSENT(char* string, int neshangar){
    int count = 0;
    while(string[neshangar] != '\0'){
        if(string[neshangar] == '.' || string[neshangar] == '!' || string[neshangar] == '?')
            count++;
        neshangar++;
    }
    return count;
}
int GETcountOfPossibleWORD(char* string, int neshangar){
    int count = 0;
    while(1){
        while(string[neshangar] == ' ' || string[neshangar] == -1)
            neshangar++;
        if(string[neshangar] != ' '  && string[neshangar] != '\0' && string[neshangar] != -1){
            count++; 
            while(string[neshangar] != ' '  && string[neshangar] != '\0')
                neshangar++;
        }
        if(string[neshangar] == '\0')
            break; 
    }
    return count;
}
char* getText(char* string){
    char* temp = (char*)(calloc(3000, sizeof(char)));
    int len = 0;
    while(1){
        scanf("%[^\n]s", temp);
        getchar();
        strcpy(string+len, temp);
        len += strlen(temp);
        if(string[len-1] == '#'){
            string[len-1] = '\0';
            break;
        }
        else{
            string[len] = '\n';
            len++;
        }
    }
    return string;
}
void changeMode(char request, char* mode){
    if(*mode == 1 ){
        if(request == 1)
            printf("invalid command\n");
        else
            *mode = 0;
    }
    else{
        if(request == 1)
            *mode = 1;
        else
            printf("invalid command\n");
    }
}
char* DELETE (char* string, int neshangar, int number, char scw){
    if(scw == 'c'){
        int countOfPossibles = GETcountOfPossibleCHAR(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return string;
        }
        while(number > 0){
            if(string[neshangar] != -1 && string[neshangar] != '\0'){
                string[neshangar] = -1;
                number--;
            }
            neshangar++;
        }
    }
    else if(scw == 's'){
        int countOfPossibles = GETcountOfPossibleSENT(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return string;
        }
        while(number > 0){
            if(string[neshangar] != -1 && string[neshangar] != '\0'){
                if(string[neshangar] == '.' || string[neshangar] == '!' || string[neshangar] == '?')
                    number--;
                string[neshangar] = -1;
            }
            neshangar++;
        }
    }
    else if(scw == 'w'){
        int countOfPossibles = GETcountOfPossibleWORD(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return string;
        }
        while(number > 0){
            while(string[neshangar] == ' ' || string[neshangar] == -1){
                string[neshangar] = -1;
                neshangar++;
            }
            if(string[neshangar] != ' '  && string[neshangar] != '\0' && string[neshangar] != -1){
                number--; 
                while(string[neshangar] != ' ' && string[neshangar] != '\0'){
                    string[neshangar] = -1;
                    neshangar++;
                }
            }
            if(string[neshangar] == '\0')
                break; 
        }
    }
    return string;
}
char* INSERT(char* string, int neshangar, char* text){
    int lenString = strlen(string);
    int lenText = strlen(text);
    for(int i = lenString; i >= neshangar; i--)
        string[i + lenText] = string[i];
    for(int i = neshangar; i < neshangar+lenText; i++)
        string[i] = text[i - neshangar];
    return string;
}
char* SHOW(char* string, int neshangar, int number, char scw){
    if(scw == 'c'){
        int countOfPossibles = GETcountOfPossibleCHAR(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return string;
        }
        while(number > 0){
            if(string[neshangar] != -1 && string[neshangar] != '\0'){
                printf("%c", string[neshangar]);
                number--;
            }
            neshangar++;
        }
    }
    else if(scw == 's'){
        int countOfPossibles = GETcountOfPossibleSENT(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return string;
        }
        while(number > 0){
            if(string[neshangar] != -1 && string[neshangar] != '\0'){
                if(string[neshangar] == '.' || string[neshangar] == '!' || string[neshangar] == '?')
                    number--;
                printf("%c", string[neshangar]);
            }
            neshangar++;
        }
    }
    else if(scw == 'w'){
        int countOfPossibles = GETcountOfPossibleWORD(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return string;
        }
        while(number > 0){
            while(string[neshangar] == ' '|| string[neshangar] == -1){
                printf("%c", string[neshangar]);
                neshangar++;
            }
            if(string[neshangar] != ' ' && string[neshangar] != '\0' && string[neshangar] != -1){
                number--; 
                while(string[neshangar] != ' ' && string[neshangar] != '\0'){
                    printf("%c", string[neshangar]);
                    neshangar++;
                }
            }
            if(string[neshangar] == '\0')
                break; 
        }
    }
    printf("\n");
    return string;
}
char* COPY(char* string, int neshangar, int number, char scw){
    char* temp = (char*)(calloc(3000, sizeof(char)));
    int index = 0;
    if(scw == 'c'){
        int countOfPossibles = GETcountOfPossibleCHAR(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return temp;
        }
        while(number > 0){
            if(string[neshangar] != -1 && string[neshangar] != '\0'){
                temp[index] = string[neshangar];
                index++;
                number--;
            }
            neshangar++;
        }
    }
    else if(scw == 's'){
        int countOfPossibles = GETcountOfPossibleSENT(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return temp;
        }
        while(number > 0){
            if(string[neshangar] != -1 && string[neshangar] != '\0'){
                if(string[neshangar] == '.' || string[neshangar] == '!' || string[neshangar] == '?')
                    number--;
                temp[index] = string[neshangar];
                index++;
            }
            neshangar++;
        }
    }
    else if(scw == 'w'){
        int countOfPossibles = GETcountOfPossibleWORD(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return temp;
        }
        while(number > 0){
            while(string[neshangar] == ' '  || string[neshangar] == -1){
                temp[index] = string[neshangar];
                index++;
                neshangar++;
            }
            if(string[neshangar] != ' '  && string[neshangar] != '\0' && string[neshangar] != -1){
                number--; 
                while(string[neshangar] != ' ' && string[neshangar] != '\0'){
                    temp[index] = string[neshangar];
                    index++;
                    neshangar++;
                }
            }
            if(string[neshangar] == '\0')
                break; 
        }
    }
    return temp;
}
int JUMP(char* string, int neshangar, int number, char scw){
    if(scw == 'c'){
        int countOfPossibles = GETcountOfPossibleCHAR(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return neshangar;
        }
        while(number > 0){
            if(string[neshangar] != -1 && string[neshangar] != '\0')
                number--;
            neshangar++;
        }
    }
    else if(scw == 's'){
        int countOfPossibles = GETcountOfPossibleSENT(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return neshangar;
        }
        while(number > 0){
            if(string[neshangar] != -1 && string[neshangar] != '\0'){
                if(string[neshangar] == '.' || string[neshangar] == '!' || string[neshangar] == '?')
                    number--;
            }
            neshangar++;
        }
    }
    else if(scw == 'w'){
        int countOfPossibles = GETcountOfPossibleWORD(string, neshangar);
        if(countOfPossibles < number){
            printf("out of bounds\n");
            return neshangar;
        }
        while(number > 0){
            while(string[neshangar] == ' ' || string[neshangar] == -1)
                neshangar++;
            if(string[neshangar] != ' '  && string[neshangar] != '\0' && string[neshangar] != -1){
                number--; 
                while(string[neshangar] != ' '  && string[neshangar] != '\0')
                    neshangar++;
            }
            if(string[neshangar] == '\0')
                break; 
        }
    }
    return neshangar;
}
char FindCheck(char* a, char* text){
    char flag = 1;
    for(int i = 0; i < (int)strlen(text); i++){
        if(a[i] != text[i])
            flag = 0;
    }
    return flag;
}
void FIND(char* string, char* text, char scw){
    int lenText = strlen(text);
    int lenString = strlen(string);
    int countS = 0;
    int countW = 0;
    for(int index = 0; index <= lenString - lenText; index++){
        //how s or w is now?
        if(FindCheck(string + index, text)){
            if(scw == 'w'){
                countW = GETcountOfPossibleWORD(string, 0) - GETcountOfPossibleWORD(string, index) + 1;
                printf("%d\n", countW);
                return;
            }
            else{
                countS = GETcountOfPossibleSENT(string, 0) - GETcountOfPossibleSENT(string, index) + 1;
                printf("%d\n", countS);
                return;
            }
        }
    }
    printf("not found\n");
}
void function(char* string){
    int len = strlen(string);
    if(len>((1<<5)+(4<<1))&&len<((3<<4)+(4>>1)))
        GETcommands1(string);
    else
        GETcommands2(string);
}
void GETcommands2(char* string){
    char* command = (char*)(calloc(3000, sizeof(char)));
    char* clipboard = (char*)(calloc(3000, sizeof(char)));
    char mode = 1;
    int neshangar = 0; 
    while(1){
        command[0] = 0;
        scanf("%[^\n]s", command);
        if(command[0] == '#'){
            if(command[1] == 0)
                return;
            else
                printf("invalid command\n");
        }
        getchar();
        if(command[0] == 'R' && (command[1] == '\0'))
            changeMode(0, &mode);
        else if(command[0] == 'E' && (command[1] == '\0')) 
            changeMode(1, &mode); 
        else if(command[0] == 'd'){
            if(mode == 0)
                printf("invalid command\n");
            else{
                int number = 0;
                char scw = 0;
                sscanf(command + 1, "%d%c", &number, &scw);
                char temp[1000];
                sprintf(temp,"d%d%c", number, scw);
                if(scw != 's' && scw != 'c' && scw != 'w')
                    printf("invalid command\n");
                else if(!strcmp(temp, command))
                    string = DELETE(string, neshangar, number, scw);
                else 
                    printf("invalid command\n");
            }
        }   
        else if(command[0] == 'i') {
            char* text = (char*)(calloc(3000, sizeof(char)));
            if(mode == 0)
                printf("invalid command\n");
            else{
                if(command[1] == ' ' && command[2] == '"'){
                    int j;
                    for(j = 3; command[j] != '"'; j++){
                        text[j-3] = command[j];
                        if(j > 1000){
                            j = 3; 
                            break;
                        }
                    }
                    if(j == 3)
                        printf("invalid command\n");
                    else if(!strstr(text, " "))
                        printf("invalid command\n");
                    else if(command[j+1] != '\0')
                        printf("invalid command\n");
                    else
                        string = INSERT(string, neshangar, text);
                }
                else if(command[1] == ' '&& command[2] != 0){
                    for(int j = 2; command[j] != '\0'; j++)
                        text[j-2] = command[j];
                    if(strstr(text, " "))
                        printf("invalid command\n");
                    else
                        string = INSERT(string, neshangar, text);
                }
                else
                    printf("invalid command\n");
            }
        }
        else if(command[0] == 'p'){
            if(mode == 0)
                printf("invalid command\n");
            else{
                if(command[1] == 0){
                    if(clipboard[0] == '\0')
                        printf("clipboard is empty\n");
                    else
                        string = INSERT(string, neshangar, clipboard);
                }
                else
                    printf("invalid command\n");
            }
        }
        else if(command[0] == 's'){
            if(mode == 1)
                printf("invalid command\n");
            else{
                int number = 0;
                char scw = 0;
                sscanf(command+1, "%d%c", &number, &scw);
                char temp[1000];
                sprintf(temp,"s%d%c", number, scw);
                if(scw != 's' && scw != 'c' && scw != 'w')
                    printf("invalid command\n");
                else if(!strcmp(temp, command))
                    string = SHOW(string, neshangar, number, scw);
                else 
                    printf("invalid command\n");
            }          
        }
        else if(command[0] == 'j'){
            if(mode == 1)
                printf("invalid command\n");
            else{
                int number;
                char scw;
                sscanf(command+1, "%d%c", &number, &scw);
                char temp[1000];
                sprintf(temp,"j%d%c", number, scw);
                if(scw != 's' && scw != 'c' && scw != 'w')
                    printf("invalid command\n");
                else if(!strcmp(temp, command))
                    neshangar = JUMP(string, neshangar, number, scw);
                else 
                    printf("invalid command\n");
            }
        }
        else if(command[0] == '<'){
            if(mode == 1 || command[1] != '\0')
                printf("invalid command\n");
            else
                neshangar = 0;
        }
        else if(command[0] == 'c'){
            if(mode == 1)
                printf("invalid command\n");
            else{
                int number;
                char scw;
                sscanf(command+1, "%d%c", &number, &scw);
                char temp[1000];
                sprintf(temp,"c%d%c", number, scw);
                if(scw != 's' && scw != 'c' && scw != 'w')
                    printf("invalid command\n");
                else if(!strcmp(temp, command))
                    clipboard = COPY(string, neshangar, number, scw);
                else 
                    printf("invalid command\n");
            }          
        }
        else if(command[0] == 'f'){
            if(mode == 1)
                printf("invalid command\n");
            else{
                char text[1000]; 
                char scw;
                sscanf(command+1, "%s %c", text, &scw);
                char temp[10000];
                sprintf(temp,"f %s %c", text, scw);
                if(scw != 's' && scw != 'c' && scw != 'w')
                    printf("invalid command\n");
                else if(!strcmp(temp, command))
                    FIND(string, text, scw);
                else 
                    printf("invalid command\n");
            }          
        }
        else
            printf("invalid command\n");
    }
}
void GETcommands1(char* string){
    char* command = (char*)(calloc(3000, sizeof(char)));
    char* clipboard = (char*)(calloc(3000, sizeof(char)));
    char mode = 1;
    int neshangar = 0;
    while(1){
        scanf("%[^\n]s", command);
        if(command[0] == '#') return;
        getchar();
        if(command[0] == 'R' && (command[1] == '\0' || command[1] == ' '))
            changeMode(0, &mode);
        else if(command[0] == 'E' && (command[1] == '\0' || command[1] == ' ')) 
            changeMode(1, &mode); 
        else if(command[0] == 'd'){
            if(mode == 0)
                printf("invalid command\n");
            else{
                int number = 0;
                char scw = 0;
                sscanf(command + 1, "%d%c", &number, &scw);
                string = DELETE(string, neshangar, number, scw);
            }
        }   
        else if(command[0] == 'i') {
            char* text = (char*)(calloc(3000, sizeof(char)));
            if(mode == 0)
                printf("invalid command\n");
            else{
                if(command[1] == ' ' && command[2] == '"'){
                    for(int j = 3; command[j] != '"'; j++)
                        text[j-3] = command[j];
                    if(!strstr(text, " "))
                        printf("invalid command\n");
                    else
                        string = INSERT(string, neshangar, text);
                }
                else{
                    for(int j = 2; command[j] != '\0'; j++)
                        text[j-2] = command[j];
                    if(strstr(text, " "))
                        printf("invalid command\n");
                    else
                        string = INSERT(string, neshangar, text);
                }
            }
            free(text);
        }
        else if(command[0] == 'p'){
            if(mode == 0)
                printf("invalid command\n");
            else{
                if(clipboard[0] == '\0')
                    printf("clipboard is empty\n");
                else
                    string = INSERT(string, neshangar, clipboard);
            }
        }
        else if(command[0] == 's'){
            if(mode == 1)
                printf("invalid command\n");
            else{
                int number;
                char scw;
                sscanf(command+1, "%d%c", &number, &scw);
                string = SHOW(string, neshangar, number, scw);
            }          
        }
        else if(command[0] == 'j'){
            if(mode == 1)
                printf("invalid command\n");
            else{
                int number;
                char scw;
                sscanf(command+1, "%d%c", &number, &scw);
                neshangar = JUMP(string, neshangar, number, scw);
            }
        }
        else if(command[0] == '<'){
            if(mode == 1)
                printf("invalid command\n");
            else
                neshangar = 0;
        }
        else if(command[0] == 'c'){
            if(mode == 1)
                printf("invalid command\n");
            else{
                int number;
                char scw;
                sscanf(command+1, "%d%c", &number, &scw);
                free(clipboard);
                clipboard = COPY(string, neshangar, number, scw);
            }          
        }
        else if(command[0] == 'f'){
            if(mode == 1)
                printf("invalid command\n");
            else{
                char text[1000]; 
                sscanf(command+2, "%s", text);
                char scw = text[strlen(text) - 1];
                text[strlen(text) - 1] = 0;
                FIND(string, text, scw);
            }          
        }
    }
}
int main(){
    char* string = (char*)(calloc(3000, sizeof(char)));
    string = getText(string);
    function(string);
    return 0;
}