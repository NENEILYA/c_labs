//
// Created by Илья Коваленко on 17.10.2021.
//

#include <stdio.h>
#include "../common.c"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10
#define DATACOUNT 50

const char mapping[] = {'0', '1', '2', '3',
                        '4', '5', '6', '7',
                        '8', '9', 'A', 'B',
                        'C', 'D', 'E', 'F'};
struct numbs{
    int i;
    double f;
};

struct numbs split(double input){
    struct numbs result;
    double tmp;
    result.f = modf(input, &tmp);
    result.i = (int) tmp;
    return result;
}


int convI(int tmp, int ind, char* result){
    int rest;
    int i = 0;
    while(tmp != 0){
        rest = tmp%ind;
        tmp = tmp/ind;
        char mapped = mapping[rest];
        result[i] = mapped;
        i+=1;
    }
    int size = 0;
    for(i=DATACOUNT-1;i!=-1;i--){
        if (result[i] != '\n'){
            size = i+1;
            break;
        }
    }
    return size;
}


void convF(double tmp, int ind, char* result){
    double rest;
    int i = 0;
    while(tmp != 0 && i != SIZE-1){
        rest = tmp*ind;
        struct numbs step = split(rest);
        tmp = step.f;
        char mapped = mapping[step.i];
        *(result+i) = mapped;
        i+=1;
    }
}

int lab6(){
    printf("Введите десятичное вещественное число: ");
    double input = check_double();
    int ind = 0;
    while (!if_in_range(ind,2,16)){
        printf("Введите число от 2 до 16: ");
        ind = check_int();
    }
    struct numbs splited = split(input);

    char f[SIZE] = {'0'};
    convF(splited.f, ind, f);
    char* i;
    i = malloc(sizeof(char) * DATACOUNT);
    memset(i, '\n', sizeof(char) * DATACOUNT);
    int size = convI(splited.i, ind, i);
    char la_finale[size];
    for(int n=1;n<=size;n++){
        la_finale[size - n] = i[n-1];
    }
    printf("Результат: %s.%s", la_finale, f);
    return 0;
}