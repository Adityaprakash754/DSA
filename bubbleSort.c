#include<stdio.h>
void bub_sort(int a[100],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main()
{
	int a[100];
	int i,n,key;
	printf("Enter array size \n");
	scanf("%d",&n);
	printf("Enter array elements \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bub_sort(a,n);
	printf("sorted array is \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
