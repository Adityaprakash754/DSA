// circular queue

// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#define max 4
void insert_cq(int q[max],int *rear,int *count,int elem)
{
    if(*count==max)
    {
        printf("overflow\n");
        return;
    }
    *rear=((*rear)+1)%max;
    q[*rear]=elem;
    (*count)++;
}
void delete_cq(int q[max],int *front,int *count)
{
    int elem;
    if(*count==0)
    {
        printf("underflow\n");
        return;
    }
    elem=q[*front];
    *front=((*front)+1)%max;
    (*count)--;
    printf("deleted elem is %d \n",elem);
}
void display_cq(int q[max],int front,int count)
{
    if(count==0){
    printf("no elem in queue\n");
    return;
    }
    printf("Elements in queue are:");
    for(;count>0;count--)
    {
        printf("%d ",q[front]);
        front=(front+1)%max;
    }
    printf("\n");
    
}
int main() {
    int q[max],front=0,rear=max-1,count=0,elem,ch;
    while(1)
    {
        printf("1:insert \n2:delete \n3:display \n4:exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("enter elem\n");
            scanf("%d",&elem);
            insert_cq(q,&rear,&count,elem);
            break;
            case 2:
            delete_cq(q,&front,&count);
            break;
            case 3:
            display_cq(q,front,count);
            break;
            default:
            exit(0);
        }
    }

    return 0;
}

