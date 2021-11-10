//
// Created by Илья Коваленко on 06.11.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "../common.c"



int lab9(){
    int teams, lose, draw, win;
    printf("Введите колличество команд: ");
    teams = check_int();
    printf("Введите кол-во очков за победу: ");
    scanf("%d",&win)
    printf("Введите кол-во очков за поражение: ");
    scanf("%d",&lose);
    printf("Введите кол-во очков за ничью: ");
    scanf("%d",&draw);
    char result[teams][teams];
}
