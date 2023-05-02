// DFS both recursive and iteartive but we are calling iteartive fun

#include<stdio.h>
#include<stdlib.h>
int a[10][10],F[10];
void read_adj(int n)
{
    int i;
    printf("Enter the matrix\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void dfs(int u,int n)
{
    F[u]=1;
    int v;
    printf("%d",u);
    for(v=0;v<n;v++)
    {
        if(a[u][v]==1&&F[v]==0)
        {
            dfs(v,n);
        }
    }
}
void dfs_iterative(int u, int n)
{
    int top=-1;
    int S[10],v;
    F[u]=1;
    printf("The nodes reachable from %d is \n",u);
    S[++top]=u;
    printf("%d\t",u);
    while(top!=-1)
    {
        u=S[top--];
        for(v=0;v<n;v++){
            if(a[u][v]==1&&F[v]==0)
            {
                printf("%d\t",v);
                F[v]=1;
                S[++top]=v;
            }
        }
    }
    printf("\n");
}
int main()
{
    int source,n;
    printf("Enter the number of nodes in the graph\n");
    scanf("%d",&n);
    read_adj(n);
    for(source=0;source<n;source++)
    {
        for(int i=0;i<n;i++)
            F[i]=0;
        
        dfs_iterative(source,n);
	printf("\n");
    }
}