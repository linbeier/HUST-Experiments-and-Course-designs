//
//  main.c
//  c shiyan 3.6
//
//  Created by 林斌 on 2017/4/13.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
int prime(int n)
{
    int k;
    for(k=2;k<n;k++)
    if (!(n%k))return 0;
    return 1;
}

int main ()
{
    int y,n,m,i;
    printf("input your numbers range:");
    scanf("%d%d",&n,&m);
    for (i=n; i>=n&&i<=m; i++)
    {
        for (y=2; y<i; y++)
        {
            if (prime(y)&&prime(i-y))
            {
                printf("%d=%d+%d\n",i,y,i-y);
                break;
            }
        }
    }
    system("PAUSE");
    return 0;
}

