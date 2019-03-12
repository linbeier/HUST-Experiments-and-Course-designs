//
//  main.c
//  c experiment 6.3
//
//  Created by 林斌 on 2017/5/11.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include "stdio.h"
#include "string.h"

void main(void)
{
    char *(*p)(char *a,char *b) = NULL;
    char a[800],b[800],c[160],*result=c;
    int choice,i;
    do{
        printf("\t\t1 copy string.\n");
        printf("\t\t2 connect string.\n");
        printf("\t\t3 exit.\n");
        printf("\t\tinput a number (1-3) please!\n");
        scanf("%d",&choice);
    }while(choice<1 || choice>3);
    switch(choice){
        case 1:
            p=strcpy;
            break;
        case 2:
            p=strcat;
            break;
        case 3:
            goto down;
    }
    getchar();
    printf("input the first string please!\n");
    i=0;
    gets(a);
    printf("input the second string please!\n");
    i=0;
    gets(b);
    result= p(a,b);
    printf("the result is %s\n",result);
down: ;
    system("PAUSE");
}
