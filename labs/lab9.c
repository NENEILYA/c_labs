
//
// Created by Илья Коваленко on 06.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../common.c"


int fillMass( int teams, int* result,int* var){
    srand(time(NULL));
    for(int i = 0;i < teams; i++){
        for(int j = i;j < teams; j++){
            if(j==i){
                *(result+16*i+j) = 0;
            }else{
                int idx = (rand() % 3);
                *(result+16*i+j) = *(var+idx);
                *(result+16*j+i) = *(var+2-idx);
            }
        }
    }
}


int lab9(){
    int teams, win, draw, lose;
    printf("Teams count:");
    teams = check_int();
    printf("Enter win:");
    win = check_int();
    printf("Enter lose:");
    lose = check_int();
    printf("Enter draw:");
    draw = check_int();
    int result[16][16];
    int var[3] = {win, draw, lose};
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            result[i][j] = 0;
        }
    }
    printf("\n");
    fillMass(teams, (int *) &result, (int *) &var);
    for(int i=0;i<teams;i++){
        for(int j=0;j<teams;j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
