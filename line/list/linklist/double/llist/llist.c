#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "llist.h"


LLIST *llist_create(int initsize)
{
	LLIST *me;

	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me->size = initsize;
	me->head.prev = &me->head;
	me->head.next = &me->head;
	me->head.data = NULL;

	return me;
}

int llist_insert(LLIST *ptr,const void *data,int mode)
{
	struct llist_node_st *new;
	
	new = malloc(sizeof(*new));
	if(new == NULL)
		return -1;

	new->data = malloc(ptr->size);
	if(new->data == NULL)
		return -2;
	
	memcpy(new->data,data,ptr->size);

//	new->data = data;
	if(mode == LLIST_FOREWARD)
	{
		new->prev = &ptr->head;
		new->next = ptr->head.next;
	}
	else if (mode == LLIST_BACKWARD)
	{
		new->prev = ptr->head.prev;
		new->next = &ptr->head;
	}
	else
		return -3;
	new->prev->next = new;
	new->next->prev = new;

	return 0;
}

int llist_find(LLIST *ptr,void *data,int index,llist_cmp *cmp,llist_op *op)
{
	struct llist_node_st *cur;

	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
	{
		if(cmp(data,cur->data,index) == 0)
		{
			printf("find ");
			op(cur->data);
			return 0;
		}
	}
/*	{
		if(memcpy(cur->data,data,ptr->size) == 0)
		{
			return 0;
		}
	}
*/
	printf("not find\n");
	return -1;
}

int llist_delete(LLIST *ptr,void *data,int index,llist_cmp *cmp)
{
	struct llist_node_st *cur;

	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
	{
		if(cmp(data,cur->data,index) == 0)
		{
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			free(cur->data);
			free(cur);
			return 0;
		}
	}

	printf("not find, can't delete\n");
	return -1;
}

void llist_travel(LLIST *ptr,llist_op *op)
{
	struct llist_node_st *cur;

	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next)
		op(cur->data);
}

void llist_destroy(LLIST *ptr)
{
	struct llist_node_st *cur = &ptr->head,*node;

	for(cur = ptr->head.next; cur != &ptr->head; cur =cur->next)
	{
	//	node = cur->next;
		free(cur->data);
		free(cur);
	}
	free(ptr);
}
