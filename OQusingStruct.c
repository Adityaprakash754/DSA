#include<stdio.h>
#include<stdlib.h>
#define maxsize 4
typedef struct emp
{
    int eid;
    char en[10];
} e;
void insert(e q[maxsize],int front,int *rear)
{
    if(*rear==maxsize-1)
    {
        printf("overflow \n");
        return;
    }
    (*rear)++;
    printf("Enter eid and en \n");
    scanf("%d %s",&(q[*rear].eid),q[*rear].en);
}
void del(e q[maxsize],int *front,int rear)
{
    if(*front>rear)
    {
        printf("underflow \n");
        return;
    }
    
    printf("deleted queue had \n");
    printf("%d %s\n",(q[*front].eid),q[*front].en);
    (*front)++;
}
void display(e q[maxsize], int front,int rear)
{
    if(front>rear)
    printf("nothing to print");
    else{
    printf("The elements are\n");
    for(;front<=rear;front++)
    printf("%d\t %s\n",q[front].eid,q[front].en);
    
    }
}
int main()
{ 
    e queue[maxsize];
    int front=0,rear=-1,ch;
    while(1)
    {
        printf("enter 1:insert 2:delete 3:display 4:exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            insert(queue,front,&rear);
            break;
            case 2:
            del(queue,&front,rear);
            break;
            case 3:
            display(queue,front,rear);
            break;
            default:
            exit(0);
        }
    }
    return 0;
}
