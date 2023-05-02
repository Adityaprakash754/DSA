// linear search of structure employee based on Eid/Ename
#include <stdio.h>
#include <string.h>
typedef struct Employee
{
    int Eid;
    char En[10];
    float Esal;
} E;

void accept(E e1[10],int *n)
{
    printf("Enter no of emp\n");
    scanf("%d",n);
    for(int i=0;i<*n;i++){
        printf("Enter Eid,En,Esal of employee %d \n",i+1);
        scanf("%d %s %f",&e1[i].Eid,e1[i].En,&e1[i].Esal);
        
    }
}
void lin_search_Eid(E e1[10],int n)
{
    int key,i;
    printf("Enter Eid to search for \n");
    scanf("%d",&key);
    for(i=0;i<n;i++)
    {
        if(e1[i].Eid==key)
        break;
    }
    printf("Eid:%d \nEn:%s \nEsal:%f \n",e1[i].Eid,e1[i].En,e1[i].Esal);
}
void lin_search_En(E e1[10],int n)
{
    int i;
    char key[10];
    printf("Enter En to search for \n");
    scanf("%s",key);
    for( i=0;i<n;i++)
    {
        if(strcmp(e1[i].En,key)==0)
        break;
    }
    printf("En:%s \nEid:%d \nEsal:%f \n",e1[i].En,e1[i].Eid,e1[i].Esal);
}

int main()
{
    int n,i;
    E e1[10];
    accept(e1,&n);
    printf("Enter 1 for search on Eid  2 for search on En \n");
    scanf("%d",&i);
    if(i==1)
    lin_search_Eid(e1,n);
    else if(i==2)
    lin_search_En(e1,n);

    return 0;
}