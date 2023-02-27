#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *llink;
    int info;
    struct node *rlink;
};
typedef struct node * NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory isn't allocated \n");
        exit(0);
    }
    return x;
}

NODE insert_front(NODE first,int item)
{
    NODE temp=getnode();
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(first==NULL)
        return temp;
    
    temp->rlink=first;
    first->llink=temp;
    return temp;
}

NODE insert_rear(NODE first,int item)
{
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    temp->llink=NULL;
    temp->rlink=NULL;
    if(first==NULL)
        return temp;
        
    cur=first;
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    
    cur->rlink=temp;
    temp->llink=cur;
    return first;
}
NODE delete_front(NODE first)
{
    NODE next;
    if(first==NULL)
    {
        printf("Nothing to delete\n");
        return first;
    }
    next=first->rlink;
    if(next!=NULL)
    next->llink=NULL;
    
    printf("Deleted element was %d \n",first->info);
    free(first);
    return next;
}
NODE delete_rear(NODE first)
{
    NODE prev,cur;
    if(first==NULL)
    {
        printf("Nothing to delete\n");
        return first;
    }
    prev=NULL;
    cur=first;
    while(cur->rlink!=NULL)
    {
        prev=cur;
        cur=cur->rlink;
    }
    printf("Deleted element was %d \n",cur->info);
    free(cur);
    
    if(prev!=NULL){
    prev->rlink=NULL;
    return first;
    }
    return prev;
}
void display(NODE first)
{
    if(first==NULL)
    {
        printf("Nothing to display \n");
        return;
    }
    printf("Elements of DLL are\n");
    NODE cur=first;
    while(cur!=NULL)
    {
        printf("%d ",cur->info);
        cur=cur->rlink;
    }
    printf("\n");
}

int main() {
    int ch,elem;
    NODE first= NULL;
    
    while(1)
    {
        printf("Enter 1:insert_f 2:insert_r 3:delete_f 4:delete_r 5:display 6:exit \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter elem to insert\n");
            scanf("%d",&elem);
            first=insert_front(first,elem);
            break;
            case 2:
            printf("Enter elem to insert\n");
            scanf("%d",&elem);
            first=insert_rear(first,elem);
            break;
            case 3:
            first=delete_front(first);
            break;
            case 4:
            first=delete_rear(first);
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