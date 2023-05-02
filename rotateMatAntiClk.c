#include<stdio.h>

int main()
{
    int i,j,m,n,k=0;
    int a[4][4],b[16];
    printf("Enter m,n\n");
    scanf("%d %d",&m,&n);

    printf("Enter matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            //b[j][i]=a[i][j]
        }
    }

    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<m;j++)
        {
            b[k++]=a[j][i];
        }
    }

    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d",b[k++]);
        }
        printf("\n");
    }

    return 0;
}