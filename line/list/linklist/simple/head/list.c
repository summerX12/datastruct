#include <stdlib.h>
#include <stdio.h>

#include "list.h"


list *list_create()
{
    list *me;

    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->next = NULL;
    return me;
}
int list_insert_at(list *me,int i,datatype *data)
{
    int j=0;
    list *node=me,*newnode;

    while(i < 0)
        return -1;

    while(j < i && node != NULL)
    {
        node = node->next;
        j++;
    }
    
    if(node)
    {
        newnode = malloc(sizeof(*newnode));
        if(newnode == NULL)
            return -2;
        newnode->data = *data;

        newnode->next = node->next;
        node->next = newnode;
        return 0;
    }
    else
        return -3;//i invalid
}

int list_order_insert(list *me,datatype *data)
{
    list *p = me,*q;

    while(p->next && p->next->data < *data)
        p = p->next;

    q = malloc(sizeof(*q));
    if(q == NULL)
        return -1;

    q->data = *data;
    q->next = p->next;
    p->next = q;

    return 0;
}

int list_delete_at(list *me,int i,datatype *data)
{
    int j=0;
    list *p=me,*q;

    while(i < 0)
        return -1;

    for(j=0; j < i;j++)
    {
        if(p->next != NULL)
            p = p->next;
        else
            return -2;
    }
   
    q = p->next;
    *data = q->data;
    p->next = q->next;
    free(q);
    q = NULL;

    return 0;
}

int list_delete(list *me,datatype *data)
{
    list *p=me,*q;

    while(p->next && p->next->data != *data)
           p = p->next;

    if(p->next == NULL)
        return -1;
    else
    {
        q = p->next;
        p->next = q->next;
        free(q);
        q = NULL;
    }
}

int list_isempty(list *me)
{
    if(me->next == NULL)
        return 0;
    return 1;
}

void list_display(list *me)
{
    list *node = me->next;

    if(list_isempty(me) == 0)
        return ;

    while(node != NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");

    return ;
}

void list_destroy(list *me)
{
    list *node,*next;

    for(node = me->next;node !=NULL; node = next)
    {
        next = node->next;
        free(node);
    }
    free(me);
    return ;
}
