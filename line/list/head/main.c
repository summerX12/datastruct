#include <stdlib.h>
#include <stdio.h>

#include "list.h"

int main(void)
{
    list *l;
    int i;
    int arr[] = {12,23,9,2,6,34,45};
    int data;

    l = list_create();
    if(l == NULL)
        exit(1);

    for(i = 0;i<sizeof(arr)/sizeof(*arr); i++)
    {
        //if( list_insert_at(l,0,&arr[i]) )
        if( list_order_insert(l,&arr[i]) )
            exit(1);
    }
    
    list_display(l);
    
   list_delete_at(l,1,&data);
   /*
    int val = 12;
    list_delete(l,&val);
   */
   list_display(l);

   list_destroy(l);


    exit(0);
}
