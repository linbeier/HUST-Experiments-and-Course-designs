//
//  main.c
//  c experiment 6.9
//
//  Created by 林斌 on 2017/6/2.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#define n 20
#define m 10
int main(void) {
    int i,d[m+n],e[m+n];
    char k,fake,a[m+n],b[m+n];
    int c[m+n];
    char*p=a;
    char*q=b;
    int*g=d,*h=e;
    for (i=0; i<n; i++)
        scanf("%c",p+i);
    k=getchar();
    for (i=0; i<m; i++)
        scanf("%c",p+n+i);
    fake=getchar();
    for (i=0; i<n; i++)
        scanf("%c",q+i);
    k=getchar();
    for (i=0; i<m; i++)
        scanf("%c",q+n+i);
    for (i=0; i<m+n; i++)
    {
        *(g+i)=(*(p+i)-'0');
        *(h+i)=(*(q+i)-'0');
        if ((*(g+i)+*(h+i))>=10)
        {
            *(c+i)=(*(g+i)+*(h+i))%10;
            *(c+i-1)+=1;
        }
        else
            *(c+i)=*(g+i)+*(h+i);
    }
    for (i=0; i<n; i++) printf("%d",*(c+i));
    printf(".");
    for (i=0; i<m; i++) printf("%d",*(c+n+i));
    printf("\n");
    return 0;
}
