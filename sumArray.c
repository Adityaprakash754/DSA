#include<stdio.h>
void add(int a[10], int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=a[i];
	}
	printf("The sum is %d \n",sum);
}
int main()
{
	int i,a[10],n;
	printf("Enter no of elements \n");
	scanf("%d",&n);
	printf("Enter array elements \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	add(a,n);
	return 0;
}
