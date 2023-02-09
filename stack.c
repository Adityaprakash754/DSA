// Stack implementation
#include <stdio.h>
#include <stdlib.h>
#define maxsize 4
void push(int s[maxsize], int *top,int elem){
    if(*top==maxsize-1){
    printf("overflow condition\n");
    return; 
    }
    else
    {
        (*top)++;
        s[*top]=elem;
    }
}
void pop(int s[maxsize], int *top)
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
    }
}

void display(int s[maxsize], int top)
{
    printf("The elements of stack are\n");
    for(int i=top;i>=0;i--)
    printf("%d\n",s[i]);
}
int main() {
    int s[maxsize],top=-1,ch,elem;
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
