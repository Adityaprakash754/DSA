#include<stdio.h>
typedef
struct Emp
{
	int Eid;
	char En[20];
	float Esal;
} E;
void accept(E *E1)
{
	printf("Enter Emp details \n");
	scanf("%d %[^\n] %f",&(*E1).Eid,(*E1).En,&(*E1).Esal);
}
void display(E E1)
{
	printf("Displaying Emp details \n");
	printf("Eid=%d En=%s Esal=%f",E1.Eid,E1.En,E1.Esal);
}

int main()
{
	E E1;
	accept(&E1);
	display(E1);
}

