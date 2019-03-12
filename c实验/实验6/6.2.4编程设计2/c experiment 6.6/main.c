//
//  main.c
//  c experiment 6.6
//
//  Created by 林斌 on 2017/5/24.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
#define N 80
void change (char *p[],int n);
int main(void)
    {
        int i,n;
        printf( "input the number(s) of the line(s):\n" );
        scanf("%d",&n);
        n=n+1;
        char a[n][N],*p[n];
        for(i=0;i<n;i++){
            gets(a[i]);
            p[i]=a[i];
        }
        change(p,n);
        system("PAUSE");
        return 0;
    }
void change(char *p[],int n)
    {
        int i,j,k=0;
        for(i=0;i<n;i++)
        {
            for(k=0,j=0;p[i][j]!='\0';j++)
            {
            if (p[i][j]==' ')
            {
                if (p[i][j+1]!=' ')p[i][k++]=' ';
            }
            else p[i][k++]=p[i][j];
            }
            p[i][k]=0;
            printf("%s\n",p[i]);
        }
    }

