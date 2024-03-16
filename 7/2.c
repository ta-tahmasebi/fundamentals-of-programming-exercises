#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Amirmahdi Tahmasebi 402106178

struct lesson {
    int id;
    int vahed;
    int average;
    int pishniaz;
    char name[100];
    struct lesson* next;
    struct lesson* perv;
};
char * connectTwoString(char* a, char* b){
    char* str3 = (char*)calloc(10000,1);
    int i = 0, j = 0;   
    while (a[i] != '\0') {
        str3[j] = a[i];
        i++;
        j++;
    }
    i = 0;
    while (b[i] != '\0') {
        str3[j] = b[i];
        i++;
        j++;
    }
    str3[j] = '\0';
    return str3;
}
char* convert(int a){
    char *b = (char*)calloc(1000,1);
    sprintf(b, "%d", a);
    return b;
}
struct info{ 
    float sum;
    float count;
    char way[10000];
    int id_next;
};
struct kol{
    float average; 
    char way[10000];
    struct kol * next;
};


void takmil(struct lesson* dars, struct info a, struct kol* k){
    char flag = 1;
    struct lesson* tempName = dars;
    while(1){
        if(tempName->pishniaz == a.id_next){
            struct info b;
            b.count = a.count + tempName->vahed;
            b.sum = a.sum + tempName->average * tempName->vahed;
            strcpy(b.way, connectTwoString(a.way,connectTwoString("\n", connectTwoString(tempName->name, connectTwoString(" ", convert(tempName->id))))));
            b.id_next = tempName->id;
            flag = 0;
            takmil(dars, b, k);
        }
        tempName = tempName->next;
        if(!tempName){
            break;
        }
    }
    if(flag){
        struct kol* temp = k;
        while(1){
            if(temp->next==NULL){
                temp->next = (struct kol*)calloc(1,sizeof(struct kol));
                temp->next->next = NULL;
                temp->next->average = a.sum/a.count;
                strcpy(temp->next->way, a.way);
                temp = temp->next;
                break;
            }
            temp = temp->next;
        }
    }
}


int main() {
    int n;
    scanf("%d", &n);
    struct lesson* a = (struct lesson*)calloc(1,sizeof(struct lesson*));
    struct lesson* b = a;
    for(int i = 1; i <= n; i++){
        scanf("%s %d %d %d %d", (a->name), &(a->id), &(a->vahed), &(a->average), &(a->pishniaz));
        a->next = (struct lesson*)calloc(1,sizeof(struct lesson));
        a->next->perv = a;
        a = a-> next;
    }
    a = a->perv;
    a->next = NULL;
    a = b;
    a->perv = NULL;
    struct info c;
    c.count= 0;
    c.id_next = 0;
    c.sum = 0;
    struct kol * k = (struct kol*)(calloc(1, sizeof(struct kol)));
    k->average = 0;
    k->next = NULL;
    strcpy(k->way, "");
    strcpy(c.way, "");
    takmil(a, c, k);
    
    float max = 0;
    struct kol * t = k;
    while(t->next){
        t = t->next;
        if(max < t->average){
            max = t->average;
        }
    }
    struct kol * tt = k;
    while(tt->next){
        tt = tt->next;
        if(tt->average < max + 0.0005 && tt->average > max - 0.0005)
            printf("%d%s\n", (int)(tt->average), tt->way);
    }
    return 0;
}