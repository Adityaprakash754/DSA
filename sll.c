#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node * link;
};
typedef struct node * NODE;

NODE getNode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL){
    printf("memory wasn't allocated \n");
    exit(0);
    }
    return x;
}

NODE insert_f(NODE first,int item)
{
    NODE temp=getNode();
    temp->info=item;
    temp->link=first;
    
    return temp;
}

NODE insert_r(NODE first,int item)
{
    NODE cur,temp=getNode();
    temp->info=item;
    temp->link=NULL;
    cur=first;
    
    if(cur==NULL)
    return temp;
    
    while(cur->link!=NULL)
        cur=cur->link;
    
    cur->link=temp;
    return first;
}

NODE delete_f(NODE first)
{
    if(first==NULL)
    {
        printf("Nothing to delete\n");
        return NULL;
    }
    NODE next=first->link;
    printf("Deleted elem was %d \n",first->info);
    free(first);
    return next;
}
NODE delete_r(NODE first)
{
    NODE prev,cur;
    if(first==NULL)
    {
        printf("Nothing to delete\n");
        return NULL;
    }
    else if(first->link==NULL)
    {
        printf("Deleted elem was %d \n",first->info);
        free(first);
        return NULL;
    }
    cur=first;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("Deleted elem was %d \n",cur->info);
    free(cur);
    
    prev->link=NULL;
    return first; 
}

void display(NODE first){
    if(first==NULL)
    {
        printf("Nothing to diaplay\n");
        return;
    }
    printf("Elements in SLL are\n");
    while(first!=NULL)
    {
        printf("%d \t",first->info);
        first=first->link;
    }
    printf("\n");
}

int main() {
    
    NODE first;
    first=NULL;
    int op,elem,count;
  
    while(1)
    {
        printf("Enter 1:insert front 2:insert rear 3:delete front 4:delete rear 5:display 6:exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("Enter element to insert\n");
            scanf("%d",&elem);
            first=insert_f(first,elem);
            break;
            case 2:
            printf("Enter element to insert\n");
            scanf("%d",&elem);
            first=insert_r(first,elem);
            break;
            case 3:
            first=delete_f(first);
            break;
            case 4:
            first=delete_r(first);
            break;
            case 5:
            display(first);
            break;
            default:
            exit(0);
        }
        
    }

    return 0;
}
