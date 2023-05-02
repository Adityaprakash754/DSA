// Dll of Structure Employee and general operation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee
{
    int Eid;
    char En[20];
    int Esal;
} E;

struct node
{
    struct node *llink;
    E info;
    struct node *rlink;
};
typedef struct node * NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory isn't allocated \n");
        exit(0);
    }
    return x;
}

NODE insert_front(NODE first)
{
    NODE temp=getnode();
    
    temp->llink=NULL;
    temp->rlink=NULL;
    printf("Enter Employee details\n");
    scanf("%d %s %d",&((temp->info).Eid),(temp->info).En,&((temp->info).Esal));
    if(first==NULL)
        return temp;
    
    temp->rlink=first;
    first->llink=temp;
    return temp;
}

void display(NODE first)
{
    if(first==NULL)
    {
        printf("Nothing to display \n");
        return;
    }
    printf("Employee details are\n");
    NODE cur=first;
    while(cur!=NULL)
    {
        printf("Eid:%d En:%s Esal:%d \n",(cur->info).Eid,(cur->info).En,(cur->info).Esal);
        
        cur=cur->rlink;
    }
}

void maxSal(NODE first)
{
    int max=0;
    NODE cur=first;
    while(cur!=NULL)
    {
        if((cur->info).Esal>max)
        max=(cur->info).Esal;
        
        cur=cur->rlink;
    }
    
    cur=first;
    while(cur!=NULL)
    {
        if((cur->info).Esal==max){
            printf("Eid:%d En:%s Esal:%d \n",(cur->info).Eid,(cur->info).En,(cur->info).Esal);
        }
        cur=cur->rlink;
    }
}

void searEn(NODE first)
{
    char ch;
    printf("Enter first letter of name to search for: \n");
    scanf(" %c",&ch);

    NODE cur=first;
    while(cur!=NULL)
    {
        if((cur->info).En[0]==ch){
        printf("Eid:%d En:%s Esal:%d \n",(cur->info).Eid,(cur->info).En,(cur->info).Esal);
        }
        
        cur=cur->rlink;
    } 
}

void updateName(NODE first)
{
    char updtName[20];
    char name[20];
    printf("Enter Name to update\n");
    scanf("%s",name);
    printf("Enter Name to update with\n");
    scanf("%s",updtName);
    
    NODE cur=first;
    while(cur!=NULL)
    {
        if(strcmp((cur->info).En,name)==0)
        break;
        cur=cur->rlink;
    }
    strcpy((cur->info).En,updtName);
    
    printf("Eid:%d En:%s Esal:%d \n",(cur->info).Eid,(cur->info).En,(cur->info).Esal);
    
}
int main() {
    int ch;
    NODE first= NULL;
    
    while(1)
    {
        printf("Enter 1:insert_f 2:display 3:maxSal 4:searchName 5:updateName 6:exit \n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            first=insert_front(first);
            break;
            case 2:
            display(first);
            break;
            case 3:
            maxSal(first);
            break;
            case 4:
            searEn(first);
            break;
            case 5:
            updateName(first);
            break;
            default:
            exit(0);
        }
       
    }

    return 0;
}
