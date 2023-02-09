#include <stdio.h>
void r_maj(int a[4][4],int m,int n)
{
    printf("Row major matrix is \n");
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t",a[i][j]);  
        }
    }
}

void c_maj(int a[4][4],int m,int n)
{
    printf(" \nColumn major matrix is \n");
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d \t",a[j][i]);  
        }
    }
}

int main() {
    int a[4][4],m,n;
   printf("enter m,n \n");
   scanf("%d %d",&m,&n);
   printf("elements of a \n");
   int i,j;
   for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);  
    }
    r_maj(a,m,n);
    c_maj(a,m,n);

    return 0;
}
