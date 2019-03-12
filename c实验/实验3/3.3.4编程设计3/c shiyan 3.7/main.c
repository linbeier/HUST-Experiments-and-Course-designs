//
//  main.c
//  c shiyan 3.7
//
//  Created by 林斌 on 2017/4/13.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
int prime(int n){
    int k;
    for(k=2;k<n;k++)
        if (!(n%k))
            return 0;
    return 1;
}

int main (){
    int x,y;
    printf("请输入一个偶数：");
        scanf("%d",&x);
        for (y=2; y<x; y++)
            if (prime(y)&&prime(x-y))
            {
                printf("%d=%d+%d\n",x,y,x-y);
                break;
            }
    system("PAUSE");
    return 0;
}

