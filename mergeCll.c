//merging two cll to third

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node * NODE;
NODE getNode()
{
    NODE x=NULL;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory isn't allocated \n");
        exit(0);
    }
    return x;
}
NODE insert_f(NODE last,int item)
{
    NODE temp;
    temp=getNode();
    temp->info=item;
    if(last==NULL)
        last=temp;
    else
        temp->link=last->link;
        
    last->link=temp;
    return last;
}

NODE merge(NODE first,NODE second)
{
	NODE result=NULL,temp=NULL,curr=NULL;
//if there are no elements in both of the cll
	if(first==NULL && second==NULL)
	return NULL;
//if first has elements    
if(first!=NULL)
    {
        curr=first->link;
        do{
            temp=getNode();
            temp->info=curr->info;
//if no element has been inserted prior to this
            if(result==NULL)
            {
                temp->link=temp;
		result=temp;
            }
//if elements has been inserted atleast once
            else
            {
                temp->link=result->link;
                result->link=temp;
                result=temp;
            }
            curr=curr->link;
        }while(curr!=first->link);
    }
//if second has elements
    if(second!=NULL)
    {
        curr=second->link;
        do{
            temp=getNode();
            temp->info=curr->info;
//if first was NULL & no element of second is inserted yet          
            if(result==NULL)
            {
                temp->link=temp;
		result=temp;
            }
//either first was not NULL or element of second was inserted at least once              
            else
            {
                temp->link=result->link;
                result->link=temp;
                result=temp;
            }
            curr=curr->link;
        }while(curr!=second->link);
    }
	return result;
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
    NODE first=NULL,second=NULL,result=NULL;
    while(1)
    {
        printf("Enter 1:insert_f 2:insert_s 3:display 4:merge 6:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter item to insert\n");
            scanf("%d",&item);
            first=insert_f(first,item);
            break;
            case 2:
            printf("Enter item to insert\n");
            scanf("%d",&item);
            second=insert_f(second,item);
            break;
            case 3:
            display(result);
            break;
            case 4:
            result=merge(first,second);
            break;
            default:
            exit(0);
        }
    }
    return 0;
}
