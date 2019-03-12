//
//  main.c
//  c shiyan 2.9
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    long m,n;
    printf("请输入一个正整数:");
    scanf ("%ld",&n);
    printf("逆转后的整数为：");
    while (n>=10) {
        m=n%10;
        printf("%ld",m);
        n/=10;
    }
    printf("%ld\n",n);
    system("PAUSE");
    return 0;
}
