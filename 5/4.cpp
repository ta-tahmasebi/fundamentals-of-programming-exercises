#include "grader.h"
#include <stdio.h>

//Amirmahdi Tahmasebi 402106178

int convertToInt(char c){
    switch (c)
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    case 'G':
        return 16;
    case 'H':
        return 17;
    case 'I':
        return 18;
    case 'J':
        return 19;
    case 'K':
        return 20;
    case 'L':
        return 21;
    case 'M':
        return 22;
    case 'N':
        return 23;
    case 'O':
        return 24;
    case 'P':
        return 25;
    case 'Q':
        return 26;
    case 'R':
        return 27;
    case 'S':
        return 28;
    case 'T':
        return 29;
    case 'U':
        return 30;
    case 'V':
        return 31;
    case 'W':
        return 32;
    case 'X':
        return 33;
    case 'Y':
        return 34;
    case 'Z':
        return 35;
    default:
        break;
    }
    return 0;
}

unsigned long long findValue(unsigned long long address){
    unsigned long long value = 0;
    unsigned long long power = 1;
    for(int i = 0; i < 8; i++){
        unsigned char b = (*((char *)(address + i)));
        unsigned long long a = ((unsigned long long)b);
        value += a * power;
        power *= 256;
    }
    return value;
}

unsigned long long finalValu(unsigned long long address, int count){
    unsigned long long value = 0;
    unsigned long long power = 1;
    for(int i = 0; count > 0; i++, count --){
        unsigned char b = (*((char *)(address + i)));
        unsigned long long a = ((unsigned long long)b);
        value += a * power;
        power *= 256;
    }
    return value;
}

void value(int level, int count, unsigned long long address){
    for(int i = level; i > 1; i--){
        address = findValue(address);
    }
    printf("%llu\n", finalValu(address, count));
}

void decryption(char *input){
    char cm;
    unsigned long long nm;
    int header = 0;
    cm = input[header];
    nm = 0;
    while(cm != '\n' && cm != ' ' && cm != '\0' && cm!= '.'){
        nm *= (unsigned long long)(10);
        nm += (unsigned long long)convertToInt(cm);
        cm = input[header+1];
        (header) ++;
    }
    header++;
    int n = (int)(nm);
    for(int i = 0; i < n; i++){
        cm = input[header];
        nm = 0;
        while(cm != '\n' && cm != ' ' && cm != '\0' && cm!= '.'){
            nm *= (unsigned long long)(10);
            nm += (unsigned long long)convertToInt(cm);
            cm = input[header+1];
            (header) ++;
        }
        header++;
        int base = nm;
        cm = input[header];
        nm = 0;
        while(cm != '\n' && cm != ' ' && cm != '\0' && cm!= '.'){
            nm *= (unsigned long long)(10);
            nm += (unsigned long long)convertToInt(cm);
            cm = input[header+1];
            (header) ++;
        }
        header++;
        int count = nm;
        cm = input[header];
        nm = 0;
        while(cm != '\n' && cm != ' ' && cm != '\0' && cm!= '.'){
            nm *= (unsigned long long)(10);
            nm += (unsigned long long)convertToInt(cm);
            cm = input[header+1];
            (header) ++;
        }
        header++;
        int level = nm;
        cm = input[header];
        nm = 0;
        while(cm != '\n' && cm != ' ' && cm != '\0' && cm!= '.'){
            nm *= (unsigned long long)(base);
            nm += (unsigned long long)convertToInt(cm);
            cm = input[header+1];
            (header) ++;
        }
        header++;
        unsigned long long address = nm;
        value(level, count, address);
    }
}