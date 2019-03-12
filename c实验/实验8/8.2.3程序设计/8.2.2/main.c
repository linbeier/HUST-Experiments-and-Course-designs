//
//  main.c
//  8.2.2
//
//  Created by 林斌 on 2017/6/12.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
    char ch;
    FILE *fp;
    if (argc != 2) {
        printf("Arguments error!\n");
        exit(-1);
    }
    if ((fp = fopen(argv[1], "r")) == NULL) {        /* fp 指向 filename */
        printf("Can't open %s file!\n", argv[1]);
        exit(-1);
    }
    
    while ((ch = fgetc(fp)) != EOF)          /* 从filename中读字符 */
        putchar(ch);                  /* 向显示器中写字符 */
    fclose(fp);
    system("PAUSE");/* 关闭filename */
    return 0;
}



