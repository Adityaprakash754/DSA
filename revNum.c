#include<stdio.h>
void rev_num(int num)
{
	int rev=0,rem;
	while(num!=0)
	{
		rem=num%10;
		rev=rev*10+rem;
		num=num/10;
	}
	printf("The reversed no is %d",rev);
}
int main(){
	int num;
	printf("Enter no\n");
	scanf("%d",&num);
	printf("The original no is %d \n",num);
	rev_num(num);
	return 0;
}
