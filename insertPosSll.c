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
int count_n(NODE first)
{
    int ctr=0;
    while(first!=NULL)
    {
        ctr++;
        first=first->link;
    }
    return ctr;
}
NODE insertPos(NODE first,int elem,int pos)
{
    int count=count_n(first);
    if(pos>count+1)
    {
        printf("Inesrtion is not possible\n");
        return first;
    }
    NODE temp=getNode();
    temp->info=elem;
    
    if(pos==1)
    {
        temp->link=first;
        return temp;
    }
    NODE prev,cur=first;
    prev=NULL;
    for(int i=1;i<pos;i++)
    {
        prev=cur;
        cur=cur->link;
    }
    
    temp->link=cur;
    prev->link=temp;
    return first;
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
    int op,elem,pos;
  
    while(1)
    {
        printf("Enter 1:insert first 2:insert at a position 3:display 4:exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("Enter element to insert\n");
            scanf("%d",&elem);
            first=insert_r(first,elem);
            break;
            case 2:
            printf("Enter element and position to insert\n");
            scanf("%d%d",&elem,&pos);
            first=insertPos(first,elem,pos);
            break;
            case 3:
            display(first);
            break;
            default:
            exit(0);
        }
        
    }

    return 0;
}

