// stack of strings

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define maxsize 4

void push(char s[maxsize][20],int *top,char inputs[20])
{
    if(*top==maxsize-1){
    printf("overflow condition \n");
    return;
    }
    else{
        (*top)++;
        strcpy(s[*top],inputs);
    }
}
void pop(char s[maxsize][20],int *top){
    
    char inputs[20];
    if(*top==-1){
        printf("Underflow condition\n");
        return;
    }
    else
    {
        strcpy(inputs,s[*top]);
        (*top)--;
        printf("Popped element is %s \n",inputs);
         
    }
    
}
void display(char s[maxsize][20],int top)
{
    printf("Elements in stack are\n");
    for(int i=top;i>=0;i--)
    printf("%s \n",s[i]);
    
}
int main()
{
    int op;
    char s[maxsize][20];
    char inputs[20];
    int top=-1;
    while(1)
    {
       
       printf("Enter operation to be performed 1:push 2:pop 3:display 4:exit \n");
       scanf("%d",&op);
       
       switch(op){
           case 1:
           printf("Enter string to be pushed \n");
           scanf(" %[^\n]",inputs);
           push(s,&top,inputs);
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
       
       op=0;
       
    }
    
    return 0;
}