#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define BUFFER 1024
#define SIZE 64

int space_tab(char c){
    return (c==' ' || c=='\t') ? 0 : 1;
}

void buff_size_check(int j){
    if(j>BUFFER){
        printf("Buffer overflow. Please enter fewer characters");
        exit(1);
    }
}

void output(char *res[]){
    int i=0;
    printf("\n");
    while(res[i]!=NULL){
        printf("%s", res[i]);
        i++;
        printf("\n");
    }
}

int lab10_internet(){
    setlocale(LC_ALL,"");
    char *a, c, buf[BUFFER], *res[SIZE];
    int i, j=0, k=0;
    while((c=getchar())!='~')
        if(space_tab(c))
            if(c!='\n'){
                buf[j]=c;
                j++;
                buff_size_check(j);
            }else{
                buf[j]='\0';
                if((a=(char*)malloc((j+1)*sizeof(char)))==NULL){
                    perror("Memory allocation error");
                    exit(1);
                }
                for(i=0;i<=j;i++)
                    a[i]=buf[i];
                res[k]=a;
                k++; j=0;
            }
    res[k+1]=NULL;
    output(res);
}
