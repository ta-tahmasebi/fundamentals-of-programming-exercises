#include <stdio.h>
#include <stdlib.h>

//Amirmahdi Tahmasebi 402106178

char getSizeByCode(char code){
    switch (code)
    {
    case 0:
        return 4;
        break;
    case 1:
        return 4;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 2;
        break;
    case 4:
        return 1;
        break;
    case 5:
        return 8;
        break;
    case 6:
        return 4;
        break;
    case 7:
        return 8;
        break;
    }
    return 0;
}

int out(int i, char*bytes, char*lastType , int j){
    switch (*(lastType + i)) {
    case 0:
        printf("%d\n", *((int*)(bytes+j)));
        j += 4;
        break;
    case 1:
        printf("%u\n", *((unsigned int*)(bytes+j)));
        j += 4;
        break;
    case 2:
        printf("%hd\n", *((short*)(bytes+j)));
        j += 2;
        break;
    case 3:
        printf("%hu\n", *((unsigned short*)(bytes+j)));
        j += 2;
        break;
    case 4:
        printf("%c\n", *((char*)(bytes+j)));
        j += 1;
        break;
    case 5:
        printf("%lld\n", *((long long*)(bytes+j)));
        j += 8;
        break;
    case 6:
        printf("%.2e\n", *((float*)(bytes+j)));
        j += 4;
        break;
    case 7:
        printf("%.4e\n", *((double*)(bytes+j)));
        j += 8;
        break;

    default:
        break;
    }
    return j;
}
int get(int i, char*bytes , char * firstTypes, int j){
    if(*(firstTypes+i) == 0){
        int a;
        scanf("%d", &a);
        for(int k = 0; k < 4; k++){
            *(bytes+j) = (char)((a & (255<<((3-k) * 8))) >> ((3-k) * 8));
            j++;
        }
    }
    if(*(firstTypes+i) == 1){
        unsigned int b;
        scanf("%u", &b);
        for(int k = 0; k < 4; k++){
            *(bytes+j) = (char)((b & (255<<((3-k) * 8))) >> ((3-k) * 8));
            j++;
        }
    }
    if(*(firstTypes+i) == 2){
        short c;
        scanf("%hd", &c);
        for(int k = 0; k < 2; k++){
            *(bytes+j) = (char)((c & (255<<((1-k) * 8))) >> ((1-k) * 8));
            j++;
        }
    }
    if(*(firstTypes+i) == 3){
        unsigned short d;
        scanf("%hu", &d);
        for(int k = 0; k < 2; k++){
            *(bytes+j) = (char)((d & (255<<((1-k) * 8))) >> ((1-k) * 8));
            j++;
        }
    }
    if(*(firstTypes+i) == 4){
        char e;
        do{
        scanf("%c", &e);
        }while (e == '\n' || e == ' ');
        for(int k = 0; k < 1; k++){
            *(bytes+j) = (char)((e & (255<<((0-k) * 8))) >> ((0-k) * 8));
            j++;
        }
    }
    if(*(firstTypes+i) == 5){
        long long f;
        scanf("%lld", &f);
        for(int k = 0; k < 8; k++){
            *(bytes+j) = (char)((f & (255ll<<((7ll-(long long)k) * 8ll))) >> ((7ll-(long long)k) * 8ll));
            j++;
        }
    }
    return j;
}

int main(){
    int n;
    scanf("%d" , &n);
    char * firstTypes = (char *)(malloc(sizeof(char) * n));
    int sumOfBytes = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        scanf("%hhu", firstTypes+i);
        sumOfBytes += getSizeByCode(*(firstTypes+i));
    }
    char* bytes = (char *)(malloc(sizeof(char) * sumOfBytes));
    for(int i = 0; i < n; i++){
        j = get(i,bytes,firstTypes, j);
    }
    j = 0;
    scanf("%d" , &n);
    char * lastTypes = (char *)(malloc(sizeof(char) * n));
    for(int i = 0; i < n; i++){
        scanf("%hhu", lastTypes+i);
    }
    for(int i = 0; i < n; i++){
        j = out(i, bytes, lastTypes, j);
    }
    return 0;
}