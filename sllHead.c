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

void insert_f(NODE head,int item)
{
    NODE temp=getNode();
    temp->info=item;
    temp->link=head->link;
    head->link=temp;
}

void insert_r(NODE head,int item)
{
    NODE cur,temp=getNode();
    temp->info=item;
    temp->link=NULL;
    cur=head;
    
    while(cur->link!=NULL)
        cur=cur->link;
    
    cur->link=temp;
}

void delete_f(NODE head)
{
    if(head->link==NULL)
    {
        printf("Nothing to delete\n");
        return;
    }
    NODE first,second;
    first=head->link;
    second=first->link;
    printf("Deleted elem was %d \n",first->info);
    free(first);
    head->link=second;
}
void delete_r(NODE head)
{
    if(head->link==NULL)
    {
        printf("Nothing to delete\n");
        return ;
    }
    NODE prev=NULL,cur=head;
    while(cur->link!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("Deleted elem was %d \n",cur->info);
    free(cur);
    prev->link=NULL;
     
}

void display(NODE head){
    if(head->link==NULL)
    {
        printf("Nothing to display\n");
        return;
    }
    NODE cur=head->link;
    printf("Elements in SLL are\n");
    while(cur!=NULL)
    {
        printf("%d \t",cur->info);
        cur=cur->link;
    }
    printf("\n");
}

int main() {
    
    NODE head;
    head=(NODE)malloc(sizeof(struct node));
    int op,elem;
  
    while(1)
    {
        printf("Enter 1:insert front 2:insert rear 3:delete front 4:delete rear 5:display 6:exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("Enter element to insert\n");
            scanf("%d",&elem);
            insert_f(head,elem);
            break;
            case 2:
            printf("Enter element to insert\n");
            scanf("%d",&elem);
            insert_r(head,elem);
            break;
            case 3:
            delete_f(head);
            break;
            case 4:
            delete_r(head);
            break;
            case 5:
            display(head);
            break;
            default:
            exit(0);
        }
        
    }

    return 0;
}

