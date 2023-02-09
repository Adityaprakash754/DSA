#include<stdio.h>
void toh(int n,char s,char t,char d)
{
	if(n==0)
	return;
	toh(n-1,s,d,t);
	printf("%d is moved from %c to %c\n",n,s,d);
	toh(n-1,t,s,d);
}

int main()
{
	int n;
	char s='a',t='b',d='c';
	printf("Enter no of disc\n");
	scanf("%d",&n);
	
	toh(n,s,t,d);
	
	return 0;
}

