#include<stdio.h>
void add(int a,int b)
{
	int sum=(a&b)+(a|b);
	printf("sum=%d \n",sum);
}
void swap(int a,int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
	
	printf("a=%d b=%d \n",a,b);
}

void swap_bit(int a,int b)
{
	a= a^b;
   	b= a^b;
   	a= a^b;
   	printf("value of a=%d and b=%d after swap \n",a,b);
}
int main(){
	int a,b;
   	printf("enter the values for a and b:\n");
   	scanf("%d%d",&a,&b);
    add(a,b);
    swap(a,b);
    swap_bit(a,b);
   
   return 0;
}
