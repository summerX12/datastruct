#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "llist.h"

#define NAMESIZE 	32

enum
{
	id = 1,
	name,
	math,
	chinese
};

struct stu_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

void print_s(const void *data)
{
	const struct stu_st *r = data;

	printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);
}

int compare(const void *data1,const void *data2,int index)
{
	const struct stu_st *d2 = data2;
	int ret = 1;
	const int *d1 = data1;
	
	switch(index)
	{
		case id:
			if(*d1 == d2->id)
				ret = 0;
			break;
		case name:
			ret = strcmp((char *)d1,(const char *)&d2->name);
			break;
		case math:
			if(*d1 == d2->math)
				ret = 0;
			break;
		case chinese:
			if(*d1 == d2->chinese)
				ret = 0;
			break;
		default:ret = -1;
	}
	return ret;
}

int main()
{
	LLIST *node;
	struct stu_st stu;
	int i;

	node = llist_create(sizeof(struct stu_st));
	if(node == NULL)
		exit(1);

	for(i=0; i< 8; i++)
	{
		stu.id = i;
		snprintf(stu.name,NAMESIZE,"stu%d",i);
		stu.math = rand()%100;
		stu.chinese = rand()%100;

		llist_insert(node,&stu,LLIST_FOREWARD);
	}

	llist_travel(node,print_s);
	printf("\n");

	int data = 86;
	if( llist_delete(node,(void *)&data,chinese,compare) < 0)
		printf("not find, can't delete\n");
	else
	{
		printf("delete success\n");
		llist_travel(node,print_s);
		printf("\n");
	}

	char *n;
	struct llist_node_st *res=NULL;
	strcpy(n,"stu7");
	if(llist_find(node,(void *)n,name,compare,&res) < 0)
		printf("not find\n");
	else
	{
		printf("find ");
		print_s(res->data);
	}
	
	llist_destroy(node);

	exit(0);
}

