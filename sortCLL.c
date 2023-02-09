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
int count(NODE last)
{
    int c=0;
    NODE curr;
    if(last==NULL)
    return c;
    curr=last->link;
    while(curr!=last){
	c++;
	curr=curr->link;
	}c++;
    return c;

}
 
void sort(NODE last,int c)
{
    int i,t,j;
    NODE first,next;
    for(i=0;i<c-1;i++)
    {
	first=last->link;
	next=first->link;
	for(j=0;j<c-i-1;j++)
	{
	    if(first->info>next->info)
	    {
		t=first->info;
		first->info=next->info;
		next->info=t;
	     }
	     first=next;
	     next=first->link;
	}
    }   	
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
    int item,ch,cnt;
    NODE last=NULL;
    while(1)
    {
        printf("Enter 1:insert_f 2:count 3:display 4:sort 5:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter item to insert\n");
            scanf("%d",&item);
            last=insert_f(last,item);
            break;
            case 2:
            cnt=count(last);
	    printf("%d \n",cnt);
            break;
            case 3:
            display(last);
            break;
            case 4:
	    sort(last,cnt);
	    break;
            default:
            exit(0);
        }
    }
    return 0;
}
