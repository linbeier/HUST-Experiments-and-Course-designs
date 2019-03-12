//
//  main.c
//  c experiment 5.4
//
//  Created by 林斌 on 2017/4/27.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    int a[3][4],b[4][3];
    int i,j;
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for (i=0;i<=2;i++)
    {
        for (j=0;j<=3;j++)
        {
            printf(" %d",a[i][j]);
            if (j==3)printf("\n");
        }
    }
    for (i=0;i<=2;i++ )
    {
        for (j=0;j<=3;j++)
        {
            b[j][i]=a[i][j];
        }
    }
    for (i=0; i<=3;i++ )
    {
        for (j=0; j<=2; j++)
        {
            printf(" %d",b[i][j]);
            if (j==2)printf("\n");
        }
    }

    return 0;
}
