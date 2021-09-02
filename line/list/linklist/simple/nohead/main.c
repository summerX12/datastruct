#include <stdlib.h>
#include <stdio.h>

#include "nohead.h"


int main()
{
    struct node_st *list=NULL;
    struct score_st tmp;
    int i,ret;
    
    for(i=0; i<7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"stu%d",i);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;

        ret = list_insert(&list,&tmp);
        if(ret != 0)
            exit(0);
    }
    list_show(list);
    printf("\n\n");

    int id = 3;
    list_find(list,id);

 /*
     list_delete(&list);
    list_show(list);
 */   
    exit(0);
}



