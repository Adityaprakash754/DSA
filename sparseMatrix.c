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
int main() {
    s a[10];
    int n,m;
    printf("Enter row and col\n");
    scanf("%d %d",&n,&m);
    accept(a,n,m);
    display(a);
    return 0;
}
