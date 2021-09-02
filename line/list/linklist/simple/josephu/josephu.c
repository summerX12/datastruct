#include <stdlib.h>
#include <stdio.h>

#define JOSE_NR 8


struct node_st
{
    int data;
    struct node_st *next;
};

struct node_st *jose_create(int n)
{
    struct node_st *me,*new,*cur;
    int i=1;

    me = malloc(sizeof(*me));
    if(me == NULL)
        return NULL;
    me->data = i;
    me->next = me;
    i++;

    cur = me;
    for(;i<=n; i++)
    {
        new = malloc(sizeof(*new));
        if(new == NULL)
            return NULL;
        new->data = i;
        new->next = me;
        
        cur->next = new;
        cur = new;
    }
    return me;
}

void jose_kill(struct node_st **me ,int n)
{
    struct node_st *cur = *me,*node;
    int i=1;

    while(cur != cur->next)
    {
        while(i<n)
        {
            node = cur;
            cur = cur->next;
            i++;
        }
        printf("%d ",cur->data);
        node->next = cur->next;
        free(cur);

        cur = node->next;
        i = 1;
    }

    *me = cur;
    printf("\n");
}

void jose_show(struct node_st *me)
{
    struct node_st *list;

    for(list = me; list->next != me; list = list->next)
    {
        printf("%d ",list->data);
    }
    printf("%d\n",list->data);
}

int main()
{
    struct node_st *list;

    list = jose_create(JOSE_NR);
    if(list == NULL)
        exit(1);

    jose_show(list);

    jose_kill(&list,3);
    jose_show(list);

    exit(0);
}
