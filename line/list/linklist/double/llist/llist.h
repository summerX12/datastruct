#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FOREWARD	1
#define LLIST_BACKWARD	2

typedef void llist_op(const void *);
typedef int llist_cmp(const void *,const void *,int index);

struct llist_node_st
{
	void *data;
	struct llist_node_st *prev;
	struct llist_node_st *next;
};

typedef struct 
{
 	int size;
	struct llist_node_st head;
}LLIST;

LLIST *llist_create(int initsize);

int llist_insert(LLIST *,const void *data,int mode);

int llist_find(LLIST *,void *data,int index,llist_cmp *,llist_op *);

int llist_delete(LLIST *,void *data,int index,llist_cmp *);

void llist_travel(LLIST *,llist_op *);

void llist_destroy(LLIST *);

#endif
