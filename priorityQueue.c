// priority queue

#include <stdio.h>
#include <stdlib.h>
#define maxsize 4
typedef struct priority
{
    char pro[2];
    int pri;
    
} P;

void pri_check(P p[maxsize],int front,int rear)
{
    int i;
    for(front=1;front<rear;front++)
    {
        for(i=front;i<=rear-front;i++)
        {
            if(p[i].pri>p[i+1].pri)
            {
                P temp;
                temp=p[i];
                p[i]=p[i+1];
                p[i+1]=temp;
            }
        }
    }
}
void insert(P p[maxsize],int front,int *rear)
{
    if(*rear==maxsize-1){
    printf("overflow \n");
    return;
    }
    (*rear)++;
    printf("Enter process and priority to be inserted \n");
    scanf("%s %d",p[*rear].pro,&p[*rear].pri);
    
    if(*rear>1)
    {
        pri_check(p,front,*rear);
    }
}

void delete(P p[maxsize],int *front,int rear)
{
    if(*front>rear){
    printf("underflow \n");
    return;
    }
    
    printf("Deleted  process and it's priority was %s and %d \n",p[*front].pro,p[*front].pri);
    
    (*front)++;
    
}
void display(P p[maxsize],int front,int rear)
{
    if(front>rear){
        printf("nothing to display \n");
        return;
    }
    for(;front<=rear;front++)
    printf("%s \t %d \n",p[front].pro,p[front].pri);
}
int main() {
    P p[maxsize];
    int front=0,rear=-1,op;
    
    while(1){
        printf("Enter 1:to insert 2:to delete 3:to display 4:to exit \n");
        scanf("%d",&op);
        switch(op){
            case 1:
            insert(p,front,&rear);
            break;
            case 2:
            delete(p,&front,rear);
            break;
            case 3:
            printf("The process and it's priority in queue are \n");
            display(p,front,rear);
            break;
            default:
            exit(0);
        }
    }

    return 0;
}
