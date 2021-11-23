//
// Created by redfo on 11/22/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define ROWS 10
#define SIZE 32


void del(char *array,int length){
    int i = 0;
    while(i<length){
        if(array[i]==' ' || array[i]=='\t'){
            array[i] = array[i+1];
            i++;
            for(int j = i;j<length;j++){
                array[j] = array[j+1];
            }
        }
        i++;
    }
}

void aloc(char **array){
    for(int i = 0; i < SIZE; i++){
        array[i] = malloc(sizeof(char)*SIZE);
        memset(array[i], '\n', sizeof(char) * SIZE);
    }
}

void fill_array(){

}

int lab10(){
    char **array[ROWS];
    aloc(array);
    for(int i = 0;i<ROWS;i++){
        printf("%s",&array[i]);
    }
    return 0;
}