#include<stdio.h>
void accept(int a[5],int *n){
	int i;
	printf("enter no of elements\n");
	scanf("%d",n);
	printf("Enter array elements\n");
	for(i=0;i<*n;i++)
		scanf("%d",&a[i]);
}

void display(int a[5],int n)
{
	int i;
	printf("The array elements are \n");
	for(i=0;i<n;i++)
		printf("%d \t",a[i]);
}

int main()
{
	int a[5],n;
	accept(a,&n);
	display(a,n);
	return 0;
}
