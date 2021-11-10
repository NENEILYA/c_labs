
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
                printf("%d",&result[i][j]);
                *(result+i*j) = 0;
            }else{
                *(result+i*j) = *(var+(rand() % 3));
                printf("%d",&result[i][j]);
            }
        }
    printf("\n");
    }
}


int lab9(){
    int teams, win, lose, draw;
    printf("Teams count:");
    teams = check_int();
    printf("Enter win:");
    win = check_int();
    printf("Enter lose:");
    lose = check_int();
    printf("Enter draw:");
    draw = check_int();
    int* result[16][16];
    int* var[3] = {win, lose, draw};
    fillMass(teams, &result, &var);
    return 0;
}
