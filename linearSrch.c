#include<stdio.h>
void linear_search(int a[10],int n)
{
	int i,key,found=0;
	printf("Enter elements to be searched\n");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			found++;
			break;
		}
	}
	if(found!=0)
		printf("The key %d is found at %d \n",key,i);
	else
		printf("Search unsuccesful \n");
}
int main()
{
	int i,a[10],n;
	printf("Enter no of elements \n");
	scanf("%d",&n);
	printf("Enter array elements \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	linear_search(a,n);
	return 0;
}
	
