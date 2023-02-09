#include <stdio.h>
#include<stdlib.h>
int* insert_oq(int* queue,int front,int* rear,int elem)
{
    (*rear)++;
    if(front>=*rear)
    {
        queue=(int*)malloc(sizeof(int)*((*rear)+1));
    }
    else
    {
        queue=(int*)realloc(queue,sizeof(int)*((*rear)+1));
    }
    queue[*rear]=elem;
    
    return queue;
}
int* delete_oq(int* queue,int front,int* rear)
{
    
    if(front>*rear)
    printf("no elem to delete\n");
    else if(front==*rear)
    {
        printf("deleted elem is %d \n",queue[front]);
        free(queue);
        queue=NULL;
        *rear=-1;
    }
    else
    {
        printf("deleted elem is %d \n",queue[front]);
        for(;front<*rear;front++)
        queue[front]=queue[front+1];
        
        (*rear)--;
        queue=(int*)realloc(queue,sizeof(int)*(*rear));
    }
    return queue;
    
}

void display(int* queue,int front,int rear)
{
    if(front>rear)
    printf("no elem \n");
    else
    {
        printf("elem are \n");
        for(;front<=rear;front++)
        printf("%d\t",queue[front]);
        
        printf("\n");
    }
}

int main() {
    int* queue;
    int front=0,rear=-1,ch,elem;
    while(1)
    {
        printf("1:insert 2:delete 3:display 4:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            
            case 1:
            printf("enter elem to insert\n");
            scanf("%d",&elem);
            queue=insert_oq(queue,front,&rear,elem);
            break;
            case 2:
            queue=delete_oq(queue,front,&rear);
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
