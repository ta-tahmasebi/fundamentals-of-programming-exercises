#include <stdio.h>
#include<stdlib.h>

//Amirmahdi Tahmasebi 402106178

int main() {
    int N;
    int *p = &N;
    scanf("%d", p);
    int *integers;
    integers = malloc(N * sizeof(int));
    char ans = 1;
    for (int i = 0; i < N; i++) 
        scanf("%d", integers + i);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 4; j++){
            char c;
            do
                scanf("%c", &c);
            while(c == '\n');
            char k = (255<<(8*(j)) & *(integers + i)) >> (8*(j));
            if (k != c)
                ans = 0;
        }
    if(ans)
        printf("Yes");
    else
        printf("No");
    return 0;
}