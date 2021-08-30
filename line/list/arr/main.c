#include <stdlib.h>
#include <stdio.h>

#include "sqlist.h"


int main()
{
    sqlist *list=NULL,*list1=NULL;
    datatype arr[] = {12,23,34,45,56};
    datatype arr1[] = {89,90,78,67,56,43};
    int err,i;

    list = sqlist_create();
   // sqlist_create1(&list);
    if(list == NULL)
    {
        fprintf(stderr,"sqlist_create() failed\n)");
        exit(1);
    }
    
    list1 = sqlist_create();
    if(list1 == NULL)
    {
        fprintf(stderr,"sqlist_create() failed\n)");
        exit(1);
    }

    for(i = 0;i<sizeof(arr)/sizeof(*arr);i++)
    {
        if((err = sqlist_insert(list,0,&arr[i])) != 0)
        {
            if(err = -1)
                fprintf(stderr,"the arr is full\n");
            else if(err = -2)
                fprintf(stderr,"the pos you insert is wrong\n");
            else
                fprintf(stderr,"wrong\n");
        }
    }
    
    for(i = 0;i<sizeof(arr1)/sizeof(*arr1);i++)
    {
        if((err = sqlist_insert(list1,0,&arr1[i])) != 0)
        {
            if(err = -1)
                fprintf(stderr,"the arr is full\n");
            else if(err = -2)
                fprintf(stderr,"the pos you insert is wrong\n");
            else
                fprintf(stderr,"wrong\n");
        }
    }
    sqlist_display(list);
    sqlist_display(list1);
 
    sqlist_union(list,list1);
//    sqlist_delete(list,1);
    sqlist_display(list);

    sqlist_destroy(list);
    sqlist_destroy(list1);

    exit(0);
}
