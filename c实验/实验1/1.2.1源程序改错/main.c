#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159/*#define ָ���е�ĩβû�зֺ�*/

int main(void)/*�����Ϊint main*/
{
    int f;
    short p,k,newint;/*����newint*/
    double c,r,s;
    /*for task1*/
    printf("Input Fahrenheit:");
    scanf("%d",&f);/*��ӵ�ַ����*/
    c=5.0/9*(f-32);/*����������ת��ΪС������*/
    printf("\n%d(F)=%.2f(C)\n\n",f,c);
    /*for task2*/
    printf("inout the radius r:");
    scanf("%lf",&r);/*rΪ˫���ȱ���*/
    s=PI*r*r;
    printf("\nThe acreage is %.2f\n\n",s);/*ȥ����ַ��*/
    /*for task3*/
    printf("input hex int k,p:");
    scanf("%hx%hx",&k,&p);/*ȡΪ16��������*/
    newint=(p&0xff00)|((k&0xff00)>>8);/*����ʽ��*/
    printf("newint=%x\n\n",newint);
    system("PAUSE");
    return 0;//��ӷ���ֵ
    
}
