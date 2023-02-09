#include<stdio.h>
void swap(int *num1,int *num2)
{
	int temp;
	temp=*num1;
	*num1=*num2;
	*num2=temp;
}
void display(int num1,int num2)
{
	printf("Values after swapping \n");
	printf("num1=%d \n",num1);
	printf("num2=%d \n",num2);
}
int main()
{
	int num1,num2;
	printf("Enter the numbers\n");
	scanf("%d%d",&num1,&num2);
	swap(&num1,&num2);
	display(num1,num2);
	return 0;
}

	
