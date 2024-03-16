#include<stdio.h>
// Amirmahdi Tahmasebi 402106178
int main() {
    char s[1000001];
    for(int i = 0; i < 1000001; i++) s[i]='.';
    int l = 0;
    while(1){
        char c;
        scanf("%c",&c);
        if(c=='\n') break;
        s[l] = c;
        l++;
    }
    for(int i = 0; i<1000001; i++){
        int token;
        int count = 0;
        if(s[i] == ' '){token = 0; count = 2;}
        else if(s[i] == '0'){token = 0; count = 1;}
        else if(s[i] == '1'){token = 1; count = 1;}
        else if(s[i] == '2'){token = 2; count = 1;}
        else if(s[i] == '3'){token = 3; count = 1;}
        else if(s[i] == '4'){token = 4; count = 1;}
        else if(s[i] == '5'){token = 5; count = 1;}
        else if(s[i] == '6'){token = 6; count = 1;}
        else if(s[i] == '7'){token = 7; count = 1;}
        else if(s[i] == '8'){token = 8; count = 1;}
        else if(s[i] == '9'){token = 9; count = 1;}
        else if(s[i] == 'a'){token = 1; count = 2;}
        else if(s[i] == 'b'){token = 1; count = 3;}
        else if(s[i] == 'c'){token = 1; count = 4;}
        else if(s[i] == 'd'){token = 2; count = 2;}
        else if(s[i] == 'e'){token = 2; count = 3;}
        else if(s[i] == 'f'){token = 2; count = 4;}
        else if(s[i] == 'g'){token = 3; count = 2;}
        else if(s[i] == 'h'){token = 3; count = 3;}
        else if(s[i] == 'i'){token = 3; count = 4;}
        else if(s[i] == 'j'){token = 4; count = 2;}
        else if(s[i] == 'k'){token = 4; count = 3;}
        else if(s[i] == 'l'){token = 4; count = 4;}
        else if(s[i] == 'm'){token = 5; count = 2;}
        else if(s[i] == 'n'){token = 5; count = 3;}
        else if(s[i] == 'o'){token = 5; count = 4;}
        else if(s[i] == 'p'){token = 6; count = 2;}
        else if(s[i] == 'q'){token = 6; count = 3;}
        else if(s[i] == 'r'){token = 6; count = 4;}
        else if(s[i] == 's'){token = 7; count = 2;}
        else if(s[i] == 't'){token = 7; count = 3;}
        else if(s[i] == 'u'){token = 7; count = 4;}
        else if(s[i] == 'v'){token = 8; count = 2;}
        else if(s[i] == 'w'){token = 8; count = 3;}
        else if(s[i] == 'x'){token = 8; count = 4;}
        else if(s[i] == 'y'){token = 9; count = 2;}
        else if(s[i] == 'z'){token = 9; count = 3;}
        int k;
        for(k = 0; k < count; k++){
            printf("%d",token);
        }
        if(k){
            printf(" ");
        }
    }
    return 0;
}