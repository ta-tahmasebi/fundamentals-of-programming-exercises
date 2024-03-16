#include <stdio.h>
//Amirmahdi Tahmasebi 402106178
int main(){
    int time;
    scanf("%d", &time);
    int clock = time / 60, min = time - clock * 60;
    char c1,c2,c3,c4;
    if (clock / 10 == 0){c1 = 'z';}
    else if (clock / 10 == 1){c1 = 'o';}
    else if (clock / 10 == 2){c1 = 't';}
    else if (clock / 10 == 3){c1 = 't';}
    else if (clock / 10 == 4){c1 = 'f';}
    else if (clock / 10 == 5){c1 = 'f';}
    else if (clock / 10 == 6){c1 = 's';}
    else if (clock / 10 == 7){c1 = 's';}
    else if (clock / 10 == 8){c1 = 'e';}
    else if (clock / 10 == 9){c1 = 'n';}
    if (clock % 10 == 0){c2 = 'z';}
    else if (clock % 10 == 1){c2 = 'o';}
    else if (clock % 10 == 2){c2 = 't';}
    else if (clock % 10 == 3){c2 = 't';}
    else if (clock % 10 == 4){c2 = 'f';}
    else if (clock % 10 == 5){c2 = 'f';}
    else if (clock % 10 == 6){c2 = 's';}
    else if (clock % 10 == 7){c2 = 's';}
    else if (clock % 10 == 8){c2 = 'e';}
    else if (clock % 10 == 9){c2 = 'n';}
    if (min / 10 == 0){c3 = 'z';}
    else if (min / 10 == 1){c3 = 'o';}
    else if (min / 10 == 2){c3 = 't';}
    else if (min / 10 == 3){c3 = 't';}
    else if (min / 10 == 4){c3 = 'f';}
    else if (min / 10 == 5){c3 = 'f';}
    else if (min / 10 == 6){c3 = 's';}
    else if (min / 10 == 7){c3 = 's';}
    else if (min / 10 == 8){c3 = 'e';}
    else if (min / 10 == 9){c3 = 'n';}
    if (min % 10 == 0){c4 = 'z';}
    else if (min % 10 == 1){c4 = 'o';}
    else if (min % 10 == 2){c4 = 't';}
    else if (min % 10 == 3){c4 = 't';}
    else if (min % 10 == 4){c4 = 'f';}
    else if (min % 10 == 5){c4 = 'f';}
    else if (min % 10 == 6){c4 = 's';}
    else if (min % 10 == 7){c4 = 's';}
    else if (min % 10 == 8){c4 = 'e';}
    else if (min % 10 == 9){c4 = 'n';}
    printf("  .-----------------------===------------------------.\n");
    printf("  :o  ______________________________________________  o:\n");
    printf("  ;   :                                            :   ;\n");
    printf("  `.  `.                                          .'  .'\n");
    printf("   :   :                                          :   :\n");
    printf("   `.  `.                 TIME???                .'  .'\n");
    printf("    :   :                  %c%c:%c%c                  :   :\n",c1,c2,c3,c4);
    printf("    `.  `.                                      .'  .'\n     :   :                                      :   :\n     `.  `.                                    .'  .'\n      :   :                                    :   :\n      `.  `.                                  .'  .'\n       :   :__________________________________:   :\n       `.                                        .'\n        '-------------|  |-----|  |--------------'\n");
    printf("       .\"\"\"\"\"\"\"\"\"\"\"\"\"\"|  |\"\"\"\"\"|  |\"\"\"\"\"\"\"\"\"\"\"\"\"\".\n");
    printf("       |  ()          '-----------'      o   ()  |\n       |   ___________________________________   |\n       |  :__|__|__|__|__|__|__|__|__|__|__|__:  |\n       |  |___|__|__|__|__|__|__|__|__|__|__|_|  |\n       |  |__|_|__|__|__|__|__|__|__|__|__|___|  |\n       |  |___|__|__|__|__|__|__|__|__|__|____|  |\n");
    printf("       |  |____|__|__|__|__|__|__|___|__|__|__|  |\n       |  :___|__|___________________|__|__|__:  |\n       |                                         |\n       |             .-------------.             |\n       |             |             |             |\n       |             |             |             |\n       |             |_____________|             |\n       |             |             |             |\n");
    printf("       |             |             |             |\n       |             '.___________.'             |\n       |                   ___                   |\n       '-----------------------------------------'");
    return 0;
}