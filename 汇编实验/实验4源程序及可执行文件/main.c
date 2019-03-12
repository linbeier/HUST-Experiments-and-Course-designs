//
//  main.cpp
//  c调用
//
//  Created by 林斌 on 2017/12/12.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#define N 5
int PARA1;
struct student {
    char rank;
    char name[10];
    char chinese;
    char english;
    char math;
    char average;
};
struct student stu[N]={' '};
extern void ZBB();
extern void SOR();
void input(){
    int a,i;
    for (a=1; a<=5; a++) {
        printf("please input no.%d students information\n",i);
        i--;
        scanf("%s",stu[i].name);
        scanf("%d",(int*)&stu[i].chinese);
        scanf("%d",(int*)&stu[i].english);
        scanf("%d",(int*)&stu[i].math);
        
    }
}
void output(){
    int i,j=0;
    int a=5;
    for (a=5; a>=1; a--) {
     while (i<=4) {
        if(stu[j].rank==i+1){
            printf("%-5s",stu[j].name);
            printf("%-5d",stu[j].chinese);
            printf("%-5d",stu[j].english);
            printf("%-5d",stu[j].math);
            printf("%-5d\n",stu[j].average);
            j=0;
            i++;
        }
        else j++;
       }
    }
}
int main(void) {
    char c;
    printf("\n");
    printf("1=input\n");
    printf("2=calculate the ave\n");
    printf("3=rank\n");
    printf("4=output\n");
    printf("5=quit\n");
    printf("\n");
    c=getchar();
    getchar();
    while(c!='5'){
        switch(c){
            case('1'):{input();PARA1=&stu[0];};break;
            case('2'):AVERAGE();break;
            case('3'):RANKS();break;
            case('4'):output();break;
            default:break;
    }
    printf("\n");
    printf("1=input\n");
    printf("2=calculate the ave\n");
    printf("3=rank\n");
    printf("4=output\n");
    printf("5=quit\n");
    printf("\n");
    getchar();
    c=getchar();
    getchar();
}
    return 0;
}
