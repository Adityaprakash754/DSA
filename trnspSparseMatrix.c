#include <stdio.h>
typedef struct sparse
{
    int row;
    int col;
    int val;
} s;

void accept(s a[10], int n, int m)
{
    int i,j,k=1,elem;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("enter the elem for row %d col %d \n",i,j);
            scanf("%d",&elem);
            if(elem!=0)
            {
                a[k].row=i;
                a[k].col=j;
                a[k].val=elem;
                k++;
            }
        }
    }
    a[0].row=n;
    a[0].col=m;
    a[0].val=k-1;
}
void display(s a[10])
{
    int i,j,k=1;
    for(i=0;i<a[0].row;i++)
    {
        for(j=0;j<a[0].col;j++)
        {
            if(a[k].row==i && a[k].col==j)
            {
                printf("%d \t",a[k].val);
                k++;
            }
            else
            printf("0 \t");
        }
        printf("\n");
    }
}
void trans(s a[10], s at[10])
{
    int i,j,k=1;
    for(i=0;i<a[0].col;i++)
    {
        for(j=1;j<=a[0].val;j++)
        {
            if(i==a[j].col)
            {
                at[k].row=a[j].col;
                at[k].col=a[j].row;
                at[k].val=a[j].val;
                k++;
            }
        }
    }
    at[0].row=a[0].col;
    at[0].col=a[0].row;
    at[0].val=a[0].val;
    
}
int main() {
    s a[10],at[10];
    int n,m;
    printf("Enter row and col\n");
    scanf("%d %d",&n,&m);
    accept(a,n,m);
    trans(a,at);
    display(at);
    return 0;
}
