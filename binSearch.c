#include<stdio.h>
void bin_search(int a[100],int n,int key)
{
	int low,high,mid,loc=-1;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
		{
			loc=mid+1;
			break;
		}
		else if(key>a[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	if(loc>=0)
		printf("The key %d is found at %d \n",key,loc);
	else
		printf("search unsuccessful \n");
}
void sel_sort(int a[100],int n)
{
	int i,j,pos;
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				pos=j;
			}
			if(i!=pos)
			{
				int temp;
				temp=a[i];
				a[i]=a[pos];
				a[pos]=temp;
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
	sel_sort(a,n);
	printf("Enter key to be searched \n");
	scanf("%d",&key);
	bin_search(a,n,key);
}
