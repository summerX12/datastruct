#include <stdio.h>
#include <stdlib.h>
#include <queue.h>

#define NAMESIZE    32

struct score_st
{
    int id;
    char name[NAMESIZE];
    int math;
    int chinese;
};

void print_s(struct score_st *d)
{
    printf("%d %s %d %d\n",d->id,d->name,d->math,d->chinese);
}

struct node_st
{
    struct score_st data;
    struct node_st *l,*r; 
};

static struct node_st *tree = NULL;

int insert(struct node_st **root,struct score_st *data)
{
    struct node_st *node;

    if(*root == NULL)
    {
        node = malloc(sizeof(*node));
        if(node == NULL)
            return -1;

        node->data = *data;
        node->l = NULL;
        node->r = NULL;

        *root = node;
        return 0;
    }

    if(data->id <= (*root)->data.id)
        return insert(&(*root)->l,data);
    return insert(&(*root)->r,data);
}



struct score_st *find(struct node_st *root,int id)
{
    if(root == NULL)
        return NULL;
    if(id == root->data.id)
        return &root->data;
    
    if(id < root->data.id)
        return find(root->l,id);
    else
        return find(root->r,id);
}


void draw_(struct node_st *root,int level)
{
    int i;

    if(root == NULL)
        return ;
    draw_(root->r,level+1);
    for(i = 0; i<level; i++)
        printf("    ");
    print_s(&root->data);
    draw_(root->l,level+1);

}

void draw(struct node_st *root)
{
    draw_(root,0);
/*  draw every step
    printf("\n\n");
    getchar();
*/
}




static int get_num(struct node_st *root)
{
    if(root == NULL)
        return 0;
    return get_num(root->l)+ 1 + get_num(root->r);
}

static struct node_st *find_min(struct node_st *root)
{
    if(root->l == NULL)
        return root;
    return find_min(root->l);
}
static void turn_left(struct node_st **root)
{
    struct node_st *cur = *root;

    *root = cur->r;
    cur->r = NULL;

    find_min(*root)->l = cur;
//    draw(tree);//draw every step
}

static struct node_st *find_max(struct node_st *root)
{
    if(root->r == NULL)
        return root;
    return find_max(root->r);
}
static void turn_right(struct node_st **root)
{
    struct node_st *cur = *root;

    *root = cur->l;
    cur->l = NULL;

    find_max(*root)->r = cur;
//    draw(tree);//draw every step
}

void balance(struct node_st **root)
{
    int sub;

    if(*root == NULL )
        return ;
    while(1)
    {
        sub = get_num((*root)->l) - get_num((*root)->r);
        if(sub>= -1 && sub <= 1)
            break;
        if(sub < -1)
            turn_left(root);
        else
            turn_right(root);
    }

    balance(&(*root)->l);
    balance(&(*root)->r);
}





void delete(struct node_st **root,int id)
{
    struct node_st **node = root;
    struct node_st *cur = NULL;

    while(*node != NULL && (*node)->data.id != id)
    {
        if(id < (*node)->data.id)
            node = &(*node)->l;
        else
            node = &(*node)->r;
    }
    if(*node == NULL)
        return ;

    cur = *node;

    if(cur->l == NULL)
        *node = cur->r;
    else
    {
        *node = cur->l;
        find_max(cur->l)->r = cur->r;
    }
    free(cur);
}

#if 0
void travel(struct node_st *root)
{
    if(root == NULL)
        return ;
    print_s(&root->data);
    travel(root->l);
    travel(root->r);
}
#else

void travel(struct node_st *root)
{
    QUEUE *qu;
    int ret;
    struct node_st *cur;

    qu = queue_create(sizeof(struct node_st *));
    if(qu == NULL)
        return ;

    queue_en(qu,&root);
    /*if error*/

    while(1)
    {
        ret = queue_de(qu,&cur);
        if(ret == -1)
            break;
        print_s(&cur->data);

        if(cur->l != NULL)
            queue_en(qu,&cur->l);
        if(cur->r != NULL)
            queue_en(qu,&cur->r);
    }

    queue_destroy(qu);

}
#endif






int main(void)
{
    int arr[] = {1,2,3,7,6,5,9,8,4};
    int i;
    struct score_st tmp,*datap;

    for(i = 0; i<sizeof(arr)/sizeof(*arr) ; i++)
    {
        tmp.id = arr[i];
        snprintf(tmp.name,NAMESIZE,"stu%d",arr[i]);
        tmp.math = rand()%100;
        tmp.chinese = rand()%100;

        insert(&tree,&tmp);
    }
    draw(tree);
    printf("\n\n\n");

    balance(&tree);
    draw(tree);
    printf("\n\n\n");

    travel(tree);

#if 0
    int tmpid = 5;
    delete(&tree,tmpid);
    draw(tree);
#endif

#if 0
    int tmpid = 2;
    datap = find(tree,tmpid);
    if(datap == NULL)
        printf("can't find id\n");
    else
        print_s(datap);
#endif
    exit(0);
}
