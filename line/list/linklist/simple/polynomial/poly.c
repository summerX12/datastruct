#include <stdlib.h> 
#include <stdio.h> 

struct node_st 
{ 
    int coef; 
    int exp; 
    struct node_st *next; 
}; 
 

struct node_st *ploy_create(int *ptr,int i) 
{ 
    int j=0,cnt=0; 
    struct node_st *head,*new,*cur; 
    head = malloc(sizeof(*head));  
    if(head == NULL)  
        return NULL;
    cur = head; 
    for(j=0; j<i; j++)
    { 
        new = malloc(sizeof(*new));   
        if(new == NULL)    
            return NULL; 
        new->coef = *(ptr+cnt); 
        cnt++; 
        new->exp = *(ptr+cnt); 
        cnt++;
        cur->next = new; 
        cur = cur->next; 
    } 
    return head; 
} 
int ploy_insert(struct node_st *p1,struct node_st *p2)
{ 
    struct node_st *cur2=p2,*new; 

    new = malloc(sizeof(*new)); 
    if(new == NULL)
       return -1;
    new->exp = cur2->next->exp; 
    new->coef = cur2->next->coef; 
    new->next = p1->next; 
    p1->next = new;
    return 0;
} 

int ploy_union(struct node_st *p1,struct node_st *p2) 
{  
    struct node_st *cur1 = p1,*cur2 = p2; 
    while(cur1->next && cur2->next)
    {  
        // printf("%d %d ",cur1->next->coef,cur1->next->exp);
        // printf("%d %d \n",cur2->next->coef,cur2->next->exp); 60
        if(cur1->next->exp == cur2->next->exp)      
        {
             cur1->next->coef += cur2->next->coef; 
             cur1 = cur1->next;
             cur2 = cur2->next;
        }
       else if(cur1->next->exp > cur2->next->exp)
       { 
           ploy_insert(cur1,cur2); 
           cur1 = cur1->next;
            cur2 = cur2->next;
       } 
       else //if(cur1->next->exp < cur2->next->exp) 
       {
           cur1 = cur1->next;
       } 
    } 
    return 0; 
}

void ploy_show(struct node_st *ptr) 
{ 
   struct node_st *cur = ptr; int i = 0; 

   while( cur->next)  
   {  
       cur = cur->next;
       // printf("%d %d\n",cur->coef,cur->exp);
        if(cur->coef != 0) 
        { 
            if(i)
                printf(" + "); 
            i = 1; 
            if(cur->exp == 0) 
                printf("%d",cur->coef);
            else if(cur->exp == 1) 
                printf("%dx",cur->coef); 
            else 
                printf("%dx^%d",cur->coef,cur->exp); 
        } 
   }
   printf("\n");
} 
   
void ploy_destroy(struct node_st *ptr)
{  
   struct node_st *cur = ptr,*q; 

   while(cur->next)
   { 
     q = cur;
     cur = cur->next;
     free(q); 
   } 
} 

       
int main()  
{ 
    struct node_st *p1,*p2; 
    int a[][2] = {{5,0},{2,1},{8,8},{3,16}}; 
    int b[][2] = {{6,1},{16,6},{-8,8}}; 

    p1 = ploy_create(a[0],4);
    p2 = ploy_create(b[0],3); 

    ploy_show(p1);
    ploy_show(p2);

    ploy_union(p1,p2);
    ploy_show(p1);

    ploy_destroy(p1);
    ploy_destroy(p2);

    exit(0);
 } 
