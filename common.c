//
// Created by Илья Коваленко on 17.10.2021.
//

int check(void){
    int a = 0;
    while (scanf("%d",&a)!= 1 || a > 100 || a < 1){
        while(getchar() != '\n'){
        }
        printf("Введите корректное число: ");
    }
    return a;
}
