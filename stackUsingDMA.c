// stack implementation using DMA
#include <stdio.h>
#include <stdlib.h>
void push(int *s, int *top,int elem){
    (*top)++;
    if((*top)==0)
     s[*top]=elem;
    
    else
    {
      
        s=(int*)realloc(s,sizeof(int)*((*top)+1));
        s[*top]=elem;
    }
}
void pop(int *s, int *top)
{
    int elem;
    if(*top==-1){
    printf("underflow condition\n");
    return; 
    }
    else
    {
        elem=s[*top];
        (*top)--;
        printf("popped element is %d\n",elem);
        if((*top)!=-1)
        s=(int*)realloc(s,sizeof(int)*((*top)+1));
        else
        return;
    }
}

void display(int *s, int top)
{
    printf("The elements of stack are\n");
    for(int i=top;i>=0;i--)
    printf("%d\n",s[i]);
}
int main() {
    int *s,top=-1,ch,elem;
    s=(int*)malloc(sizeof(int));
    while(1)
    {
        printf("Enter 1:push 2:pop 3:display 4:exit \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("Enter elem to push\n");
            scanf("%d",&elem);
            push(s,&top,elem);
            break;
            case 2:
            pop(s,&top);
            break;
            case 3:
            display(s,top);
            break;
            default:
            exit(0);
        }
        ch=4;
    }

    return 0;
}
