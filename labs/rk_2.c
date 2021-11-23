
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define ROWS 4
#define COLUMNS 5

void print_mass(int mass_1[][COLUMNS], int mass_2[][ROWS]){
    int summary[9] = {0}, sum = 0;
    char letter = 'a';
    printf("\nFirst mass:\n");
    printf("  ");
    for(int i=0;i<COLUMNS;i++){
        printf("%c  ",letter+i);
    }
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        sum = 0;
        printf("%c ",letter+i);
        for(int j = 0;j < COLUMNS; j++){
            if(mass_1[i][j] == 10){
                printf("%d ", mass_1[i][j]);
            }else{
                printf("%d  ", mass_1[i][j]);
            }
            sum += mass_1[i][j];
            summary[i] = sum;
        }
        printf("\n");
    }
    printf("\nSecond mass:\n");
    printf("  ");
    for(int i=0;i<ROWS;i++){
        printf("%c  ",letter+i);
    }
    printf("\n");
    for(int i = 0, k=8; i < COLUMNS; i++, k--){
        sum = 0;
        printf("%c ",letter+i);
        for(int j = 0;j < ROWS; j++){
            if(mass_2[i][j] == 10){
                printf("%d ", mass_2[i][j]);
            }else {
                printf("%d  ", mass_2[i][j]);
            }
            sum += mass_2[i][j];
        }
        summary[k] = sum;
        printf("\n");
    }
    printf("\nThe sum of the columns of the first array: ");
    for(int i = ROWS;i<ROWS+COLUMNS;i++){
        printf("%c) %d ",letter+i-ROWS ,summary[i]);
    }
    printf("\nThe sum of the columns of the second array: ");
    for(int i = 0;i<ROWS;i++){
        printf("%c) %d ",letter+i ,summary[i]);
    }
    printf("\n");
}


void  init_fill(int mass_1[][COLUMNS]){
    for(int i = 0; i<ROWS;i++) {
        for (int j = 0; j < COLUMNS; j++) {
            mass_1[i][j] = rand() % 10 + 1;
        }
    }
}

void transpose_backwards(int mass_1[][COLUMNS], int mass_2[][ROWS]){
    for(int i=0;i<ROWS;i++){
        for(int j = 0;j < COLUMNS;j++){
            mass_2[j][i] = mass_1[i][COLUMNS-j-1];
        }
    }
}

int rk_2(){
    srand(time(NULL));
    int mass_1[ROWS][COLUMNS];
    int mass_2[COLUMNS][ROWS];
    init_fill(mass_1);
    transpose_backwards(mass_1, mass_2);
    print_mass(mass_1 ,mass_2);
    return 0;
}
