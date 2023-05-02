// stack of structure employee


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 4

typedef struct Employee
{
    int Eid;
    char En[10];
    float Esal;
} E;


void push(E s [maxsize], int *top, int id,char name[10],float sal) {
    if (*top==maxsize-1){
    printf ("overflow condition\n");
    return;
    }
   else
    {
        (*top)++;
        s[(*top)].Eid=id;
        strcpy(s[(*top)].En,name);
        s[(*top)].Esal=sal;
    }
}

void pop(E s [maxsize], int *top) 
{
    int id;
    char name[10];
    float sal;
    if (*top==-1) {
    printf ("underflow condition\n") ;
    return;
    } 
    else
    {
        id=s[(*top)].Eid;
        strcpy(name,s[(*top)].En);
        sal=s[(*top)].Esal;
        (*top)--;
    printf("popped employee's Id:%d \nName:%s \nSal:%f \n ",id,name,sal) ;
    }
}
void display(E s [maxsize], int top) 
{
    for(int i=top;i>=0;i--){
        printf ("The elements of stack have employe's Id:%d \nName:%s \nSal:%f \n",s[i].Eid,s[i].En,s[i].Esal);
        
    }

}

int main()
{
    E s [maxsize];
    int top=-1, ch, id ;
    char name[10];
    float sal;
    while (1){
        printf("Enter 1:push 2:pop 3: display 4:exit \n");
        scanf("%d",&ch);
        switch (ch) {
        case 1:
        printf ("Enter id,name,sal to push\n");
        scanf ("%d %s %f",&id,name,&sal);
        push (s, &top, id,name,sal);
        break;
        case 2:
        pop (s,&top);
        break;
        case 3:
        display(s ,top);
        break;
        default:
        exit (0);
        } 
  
    ch=4;
    }
    return 0;
}
