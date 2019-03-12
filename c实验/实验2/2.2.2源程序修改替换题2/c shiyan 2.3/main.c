//
//  main.c
//  c shiyan 2.3
//
//  Created by 林斌 on 2017/4/6.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>

int main()
{
    int i=1,n;
    long s=1;
    printf("Please enter n:");
    scanf("%d",&n);
     do {
        s*=i;
        i++;
     }while (i<=n);
    printf("%d!=%d",n,s);
    putchar('\n');
    system("PAUSE");
    return 0;
}
