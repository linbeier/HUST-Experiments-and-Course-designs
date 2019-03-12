//
//  main.c
//  c experiment 6.8
//
//  Created by 林斌 on 2017/5/24.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include"stdlib.h"
#define N 2
#define M 3
int * average_students (int *pa,int *sa)
{
    int k,s;
    for (k=0; k<N; k++)
    {
        for(s=0;s<M;s++)
            *(sa+k)+=*(pa+s*N+k);
        *(sa+k)=*(sa+k)/M;
    }
    return sa;
}
int * average_courses (int *pa,int *sa)
{
    int k,s;
    for (k=0; k<M; k++)
    {
        for(s=0;s<N;s++)
            *(sa+k)+=*(pa+k*N+s);
        *(sa+k)=*(sa+k)/N;
    }
    return sa;
}
int number_notpass (int*pa)
{
    int c[M]={0,0,0},k,s,n=0;
    for (k=0; k<M; k++)
{
    for(s=0;s<N;s++)
        c[k]+=*(pa+k*N+s);
    c[k]=c[k]/10;
}
    for(k=0;k<M;k++)
    {
        for(s=0;s<N;s++)
        {
    while (c[k]>*(pa+k*N+s)) n++;
        }
    }
    return n;
}
int * number_notpass_course(int *pa,int *sa){
    int k,s;
    for(k=0;k<M;k++)
    {
        for(s=0;s<N;s++)
        {
            if (60>*(pa+k*N+s)) (*sa)++;
            if (89<*(pa+k*N+s)) (*(sa+1))++;
        }
    }
    return sa;
}
int main(void){
    int a[M][N]={0,0,0,0,0,0},i,j,*pa,*sa,*la,*fa,c[M]={0,0,0},d[N]={0,0},f[2]={0,0};
    char x;
    pa=&a[0][0];
    sa=&c[0];
    la=&d[0];
    fa=&f[0];
    for (i=0; i<M; i++)
    {
        for(j=0;j<N;j++)
        scanf("%d",&a[i][j]);
    }
    printf("please input the operation you want\n");
    scanf("%c",&x);
    scanf("%c",&x);
    switch (x){
        case 'a':{average_students(pa,la);for(i=0;i<N;i++)printf("%d\n",*(la+i));}break;
        case 'b':{average_courses(pa,sa);for(i=0;i<M;i++)printf("%d\n",*(sa+i));}break;
        case 'c':printf("%d\n",number_notpass(pa));break;
        case 'd':{number_notpass_course(pa,fa);for(i=0;i<2;i++)printf("%d\n",*(fa+i));}break;
    }
    system("PAUSE");
    return 0;
}


