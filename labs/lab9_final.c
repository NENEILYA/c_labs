/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

void fillMass(int result[][SIZE+1], char var[]){
    for(int i = 0;i < SIZE; i++){
        for(int j = i;j < SIZE; j++){
            if(j==i){
                result[i][j] = 0;
            }else{
                int idx = (rand() % 3);
                result[i][j] = var[idx];
                result[j][i] = var[2-idx];
            }
        }
    }
}

int summary(char letter, int result[][SIZE+1]){
    int max = 0;
    for(int i=0;i<SIZE;i++){
        result[i][SIZE] = 0;
        printf("%c ",letter+i);
        for(int j=0;j<SIZE;j++){
            printf("%d ", result[i][j]);
            result[i][SIZE] += result[i][j];
        }
        if (result[i][SIZE] > max){
            max = result[i][SIZE];
        }
        printf(" Summary: %d",result[i][SIZE]);
        printf("\n");
    }
    return max;
}

void max_top(int max, int result[][SIZE+1], char letter){
    for(int i=0; i<SIZE;i++){
        if(result[i][SIZE]==max){
            printf("%c ", letter+i);
        }
    }
}

int main(){
    int win=3, draw=1, lose=0;
    printf("\n");
    int result[SIZE+1][SIZE+1];
    char var[] = {win, draw, lose};
    srand(time(NULL));
    fillMass(result, var);
    char letter = 'a';
    printf("  ");
    for(int i=0;i<SIZE;i++){
        printf("%c ",letter+i);
    }
    printf("\n");
    int topTeams[SIZE];
    for(int i=0;i<SIZE;i++){
        topTeams[i] = -1;
    }
    int max = summary(letter, result);
    printf("Max score: %d\nTeams with max score: ",max);
    max_top(max, result, letter);
    printf("\n");
    return 0;
}
*/