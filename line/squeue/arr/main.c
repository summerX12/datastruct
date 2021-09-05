#include <stdlib.h>
#include <stdio.h>

#include "queue.h"

int main()
{
    queue *sq;
    datatype arr[] = {2,45,23,65};
    int i;

    sq = qu_create();
    if(sq == NULL)
        exit(1);

    for(i = 0; i<sizeof(arr)/sizeof(*arr); i++)
        qu_enqueue(sq,&arr[i]);

    qu_travel(sq);

/*
    datatype tmp=100;
    qu_enqueue(sq,&tmp);
    qu_travel(sq);
*/
    datatype tmp;

    qu_dequeue(sq,&tmp);
    printf("DEQUEUE:%d\n",tmp);
    qu_travel(sq);


    qu_destroy(sq);

    exit(0);
}
