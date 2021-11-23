#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LENBUF 1024
#define NUMSTR 64

int issep(char c)
{
    return (c==' ' || c=='\t') ? 0 : 1;
}

void isfull(int j)
{
    if(j>LENBUF)
    {
        printf("Buffer overflow. Please enter fewer characters");
        exit(1);
    }
}

void out(char *res[])
{
    int i=0;
    putchar('\n');
    while(res[i]!=NULL)
    {
        printf("%s", res[i]);
        i++;
        putchar('\n');
    }
}

int lab10_internet()
{
    setlocale(LC_ALL,"");
    char *m, c, buf[LENBUF], *res[NUMSTR];
    int i, j=0, k=0;
    while((c=getchar())!='~')
        if(issep(c))
            if(c!='\n')
            {
                buf[j]=c;
                j++;
                isfull(j);
            }
            else
            {
                buf[j]='\0';
                if((m=(char*)malloc((j+1)*sizeof(char)))==NULL)
                {
                    perror("Memory allocation error");
                    exit(1);
                }
                for(i=0;i<=j;i++)
                    m[i]=buf[i];
                res[k]=m;
                k++; j=0;
            }
    res[k+1]=NULL;
    out(res);
}
