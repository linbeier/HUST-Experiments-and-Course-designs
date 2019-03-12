//
//  main.c
//  c experiment 5.3
//
//  Created by 林斌 on 2017/4/27.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include<stdio.h>
#include"stdlib.h"
void strnca(char [],char [],int);
int main(void)
{
    char a[50]="The adopted symbol is ",b[27]="abcdefghijklmnopqrstuvwxyz";
    strnca(a, b, 4);
    printf("%s\n",a);
    system("PAUSE");
    return 0;
}
void strnca(char s[],char t[], int n)
{
    int i = 0, j;
    while(s[i])i++;//
    for(j = 0; j < n && t[j];)
        s[i++] = t[j++];
    s[i] = '\0';
}
