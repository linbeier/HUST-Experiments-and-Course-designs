//
//  main.c
//  c experiment 5.6
//
//  Created by 林斌 on 2017/4/27.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int b[1000];

int search(int score,int n,int k);

int main()
{
    int i,j,n,max,temp,score,k;
    char a[1000][100],s[100];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s",a[i]);
        scanf("%d",&b[i]);
    }
    for (i=1;i<n;i++)
    {
        max=i;
        for (j=i+1;j<=n;j++)
            if (b[j]>b[max]) max=j;
        if (i!=max)
        {
            temp=b[i];
            b[i]=b[max];
            b[max]=temp;
            strcpy(s,a[i]);
            strcpy(a[i],a[max]);
            strcpy(a[max],s);
        }
    }
    for (i=1;i<=n;i++)
    {
        printf("%s ",a[i]);
        printf("%d",b[i]);
        printf("\n");
    }
    printf("\n");
    scanf("%d",&score);
    k=search(score,1,n);
    if (k==0) printf("not found!");
    else printf("%s %d",a[k],b[k]);
    return 0;
}

int search(int score,int n,int k)
{
    if (score==b[(n+k)/2]) return (n+k)/2;
    if (n==k&&score!=b[n]) return 0;
    if (score>b[(n+k)/2]) search(score,n,(n+k)/2);
    else search(score,(n+k)/2+1,k);
    return 0;
}
