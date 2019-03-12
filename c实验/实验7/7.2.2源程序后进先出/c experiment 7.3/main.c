//
//  main.c
//  c experiment 7.3
//
//  Created by 林斌 on 2017/6/1.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct s_list
{
    int data;
    struct s_list *next;
};
void create_list(struct s_list *(*headp),int *p)
{
    struct s_list *loc_head=NULL,*n;
    if(p[0]==0)
        ;
    else
    {
        loc_head=(struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data=*p++;
        loc_head->next=NULL;
        while(*p)
        {
            n=(struct s_list *)malloc(sizeof(struct s_list));
            n->data=*p++;
            n->next=loc_head;
            loc_head=n;
        }
    }
    *headp=loc_head;
}

int main()
{
    struct s_list *head,*p;
    head=NULL;
    int s[]= {1,2,3,4,5,6,7,8,0};
    create_list(&head,s);
    p=head;
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

