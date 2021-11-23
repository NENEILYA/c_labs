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

bool if_in_range(int x, int start, int end){
    if (start <= x && x <= end) return true;
    else return false;
}

int check_int(int min, int max, char inf){
    int a = 0;
    if(min == max){
        while (scanf("%i",&a)!= 1){
            while(getchar() != '\n'){
            }
            printf("Enter valid value: ");
        }
        return a;
    }else if(inf == 'L'){
        while (scanf("%i",&a)!= 1 || a > max){
            while(getchar() != '\n'){
            }
            printf("Enter valid value: ");
        }
        return a;
    }else if(inf == 'R'){
        while (scanf("%i",&a)!= 1 || a < min){
            while(getchar() != '\n'){
            }
            printf("Enter valid value: ");
        }
        return a;
    }else{
        while (scanf("%i",&a)!= 1 || a > max || a < min){
            while(getchar() != '\n'){
            }
            printf("Enter valid value: ");
        }
        return a;
    }

}