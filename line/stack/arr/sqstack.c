#include <stdlib.h>
#include <stdio.h>

#include "sqstack.h"


sqstack *st_create(void)
{
    sqstack *st;

    st = malloc(sizeof(*st));
    if(st == NULL)
        return NULL;

    st->top = -1;
    return st;
}

int st_isempty(sqstack *st)
{
    return (st->top == -1);
}

int st_push(sqstack *st,datatype *data)
{
    if(st->top == (MAXSIZE-1))
        return -1;
    
    st->data[++st->top] = *data;
    return 0;
}

int st_pop(sqstack *st,datatype *data)
{
    if(st_isempty(st))
        return -1;
    *data = st->data[st->top--];
    return 0;
}
int st_top(sqstack *st,datatype *data)
{
    if(st_isempty(st))
        return -1;
    *data = st->data[st->top];
    return 0;
}

int st_travel(sqstack *st)
{
    int i;

    if(st_isempty(st))
        return -1;

    for(i=0; i<=st->top; i++)
        printf("%d ",st->data[i]);

    return 0;
}

void st_destroy(sqstack *st)
{
    free(st);
}
