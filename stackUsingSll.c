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

NODE push(NODE stack,int item)
{
    NODE temp=getNode();
    temp->info=item;
    temp->link= stack;
    
    return temp;
}

NODE pop(NODE stack)
{
    if(stack ==NULL)
    {
        printf("Nothing to pop\n");
        return NULL;
    }
    NODE next= stack->link;
    printf("Popped elem was %d \n", stack->info);
    free(stack);
    return next;
}

void display(NODE stack){
    if(stack==NULL)
    {
        printf("Nothing to display\n");
        return;
    }
    printf("Elements of stack are\n");
    while(stack!=NULL)
    {
        printf("%d \t",stack->info);
        stack = stack->link;
    }
    printf("\n");
}

int main() {
    
    NODE stack;
    stack=NULL;
    int op,elem;
  
    while(1)
    {
        printf("Enter 1:push element onto stack 2:pop element from stack 3:display elements of stack 4:exit\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            printf("Enter element to push\n");
            scanf("%d",&elem);
            stack=push(stack,elem);
            break;
            case 2:
            stack=pop(stack);
            break;
            case 3:
            display(stack);
            break;
            default:
            exit(0);
        }
        
    }

    return 0;
}

