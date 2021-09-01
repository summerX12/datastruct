#include <stdlib.h>
#include <stdio.h>

#include "sqstack.h"


int main()
{
    sqstack *st;
    datatype arr[] = {13,45,66,67,1};
    int i,ret;
    
    st = st_create();
    if(st == NULL)
        exit(1);
    
    for(i = 0; i<sizeof(arr)/sizeof(*arr); i++)
        st_push(st,&arr[i]);

    st_travel(st);
    printf("\n");

/*
    datatype tmp = 1;
    ret = st_push(st,&tmp);
    if(ret != 0)
        printf("push err\n");
    else
        st_travel(st);
*/

/*
    int data;
    st_top(st,&data);
    printf("%d",data);

    st_pop(st,&data);
    st_travel(st);
*/

    st_destroy(st);

    exit(0);
}
