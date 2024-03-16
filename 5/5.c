#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Amirmahdi Tahmasebi 402106178

void print(int ** matrix, int n, int m){
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            printf("%d ", *(*(matrix + i) + j));
        printf("\n");
    }
}
int ** ravel (int ** first, int* n, int* m){
    int** matrix = (int**)malloc(sizeof(int*) * 1);
    *(matrix) = (int*)malloc(sizeof(int) * (*m) * (*n));
    for(int i = 0; i < *n; i++){
        for (int j = 0; j < *m; j++){
            *(*matrix + (*m) * i + j) = *(*(first + i) + j);
        }
    }
    *m = (*m) * (*n);
    *n = 1;
    return matrix;
}
int ** reshape(int ** first, int*n, int *m, int i, int j){
    int** matrix = (int**)malloc(sizeof(int*) * i);
    for(int k = 0; k < i; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * j);
    int * nn = n;
    int * mm = m;
    first = ravel(first , nn, mm);
    for(int k = 0; k < i; k++){
        for (int h = 0; h < j; h++){
            *(*(matrix + k) + h) = *(*first + k * j + h);
        }
    }
    *n = i;
    *m = j;
    return matrix;
}
int ** resizee(int ** first, int*n, int *m, int i, int j){
    int** matrix = (int**)malloc(sizeof(int*) * i);
    for(int k = 0; k < i; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * j);
    int * nn = n;
    int * mm = m;
    first = ravel(first , nn, mm);
    for(int k = 0; k < i; k++){
        for (int h = 0; h < j; h++){
            *(*(matrix + k) + h) = *(*first + (k * j + h) % (*n * *m));
        }
    }
    *n = i;
    *m = j;
    return matrix;
}
int ** append_row (int ** first, int * new, int* n, int *m){
    int** matrix = (int**)malloc(sizeof(int*) * (*n + 1));
    for(int k = 0; k < *n + 1; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * *m);
    int k;
    for(k = 0; k < *n; k++)
        for(int u = 0; u < *m; u++)
            *(*(matrix + k) + u) = *(*(first + k)+u);
    for(int u = 0; u < *m; u++)
            *(*(matrix + k) + u) = *(new+u);
    *n += 1;
    return matrix;
}
int ** insert_row (int ** first, int * new, int* n, int *m, int r){
    int** matrix = (int**)malloc(sizeof(int*) * (*n + 1));
    for(int k = 0; k < *n + 1; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * *m);
    int k;
    for(k = 0; k < r; k++)
        for(int u = 0; u < *m; u++)
            *(*(matrix + k) + u) = *(*(first + k)+u);
    for(int u = 0; u < *m; u++)
        *(*(matrix + r) + u) = *(new+u);
    for(k = r+1; k < *n + 1; k++)
        for(int u = 0; u < *m; u++)
            *(*(matrix + k) + u) = *(*(first + k - 1)+u);
    *n += 1;
    return matrix;
}
int ** append_column (int ** first, int * new, int* n, int *m){
    int** matrix = (int**)malloc(sizeof(int*) * (*n));
    for(int k = 0; k < *n + 1; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * (*m + 1));
    for(int k = 0; k < *n; k++){
        int u;
        for(u = 0; u < *m; u++)
            *(*(matrix + k) + u) = *(*(first + k)+u);
        *(*(matrix + k) + u) = *(new + k);
    }
    *m += 1;
    return matrix;
}
int ** insert_column (int ** first, int * new, int* n, int *m, int c){
    int** matrix = (int**)malloc(sizeof(int*) * (*n));
    for(int k = 0; k < *n + 1; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * (*m + 1));
    for(int k = 0; k < *n; k++){
        int u;
        for(u = 0; u < c; u++)
            *(*(matrix + k) + u) = *(*(first + k)+u);
        *(*(matrix + k) + c) = *(new + k);
        for(u = c+1; u < *m + 1; u++)
            *(*(matrix + k) + u) = *(*(first + k)+u-1);
    }
    *m += 1;
    return matrix;
}
int ** delete_row(int** first, int*n, int*m, int r){
    int** matrix = (int**)malloc(sizeof(int*) * (*n - 1));
    for(int k = 0; k < *n - 1; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * (*m));
    int k;
    for(k = 0; k < r; k++)
        for(int u = 0; u < *m; u++)
            *(*(matrix + k) + u) = *(*(first + k)+u);
    for(k = r+1; k < *n; k++)
        for(int u = 0; u < *m; u++){
            *(*(matrix + k - 1) + u) = *(*(first + k)+u);
        }
    *n -= 1;
    return matrix;
}
int ** delete_column(int** first, int*n, int*m, int c){
    int** matrix = (int**)malloc(sizeof(int*) * (*n));
    for(int k = 0; k < *n; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * (*m));
    for(int k = 0; k < *n; k++){
        int u;
        for(u = 0; u < c; u++)
            *(*(matrix + k) + u) = *(*(first + k)+u);
        for(u = c+1; u < *m+1; u++)
            *(*(matrix + k) + u-1) = *(*(first + k)+u);
    }
    *m -= 1;
    return matrix;
}
int ** tile(int** first, int*n, int*m, int r , int c){
    int** matrix = (int**)malloc(sizeof(int*) * (*n) * r);
    for(int k = 0; k < *n * r; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * (*m) * c);
    for(int k = 0; k < *n * r; k++){
        for(int u = 0; u < *m * c; u++)
            *(*(matrix + k) + u) = *(*(first + (k%(*n)))+(u%(*m)));
    }
    *m *= c;
    *n *= r;
    return matrix;
}
int ** transpose(int** first, int*n, int*m){
    int** matrix = (int**)malloc(sizeof(int*) * (*m));
    for(int k = 0; k < *m; k++)
        *(matrix + k) = (int*)malloc(sizeof(int) * (*n));
    for(int k = 0; k < *n; k++)
        for(int u = 0; u < *m; u++)
            *(*(matrix + u) + k) = *(*(first + k) + u); 
    int temp = *n;
    *n = *m;
    *m = temp;
    return matrix;
}
void commands(int** matrix, int n, int m){
    while(1){
        char t;
        do{
        scanf("%c", &t);
        }while(t =='\n' || t == ' ');
        char *input = (char*)malloc(17);
        for(int i = 0; i < 17; i++){
            *(input + i) = '\0';
        }
        scanf("%[^\n]s", input); 
        if(!strcmp(input, "avel")){
            matrix = ravel(matrix, &n, &m);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "eshape")){
            int i, j;
            scanf("%d %d", &i, &j);
            matrix = resizee(matrix, &n, &m, i, j);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "esize")){
            int i, j;
            scanf("%d %d", &i, &j);
            matrix = resizee(matrix, &n, &m, i, j);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "ppend_row")){
            int * new = (int*)(malloc(sizeof(int *) * m));
            for(int i = 0; i < m; i++){
                scanf("%d", (new + i));
            } 
            matrix = insert_row(matrix, new, &n, &m, n);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "nsert_row")){
            int * new = (int*)(malloc(sizeof(int *) * m));
            int r;
            scanf("%d",  &r);
            for(int i = 0; i < m; i++){
                scanf("%d", new + i);
            } 
            matrix = insert_row(matrix, new, &n, &m, r);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "ppend_column")){
            int * new = (int*)(malloc(sizeof(int *) * n));
            for(int i = 0; i < n; i++){
                scanf("%d", new + i);
            } 
            matrix = insert_column(matrix, new, &n, &m, m);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "nsert_column")){
            int * new = (int*)(malloc(sizeof(int *) * n));
            int c;
            scanf("%d", &c); 
            for(int i = 0; i < n; i++){
                scanf("%d", new + i);
            }
            matrix = insert_column(matrix, new, &n, &m, c);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "elete_row")){
            int r;
            scanf("%d", &r);
            matrix = delete_row(matrix, &n, &m, r);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "elete_column")){
            int r;
            scanf("%d", &r);
            matrix = delete_column(matrix, &n, &m, r);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "ile")){
            int r, c;
            scanf("%d %d", &r , &c);
            matrix = tile(matrix, &n, &m, r , c);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "ranspose")){
            matrix = transpose(matrix, &n, &m);
            print(matrix,n,m);
        }
        else if(!strcmp(input, "xit")){
            break;
        }
    }    
}
int main(){
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d" , &m);
    int** matrix = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        *(matrix+i) = (int*)malloc(sizeof(int) * m);
        for(int j = 0; j < m; j++)
            scanf("%d", (*(matrix + i) + j));
    }
    commands(matrix, n, m);
    return 0;
}