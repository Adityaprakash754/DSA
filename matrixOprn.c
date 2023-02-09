
#include <stdio.h>
void transpose(int a[4][4],int m,int n)
{
    int b[4][4],i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            b[i][j]=a[j][i];
    }
    printf("transposed matrix is \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",b[i][j]);  
        }
        printf("\n");
    }
}

void sum(int a[4][4],int b[4][4],int m,int n)
{
    int c[4][4],i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            c[i][j]=0;
            c[i][j]+=a[i][j]+b[i][j];
        }
    } 
    
     printf("addition of matrix is \n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);  
        }
        printf("\n");
    }
}

void mul(int a[4][4],int b[4][4],int m,int n,int p,int q)
{
    int c[4][4],i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    } 
    
     printf("product of matrix is \n");
     for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d ",c[i][j]);  
        }
        printf("\n");
    }
}

int main() {
    int a[4][4],b[4][4],m,n,p,q;
   printf("enter m,n,p,q \n");
   scanf("%d %d %d %d",&m,&n,&p,&q);
   printf("elements of a \n");
   int i,j;
   for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);  
    }
    printf("elements of b \n");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
            scanf("%d",&b[i][j]);  
    }
    transpose(a,m,n);
    sum(a,b,m,n);
    mul(a,b,m,n,p,q);
   
    
    
    return 0;
}
