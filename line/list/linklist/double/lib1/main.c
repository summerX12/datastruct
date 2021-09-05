#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "llist.h"

#define NAMESIZE 32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

void print_s(const void *record)
{
    const struct score_st *r = record;

    printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);
}

static int id_cmp(const void *key,const void *record)
{
        const int *k = key;
        const struct score_st *r = record;

        return (*k - r->id);
}

static int name_cmp(const void *key,const void *record)
{
    const char *k = key;
    const struct score_st *r = record;

    return strcmp(k,r->name);
}

int main()
{
    LLIST *handler;
    struct score_st tmp;
    int ret,i;

    handler = llist_create(sizeof(struct score_st));
    if(handler == NULL)
        exit(1);

    for(i = 0;i<7; i++)
    {
        tmp.id = i;
        snprintf(tmp.name,NAMESIZE,"std%d",i);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;

        ret = llist_insert(handler,&tmp,LLIST_BACKWARD);
        if(ret < 0)
            exit(1);
    }
    
    llist_travel(handler,print_s);
    printf("\n");
 
    int id = 3;
    char *del_name = "std6";

    ret = llist_delete(handler,del_name,name_cmp);
    if(ret)
        printf("llist_delete failed\n");

    llist_travel(handler,print_s);

/*    struct score_st *data;
   
    data = llist_find(handler,&id,id_cmp);
    if(data == NULL)
        printf("can't find");
    else
        print_s(data);
*/
    llist_destroy(handler);
}
