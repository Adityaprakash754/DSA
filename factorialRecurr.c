#include <stdio.h>

int fact(int n)
{
    if(n<2)
    return 1;
    else 
    return n*fact(n-1);
    
}
int main() {
    int n;
    printf("Enter n\n");
    scanf("%d",&n);
    printf("%d\n",fact(n));

    return 0;
}
