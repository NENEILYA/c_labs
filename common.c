//
// Created by Илья Коваленко on 17.10.2021.
//
#include <stdbool.h>
#include <stdio.h>

double check_double(void){
    double a = 0;
    while (scanf("%lf",&a) != 1){
        while(getchar() != '\n'){
        }
        printf("Введите корректное число: ");
    }
    return a;
}

int check_int(void){
    int a = 0;
    while (scanf("%i",&a)!= 1 || a<0){
        while(getchar() != '\n'){
        }
        printf("Enter valid value: ");
    }
    return a;
}

bool if_in_range(int x, int start, int end){
    if (start <= x && x <= end) return true;
    else return false;
}

int check_int_spec(void){
    int a = 0;
    while (scanf("%i",&a)!= 1 || a<=0 || a>=16){
        while(getchar() != '\n'){
        }
        printf("Enter valid value: ");
    }
    return a;
}