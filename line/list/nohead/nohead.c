#include <stdlib.h>
#include <stdio.h>
#include "nohead.h"


int list_insert(struct node_st **list, struct score_st *data)
{
    struct node_st *new;

    new = malloc(sizeof(*new));
    if(new == NULL)
        return -1;


    new->data = *data;
    new->next = *list;
    *list = new;
    
    return 0;
}

void list_show(struct node_st *list)
{
    struct node_st *cur;

    for(cur = list; cur != NULL; cur = cur->next)
    {
        printf("%d %s %d %d \n",cur->data.id,cur->data.name,cur->data.math,cur->data.chinese);
    }
}


int list_delete(struct node_st **list)
{
    struct node_st *cur;

    if(*list == NULL)
        return -1;

    cur = *list;
    *list = (*list)->next;

    free(cur);
    return 0;
}
int list_find(struct node_st *list,int id)
{
    struct node_st *cur;

    for(cur = list; cur != NULL; cur = cur->next)
    {
        if(cur->data.id == id)
        {
            printf("%d %s %d %d \n",cur->data.id,cur->data.name,cur->data.math,cur->data.chinese);
            return 0;
        }
    }
    return -1;
}
