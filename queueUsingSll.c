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

NODE insert(NODE queue,int item)
{
    NODE cur,temp=getNode();
    temp->info=item;
    temp->link=NULL;
    cur=queue;
    
    if(cur==NULL)
    return temp;
    
    while(cur->link!=NULL)
        cur=cur->link;
    
    cur->link=temp;
    return queue;
}

NODE delete(NODE queue)
{
    if(queue==NULL)
    {
        printf("Nothing to delete\n");
        return NULL;
    }
    NODE next=queue->link;
    printf("Deleted elem was %d \n",queue->info);
    free(queue);
    return next;
}

void display(NODE queue){
    if(queue==NULL)
    {
        printf("Nothing to display\n");
        return;
    }
    printf("Elements of queue are\n");
    while(queue!=NULL)
    {
        printf("%d \t",queue->info);
        queue=queue->link;
    }
    printf("\n");
}

int main() {
    
    NODE queue;
    queue=NULL;
    int op,elem;
  
    while(1)
    {
        printf("Enter 1:insert element into queue 2:delete element from the queue 3:display queue elements 4:exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("Enter element to insert\n");
            scanf("%d",&elem);
            queue=insert(queue,elem);
            break;
            case 2:
            queue=delete(queue);
            break;
            case 3:
            display(queue);
            break;
            default:
            exit(0);
        }
        
    }

    return 0;
}

