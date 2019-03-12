//
//  main.c
//  c shiyan2.1
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i,n;//s为n！的值，int类型过于小，应改为long
    long s=1;
    printf("Please enter n:");
    scanf("%d",&n);//scanf语句错误，缺少地址符&
    for(i=1;i<=n;i++)//for 语句错误，中间应用；隔开
        s=s*i;
    printf("%d!=%d",n,s);
    putchar('\n');
    system("PAUSE");
    return 0;
}
//return 0 (return 函数应该在大括号内）
