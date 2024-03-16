#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//Amirmahdi Tahmasebi 402106178

void action(unsigned char* bytes){
    unsigned int command = (bytes[0] & 252) >> 2;
    if(command == 8 || command == 12 || command == 13 || command == 35 || command == 32 || command == 43 || command == 40){ // i format
        unsigned int rs = ((bytes[0] & 3) << 3) + ((bytes[1] & 224) >> 5);
        unsigned int rt = ((bytes[1] & 31));
        unsigned int imm = (bytes[2] << 8) + bytes[3];
        if(command == 8)
            printf("addi $%d, $%d, %d\n", rt, rs, imm);
        if(command == 12)
            printf("andi $%d, $%d, %d\n", rt, rs, imm);
        if(command == 13)
            printf("ori $%d, $%d, %d\n", rt, rs, imm);
        if(command == 35)
            printf("lw $%d, %d($%d)\n", rt, imm, rs);
        if(command == 32)
            printf("lb $%d, %d($%d)\n", rt, imm, rs);
        if(command == 43)
            printf("sw $%d, %d($%d)\n", rt, imm, rs);
        if(command == 40)
            printf("sb $%d, %d($%d)\n", rt, imm, rs);
    }
    if(command == 2 || command == 3){ // j format
        unsigned int address = bytes[3] + (bytes[2] << 8) +(bytes[1] << 16) + ((bytes[0] & 3) << 24);
        if(command == 2)    
            printf("j %X\n", address);
        if(command == 3)
            printf("jal %X\n", address);
    }
    if(command == 0){ //r format
        unsigned int rs = ((bytes[0] & 3) << 3) + ((bytes[1] & 224) >> 5);
        unsigned int rt = (bytes[1] & 31);
        unsigned int rd = ((bytes[2] & 248) >> 3);
        unsigned int shamt = ((bytes[2] & 7) << 2) + ((bytes[3] & 192) >> 6);
        unsigned int func = bytes[3] & 63;
        if(func == 0)
            printf("sll $%d, $%d, %d\n", rd, rt, shamt);
        if(func == 2)
            printf("srl $%d, $%d, %d\n", rd, rt, shamt);
        if(func == 32)
            printf("add $%d, $%d, $%d\n", rd, rs, rt);
        if(func == 34)
            printf("sub $%d, $%d, $%d\n", rd, rs, rt);
        if(func == 37)
            printf("or $%d, $%d, $%d\n", rd, rs, rt);
        if(func == 38)
            printf("xor $%d, $%d, $%d\n", rd, rs, rt);
    }
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "rb");
    if(file == NULL){
        printf("File not found\n");
        return 1;
    }
    unsigned char buf[300];
    size_t bytes = 0, byte, readsz = sizeof buf;
    while ((bytes = fread (buf, sizeof *buf, readsz, file)) == readsz);
    for (byte = 0; byte < bytes/4; byte++){
        unsigned char* data = (unsigned char*)calloc(4, sizeof(char));
        data[0] = buf[byte * 4 + 0];
        data[1] = buf[byte * 4 + 1];
        data[2] = buf[byte * 4 + 2];
        data[3] = buf[byte * 4 + 3];
        action(data);
    }
}