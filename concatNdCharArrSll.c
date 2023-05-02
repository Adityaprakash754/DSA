// concatenate nodes of sll into a character array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char info[10];
    struct node * link;
};
typedef struct node * NODE;
NODE getnode()
{
    NODE x=NULL;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory is not available\n");
        exit(0);
    }
    return x;
}
NODE insert_front(NODE first,char elem[10])
{
    NODE temp;
    temp=getnode();
    strcpy(temp->info,elem);
    temp->link=first;
    return temp;
}
void concat(NODE first,char cc[30])
{
    while(first!=NULL){
    strcat(cc,first->info);
    first=first->link;
    }
   
    printf("Concatenated string is %s \n",cc);
}
int main() {
    NODE first=NULL;
    char elem[10],cc[30];
    int ch;
    while(1)
    {
        printf("1:insert 2:concatenate 3:exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter string \n");
            scanf("%s",elem);
            first=insert_front(first,elem);
            break;
            case 2:
            concat(first,cc);
            break;
            default:
            exit(0);
        }
    }

    return 0;
}
