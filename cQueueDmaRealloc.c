//cq using realloc

#include <stdio.h>
#include <stdlib.h>
int max=3;
int * insert(int *q,int *f,int *r,int *c,int elem)
{
    if(*c==max)
    {
        int i,j;
        max=max*2;
        q=(int*)realloc(q,sizeof(int)*max);
        for(i=(max/2)-1,j=max-1;i>=*f;i--){
            q[j--]=q[i];
        }
        if(*f>*r)
        *f=(*f)+max/2;
        
        (*c)++;
        *r=((*r)+1)%max;
        q[*r]=elem;
        return q;
    }
    (*c)++;
    *r=((*r)+1)%max;
    q[*r]=elem;
    return q;
}
void del(int *q,int *f,int *r,int *c)
{
   if(*c==0){
   printf("Nothing to delete\n");
   return;
   }
   (*c)--;
   printf("The deleted elem is %d\n",q[*f]);
   *f=((*f)+1)%max;
}
void display(int *q,int f,int c)
{
    if(c==0)
    {
        printf("No elem in cq\n");
        return;
    }
    int i;
    for(i=f;c>0;c--)
    {
        printf("%d\n",q[i]);
        i=(i+1)%max;
    }
}
int main() {
    int *q =(int*)malloc(sizeof(int)*max);
    int c=0,f=0,r=max-1,ch,elem;
    while(1)
    {
        printf("Enter 1:insert 2:delete 3:display 4:exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter element\n");
            scanf("%d",&elem);
            q=insert(q,&f,&r,&c,elem);
            break;
            case 2:
            del(q,&f,&r,&c);
            break;
            case 3:
            display(q,f,c);
            break;
            default:
            exit(0);
        }
    }

    return 0;
}
