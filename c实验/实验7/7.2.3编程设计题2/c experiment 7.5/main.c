//
//  main.c
//  c experiment 7.5
//
//  Created by 林斌 on 2017/6/1.
//  Copyright © 2017年 林斌. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct s_list
{
    char ID[15];
    char Name[20];
    float English;
    float Math;
    float Physics;
    float C;
    float SUM;
    float AVG;
    struct s_list *next;
};
void swap(struct s_list *p1, struct s_list *p2)
{
    struct s_list *tmp1 = p1->next, *tmp2 = p2->next;
    struct s_list tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
    p1->next = tmp1;
    p2->next = tmp2;
}
void SelctSort(struct s_list *loc_head)
{
    struct s_list * p1, *p2, *index;
    for (p1 = loc_head; p1->next != NULL; p1 = p1->next)
    {
        index = p1;
        for (p2 = p1->next; p2 != NULL; p2 = p2->next)
            if (p2->AVG < index->AVG)
                index = p2;
        if (index != p1)
            swap(index, p1);
    }
}
int main()
{
    struct s_list *loc_head=NULL,*tail;
    struct s_list *current;
    struct s_list *p;
    int i,n;
    float rescore;
    char reid[15],sub[15];
    scanf("%d",&n);
    loc_head=(struct s_list *)malloc(sizeof(struct s_list));
    scanf("%s %s %f %f %f %f",loc_head->ID,loc_head->Name,&loc_head->English,&loc_head->Math,&loc_head->Physics,&loc_head->C);
    tail=loc_head;
    for(i=1; i<n; i++)
    {
        tail->next=(struct s_list *)malloc(sizeof(struct s_list));
        tail=tail->next;
        scanf("%s %s %f %f %f %f",tail->ID,tail->Name,&tail->English,&tail->Math,&tail->Physics,&tail->C);
    }
    tail->next=NULL;
    printf("%-15s%-20s%-10s%-10s%-10s%-10s\n","ID","Name","English","Math","Physics","C");
    for(current=loc_head; current!=NULL; current=current->next)
    {
        printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n",current->ID,current->Name,current->English,current->Math,current->Physics,current->C);
    }
    printf("\n");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s %s %f",reid,sub,&rescore);
        p=loc_head;
        for(;;)
        {
            if(strcmp(p->ID,reid)==0)
            {
                if(strcmp(sub,"English")==0)
                    p->English=rescore;
                else if(strcmp(sub,"Math")==0)
                    p->Math=rescore;
                else if(strcmp(sub,"Physics")==0)
                    p->Physics=rescore;
                else if(strcmp(sub,"C")==0)
                    p->C=rescore;
                break;
            }
            else
                p=p->next;
        }
    }
    printf("Alter:\n");
    printf("%-15s%-20s%-10s%-10s%-10s%-10s\n","ID","Name","English","Math","Physics","C");
    for(current=loc_head; current!=NULL; current=current->next)
    {
        printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n",current->ID,current->Name,current->English,current->Math,current->Physics,current->C);
    }
    printf("\n");
    printf("SumAndAvg:\n");
    printf("%-15s%-20s%-10s%-10s\n","ID","Name","SUM","AVG");
    for(current=loc_head; current!=NULL; current=current->next)
    {
        current->SUM=+current->English+current->Math+current->Physics+current->C;
        current->AVG=current->SUM/4;
        printf("%-15s%-20s%-10.2f%-10.2f\n",current->ID,current->Name,current->SUM,current->AVG);
    }
    printf("\n");
    SelctSort(loc_head);
    printf("Sort:\n");
    printf("%-15s%-20s%-10s\n","ID","Name","AVG");
    for(current=loc_head; current!=NULL; current=current->next)
    {
        printf("%-15s%-20s%-10.2f\n",current->ID,current->Name,current->AVG);
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

