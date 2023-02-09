
#include <stdio.h>
#define maxsize 20

int F(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        return 2;
        case '*':
        case '/':
        case '%':
        return 4;
        case '$':
        case '^':
        return 5;
        case '(':
        return 0;
        case '#':
        return -1;
        default:
        return 8;
    }
    
}
int G(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        case '%':
        return 3;
        case '$':
        case '^':
        return 6;
        case '(':
        return 9;
        case ')':
        return 0;
        default:
        return 7;
    }
    
}
void push(char s[maxsize], int *top,char elem){
    if(*top==maxsize-1){
    printf("overflow condition\n");
    return; 
    }
    (*top)++;
    s[*top]=elem;
    
}
char pop(char s[maxsize], int *top)
{
    char elem;
    if(*top==-1)
    printf("underflow condition\n");
   
    else
    {
        elem=s[*top];
        (*top)--;
        return elem;
    }
}
void con_in_pos(char infix[maxsize],char postfix[maxsize])
{
    char s[maxsize],symbol;
    int top=-1,i=0,j=0;
    push(s,&top,'#');
    while(infix[i]!='\0')
    {
        symbol=infix[i++];
        while(F(s[top])>G(symbol))
        postfix[j++]=pop(s,&top);
        
        if(F(s[top])!=G(symbol))
        push(s,&top,symbol);
        else
        pop(s,&top);
    }
    while(top!=0)
    postfix[j++]=pop(s,&top);
    
     postfix[j]='\0';
}
int main() {
    char infix[maxsize], postfix[maxsize];
    printf("Enter infix\n");
    scanf("%s",infix);
    con_in_pos(infix,postfix);
    printf("Postfix: %s \n",postfix);

    return 0;
}
