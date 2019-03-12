//
//  main.c
//  c experimrnt 5.7
//
//  Created by 林斌 on 2017/6/3.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include<stdio.h>
#include"stdlib.h"
#include<string.h>
int strnins(char *s, char *t, int n)
{
    int i, l = strlen(s);
    char a[100];
    if (n<0 || n>l)	return 0;
    
    for (i = 0; s[i + n] != '\0'; i++)
    {
        a[i] = s[n + i];
    }
    a[i] = '\0';
    for (i = 0; t[i] != '\0'; i++)
    {
        s[n + i] = t[i];
    }
    n += i;
    for (i = 0; a[i] != '\0'; i++)
    {
        s[n + i] = a[i];
    }
    s[n + i] = '\0';
    return 1;
}
int main()
{
    char t[50], s[50];
    int n, i, m;
    scanf("%d", &m);
    getchar();
    for (i = 0; i < m; i++)
    {
        gets(s);
        gets(t);
        scanf("%d", &n);
        getchar();
        strnins(s, t, n);
        printf("%s\n", s);
    }
    return 0;
}



