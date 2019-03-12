#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159/*#define 指令行的末尾没有分号*/

int main(void)/*建议改为int main*/
{
    int f;
    short p,k,newint;/*声明newint*/
    double c,r,s;
    /*for task1*/
    printf("Input Fahrenheit:");
    scanf("%d",&f);/*添加地址符号*/
    c=5.0/9*(f-32);/*将整数运算转化为小数运算*/
    printf("\n%d(F)=%.2f(C)\n\n",f,c);
    /*for task2*/
    printf("inout the radius r:");
    scanf("%lf",&r);/*r为双精度变量*/
    s=PI*r*r;
    printf("\nThe acreage is %.2f\n\n",s);/*去掉地址符*/
    /*for task3*/
    printf("input hex int k,p:");
    scanf("%hx%hx",&k,&p);/*取为16进制运算*/
    newint=(p&0xff00)|((k&0xff00)>>8);/*更改式子*/
    printf("newint=%x\n\n",newint);
    system("PAUSE");
    return 0;//添加返回值
    
}
