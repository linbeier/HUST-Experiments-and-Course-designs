//
//  main.c
//  c experiment 6.4
//
//  Created by 林斌 on 2017/5/11.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
char *strcp(char *s,char *t);
int main(void)
{
    char a[20],b[60]="there is a boat on the lake.";
    printf("%s\n",strcp(a,b));
    system("PAUSE");
    return 0;
}
char *strcp(char *s,char *t)
{
    char *p=s;
    while((*s++=*t++));
    return (p);
}
