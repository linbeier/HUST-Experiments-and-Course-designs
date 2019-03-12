//
//  main.c
//  8.2
//
//  Created by 林斌 on 2017/6/12.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    char c = 0;
    int flag = 0;
    int count = 0;
    FILE* file_name = fopen("D:\\abc2.txt", "w");
    //fputc(c, stdout);
    while ((c = getchar()) != EOF)
    {
        count++;
        if (c == '\n') count = 0;
        if (count == 1)
        {
            if ('a' <= c&&c <= 'z')
            {
                fputc(c + 'A' - 'a', file_name);
                flag = 0;
                continue;
            }
            else
            {
                fputc(c, file_name);
                continue;
            }
        }
        if (c == ' ') flag = 1;
        if ('a' <= c&&c <= 'z')
        {
            if (flag == 1)
            {
                fputc(c + 'A' - 'a', file_name);
                flag = 0;
            }
            else fputc(c, file_name);
        }
        else fputc(c, file_name);
    }
    system("PAUSE");
    return 0;
}
