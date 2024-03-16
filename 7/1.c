#include <stdio.h>
#include <stdlib.h>

//Amirmahdi Tahmasebi 402106178


//variables
int max = 1;
struct player {
    int number;
    struct player* next;
    struct player* perv;
};
//end of variables
//portotypes
void get_1_type(struct player*);
void get_2_type(struct player*);
//end of portotypes

void get_1_type(struct player* neshangar){
    int number;
    char BF;
    scanf("%d%c", &number, &BF);
    while(number > 0){
        if(BF == 'F')
            neshangar = neshangar->next;
        else
            neshangar = neshangar->perv;
        number--;
    }
    printf("%d\n", neshangar->number);
    get_2_type(neshangar);
}
void get_2_type(struct player* neshangar){
    char text[20];
    scanf("%s", text);
    if(text[0] == 'A'){
        struct player* a = (struct player*)calloc(1, sizeof(struct player*));
        a->next = neshangar->next;
        a->next->perv = a;
        a ->number = max;
        max++;
        a->perv = neshangar;
        neshangar->next = a;
        neshangar = a;
    }
    if(text[0] == 'R'){
        neshangar->perv->next = neshangar->next;
        neshangar->next->perv = neshangar->perv;
        neshangar = neshangar->next;
    }
    if(text[0] == 'E')
        return;
    printf("%d\n", neshangar->number);
    get_1_type(neshangar);
}
int main() {
    int n;
    scanf("%d", &n);
    max += n;
    struct player* a = (struct player*)calloc(1,sizeof(struct player*));
    struct player* b = a;
    for(int i = 1; i <= n; i++){
        a->number = i;
        a->next = (struct player*)calloc(1,sizeof(struct player*));
        a->next->perv = a;
        a = a-> next;
    }
    a = a->perv;
    a->next = b;
    b->perv = a;
    get_1_type(b);   
    return 0;
}