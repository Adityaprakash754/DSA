// DE queue basic operations 

#include <stdio.h>
#include <stdlib.h>
#define maxsize 4
void insert_r(int q[maxsize], int *rear,int elem){
    if(*rear==maxsize-1){
    printf("overflow condition\n");
    return; 
    }
   
    (*rear)++;
    q[*rear]=elem;
    
}
void insert_f(int q[maxsize],int *front, int *rear,int elem){
    if(*front==0 && *rear==-1){
        (*rear)++;
        q[*rear]=elem;
    }
    else if(*front!=0)
    {
        (*front)--;
        q[*front]=elem;
    }
    else
    printf("can't insert\n");
}
void delete_f(int q[maxsize], int *front,int rear)
{
    int elem;
    if(*front>rear){
    printf("underflow condition\n");
    return; 
    }
    elem=q[*front];
    (*front)++;
    printf("del element is %d\n",elem);
    
}
void delete_r(int q[maxsize], int *front,int *rear)
{
    
    if(*front>*rear){
    printf("underflow condition\n");
    return; 
    }
    printf("del element is %d\n",q[*rear]);
    (*rear)--;
    if(*front>*rear)
    {
        *front=0;
        *rear=-1;
    }
    
}
void display(int q[maxsize], int front,int rear)
{
    if(front>rear){
    printf("nothing to print\n");
    return;
    }
   
    printf("The elements are\n");
    for(;front<=rear;front++)
    printf("%d\n",q[front]);
    
    printf("\n");
   
}
int main() {
    int rear=-1,front=0,ch;
    int q[maxsize],elem;
    while(1)
    {
        printf("Enter 1:insert_f 2:insert_r 3:delete_f 4:delete_r 5:display 6:exit \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter elem to insert\n");
            scanf("%d",&elem);
            insert_f(q,&front,&rear,elem);
            break;
            case 2:
            printf("Enter elem to insert\n");
            scanf(" %d",&elem);
            insert_r(q,&rear,elem);
            break;
            case 3:
            delete_f(q,&front,rear);
            break;
            case 4:
            delete_r(q,&front,&rear);
            break;
            case 5:
            display(q,front,rear);
            break;
            default:
            exit(0);
        }
       
    }

    return 0;
}

