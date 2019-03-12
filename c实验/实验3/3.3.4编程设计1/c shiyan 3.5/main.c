//
//  main.c
//  c shiyan 3.5
//
//  Created by 林斌 on 2017/4/13.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
int last (int m,int n){
    int z,r;
    if (m>=n&&m%n==0) z=n;
    else if (m<=n&&m%n==0) z=m;
    else
    {
    r=m%n;
    m=n;
    n=r;
    z=last(m,n);
    }
    return z;
}

int main (void){
    int m,n;
    printf("please input two integers:\n");
    scanf("%d%d",&m,&n);
    printf("两整数的最大公约数为：%d\n",last(m,n));
    system("PAUSE");
}
