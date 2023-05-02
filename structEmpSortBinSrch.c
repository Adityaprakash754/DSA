// binary search of structure employee based on employee id
#include <stdio.h>

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
void sort(E e1[10],int n)
{
    E temp;
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++)
        {
            if(e1[j].Eid>e1[j+1].Eid)
            {
                temp=e1[j];
                e1[j]=e1[j+1];
                e1[j+1]=temp;
            }
        }
    }
    
}
void bin_search_Eid(E e1[10],int n)
{
    int key,i=-1,low,high,mid;
    printf("Enter Eid to search for \n");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(e1[mid].Eid==key){
            i++;
            break;
        }
        else if(key>e1[mid].Eid)
        low=mid+1;
        else
        high=mid-1;
    }
        if(i>=0)
        printf("Eid:%d \nEn:%s \nEsal:%f \n",e1[mid].Eid,e1[mid].En,e1[mid].Esal);
        else
        printf("Not found\n");
    

}


int main()
{
    int n;
    E e1[10];
    accept(e1,&n);
    sort(e1,n);
    
    bin_search_Eid(e1,n);

    return 0;
}
