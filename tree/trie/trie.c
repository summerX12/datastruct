#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DESC_SIZE   256
#define KEY_SIZE    256
#define BUFSIZE     1024
#define FNAME       "log"

struct node_st
{
    struct node_st *ch[26];
    char desc[DESC_SIZE];
};


int get_word(FILE *fp,char *key,char *desc)
{
    char buf[BUFSIZE];
    char *retp;
    int i,j;

    retp = fgets(buf,BUFSIZE,fp);
    if(retp == NULL)
        return -1;

    for(i=0; i<KEY_SIZE-1 && buf[i] != ':'; i++)
        key[i] = buf[i];
    key[i] = '\0';

    i++;

    for(j = 0; j<DESC_SIZE-1 && buf[i] != '\0'; j++,i++)
        desc[j] = buf[i];
    desc[j] = '\0';

    return 0;
}

struct node_st *newnode(void)
{
    struct node_st *node;
    int i;

    node = malloc(sizeof(*node));
    if(node == NULL)
        return NULL;

    node->desc[0] = '\0';
    for(i=0; i< 26; i++)
        node->ch[i] = NULL;

    return node;
}

int insert(struct node_st **root,char *key,char *desc)
{
    
    if(*root == NULL)
    {
        *root = newnode();
        if(*root == NULL)
            return -1;
    }

    if(*key == '\0')
    {
        strcpy((*root)->desc,desc);
        return 0;
    }

    return insert((*root)->ch+*key-'a',key+1,desc);
}

char *find(struct node_st *root,char *key)
{
    if(root == NULL)
        return NULL;

    if(*key == '\0')
        return root->desc;
    return find(root->ch[*key-'a'],key+1);
}


int main()
{
    struct node_st *tree = NULL;
    FILE *fp;
    char desc[DESC_SIZE]={'\0'},key[KEY_SIZE]={'\0'};
    int ret;
    char *datap;

    fp = fopen(FNAME,"r");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    while(1)
    {
        ret = get_word(fp,key,desc);
        if(ret == -1)
            break;
/*
        puts(key);
        puts(desc);
*/
        insert(&tree,key,desc);
    }

    datap = find(tree,"donkey");
    if(datap == NULL)
        printf("can't find\n");
    else
        puts(datap);

    fclose(fp);

    exit(0);
}
