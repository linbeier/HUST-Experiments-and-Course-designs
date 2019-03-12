//
//  main.c
//  c experimrnt 7.4
//
//  Created by 林斌 on 2017/6/1.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include<stdio.h>
#include"stdlib.h"
struct BITS
{
    unsigned short bit0 : 1;
    unsigned short bit1 : 1;
    unsigned short bit2 : 1;
    unsigned short bit3 : 1;
    unsigned short bit4 : 1;
    unsigned short bit5 : 1;
    unsigned short bit6 : 1;
    unsigned short bit7 : 1;
    unsigned short resv : 8;
};
union REG
{
    unsigned short  all;
    struct BITS bit;
};
void isr0(void)
{
    printf("The Interrupt Service Routine isr0 is called!\n");
}
void isr1(void)
{
    printf("The Interrupt Service Routine isr1 is called!\n");
}
void isr2(void)
{
    printf("The Interrupt Service Routine isr2 is called!\n");
}
void isr3(void)
{
    printf("The Interrupt Service Routine isr3 is called!\n");
}
void isr4(void)
{
    printf("The Interrupt Service Routine isr4 is called!\n");
}
void isr5(void)
{
    printf("The Interrupt Service Routine isr5 is called!\n");
}
void isr6(void)
{
    printf("The Interrupt Service Routine isr6 is called!\n");
}
void isr7(void)
{
    printf("The Interrupt Service Routine isr7 is called!\n");
}
int main()
{
    union REG uIsrReg;
    unsigned short number[51];
    void(*p_isr[8])(void);
    p_isr[0] = isr0;
    p_isr[1] = isr1;
    p_isr[2] = isr2;
    p_isr[3] = isr3;
    p_isr[4] = isr4;
    p_isr[5] = isr5;
    p_isr[6] = isr6;
    p_isr[7] = isr7;
    int n, t;
    scanf("%d", &n);
    for (t = 0; t < n; t++)
        scanf("%hu", &number[t]);
    for ( t = 0; t < n; t++)
    {
        uIsrReg.all = number[t];
        printf("%hu:\n", uIsrReg.all);
        if (uIsrReg.bit.bit0==1)
            p_isr[0]();
        if (uIsrReg.bit.bit1 == 1)
            p_isr[1]();
        if (uIsrReg.bit.bit2 == 1)
            p_isr[2]();
        if (uIsrReg.bit.bit3 == 1)
            p_isr[3]();
        if (uIsrReg.bit.bit4 == 1)
            p_isr[4]();
        if (uIsrReg.bit.bit5 == 1)
            p_isr[5]();
        if (uIsrReg.bit.bit6 == 1)
            p_isr[6]();
        if (uIsrReg.bit.bit7 == 1)
            p_isr[7]();
        printf("\n");
    }
    system("PAUSE");
    return 0;
}

