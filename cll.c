//basic operations on circular linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node * NODE;

// to allocate a node to linked list
NODE getNode()
{
    NODE x=NULL;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory isn't allocated you don't have enough room!!\n");
        exit(0);
    }
    return x;
}
NODE insert_f(NODE last,int item)
{
    NODE temp;
    temp=getNode();
    temp->info=item;
//inserting for first instance
    if(last==NULL)
        last=temp;
//if cll has elements
    else
        temp->link=last->link;
        
    last->link=temp;
    return last;
}
NODE insert_r(NODE last,int item)
{
    NODE temp;
    temp=getNode();
    temp->info=item;
//inserting for first instance
    if(last==NULL)
        last=temp;
//if cll has elements
    else
        temp->link=last->link;
    
    last->link=temp;
    
    return temp;
}
NODE delete_f(NODE last)
{
//if there are no elements
    if(last==NULL){
        printf("Nothing to delete\n");
        return NULL;
    }
//for single element
    if(last->link==last)
    {
        printf("deleted elem is %d\n",last->info);
        free(last);
        return NULL;
    }
//if there are multiple elements
    NODE first=last->link;
    last->link=first->link;
    printf("delted elem was %d\n",first->info);
    free(first);
    return last;
}
NODE delete_r(NODE last)
{
//if there are no elements
    if(last==NULL){
        printf("Nothing to delete\n");
        return NULL;
    }
//for single element
    if(last->link==last)
    {
        printf("deleted elem is %d\n",last->info);
        free(last);
        return NULL;
    }
//if there are multiple elements
    NODE prev=last->link;
    while(prev->link!=last)
        prev=prev->link;
        
    prev->link=last->link;
    printf("delted elem was %d\n",last->info);
    free(last);
    return prev;
}
void display(NODE last)
{
    if(last==NULL){
        printf("Nothing to display\n");
        return;
    }
    NODE curr=last->link;
    printf("Elements in cll :\n");
    while(curr!=last){
        printf("%d\t",curr->info);
        curr=curr->link;
    }
    printf("%d\t",last->info);
    printf("\n");
}
int main() {
    int item,ch;
    NODE last=NULL;
    while(1)
    {
        printf("Enter 1:insert_f 2:insert_r 3:delete_f 4:delete_r 5:display 6:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter item to insert\n");
            scanf("%d",&item);
            last=insert_f(last,item);
            break;
            case 2:
            printf("Enter item to insert\n");
            scanf("%d",&item);
            last=insert_r(last,item);
            break;
            case 3:
            last=delete_f(last);
            break;
            case 4:
            last=delete_r(last);
            break;
            case 5:
            display(last);
            break;
            default:
            exit(0);
        }
    }
    return 0;
}
