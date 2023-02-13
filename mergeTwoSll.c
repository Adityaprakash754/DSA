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
NODE merge(NODE first,NODE second,NODE res)
{
    int item;
    NODE cur=first;
    while(cur!=NULL)
    {
        item=cur->info;
        res=insert_r(res,item);
        cur=cur->link;
    }
    cur=second;
    while(cur!=NULL)
    {
        item=cur->info;
        res=insert_r(res,item);
        cur=cur->link;
    }
    
    return res;
    
}

void display(NODE first){
    if(first==NULL)
    {
        printf("Nothing to display\n");
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
    
    NODE first,second,res;
    first=second=res=NULL;
    int op,elem;
  
    while(1)
    {
        printf("Enter 1:insert first 2:insert second 3:merge both 4:display 5:exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("Enter element to insert\n");
            scanf("%d",&elem);
            first=insert_r(first,elem);
            break;
            case 2:
            printf("Enter element to insert\n");
            scanf("%d",&elem);
            second=insert_r(second,elem);
            break;
            case 3:
            res=merge(first,second,res);
            break;
            case 4:
            display(res);
            display(first);
            display(second);
            break;
            default:
            exit(0);
        }
        
    }

    return 0;
}

