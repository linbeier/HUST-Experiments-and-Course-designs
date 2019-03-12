//
//  main.c
//  c experiment 6.10
//
//  Created by 林斌 on 2017/6/4.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include<stdio.h>
#include<string.h>
int main(void)
{
    char *(*p[2])(const char *, const char *);
    char a[80], b[80], c[160], *result = c;
    p[1]=strcpy;
    p[0]=strcat;
    printf("input the first string please!\n");
    gets(a);
    printf("input the second string please!\n");
    gets(b);
    result = p[0](a, b);
    printf("the first result is %s\n", result);
    result = p[1](a, b);
    printf("the second result is %s\n", result);
    return 0;
}
