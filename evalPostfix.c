
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define maxsize 20

int compute(int op1,char s,int op2)
{
    int res;
    switch(s)
    {
        case '+':
        res=op1+op2;
        break;
        case '-':
        res=op1-op2;
        break;
        case '*':
        res=op1*op2;
        break;
        case '/':
        res=op1/op2;
        break;
        case '%':
        res=op1%op2;
        break;
        
        case '$':
        case '^':
        res=pow(op1,op2);
        break;
    }
    return res;
    
}

void push(int s[maxsize], int *top,int elem){
    if(*top==maxsize-1){
    printf("overflow condition\n");
    return; 
    }
    (*top)++;
    s[*top]=elem;
    
}
int pop(int s[maxsize], int *top)
{
    int elem;
    if(*top==-1)
    printf("underflow condition\n");
   
    else
    {
        elem=s[*top];
        (*top)--;
    }
    return elem;
}
int eval_post(char postfix[maxsize])
{
    char symbol;
    int s[maxsize];
    int top=-1,i,op1,op2,res;
    
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
        push(s,&top,symbol-'0');
        
        else{
            op2=pop(s,&top);
            op1=pop(s,&top);
            res=compute(op1,symbol,op2);
            
            push(s,&top,res);
        }
        
    }
    
    return pop(s,&top);
}
int main() {
    char postfix[maxsize];
    int res;
    printf("Enter postfix\n");
    scanf("%s",postfix);
    res=eval_post(postfix);
    printf("Result: %d",res);

    return 0;
}
