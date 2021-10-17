#include <stdio.h>
#include <stdlib.h>
#define OLD 60
#define YOUNG 18
#include "common.c"

/*
 1 - год
 2 - года
 3 - лет
 */
char* age_check(int age){
    age = abs(age);
    int v;
    int last = age % 10;
    if (age >= 11 && age <= 14){
        v = 3;
    }else if(last == 1){
        v = 1;
    }else if(last >= 2 && last <= 4){
        v = 2;
    }else{
        v = 3;
    }
    switch(v){
        case 1:
            return "год";
        case 2:
            return "года";
        case 3:
            return "лет";
        default:
            return "ОШИБКА!!!!";
    }
}


int lab5(){
    int age, to_old, to_young;
    printf("Введите ваш возраст от 1 до 100: ");
    age = check();
    to_young = YOUNG - age;
    to_old = OLD - age;
    char* age_type = age_check(age);
    char* young_type = age_check(to_young);
    char* old_type = age_check(to_old);
    printf("Ваш возраст %d %s\n", age, age_type);
    if(to_young > 0){
        printf("Вам до совершеннолетия ещё %d %s\n",to_young, young_type);
    }else if(to_young < 0){
        printf("Вы совершеннолетний уже целых %d %s\n", abs(to_young), young_type);
    }else{
        printf("Вы совершеннолетний\n");
    }
    if(to_old > 0){
        printf("Вам до пенсии ещё %d %s",to_old, old_type);
    }else if(to_old < 0){
        printf("Вы на пенсии уже целых %d %s", abs(to_old), old_type);
    }else{
        printf("Вы пенсионер");
    }
    return 0;
}

