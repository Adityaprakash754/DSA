#include <stdio.h>

int add(int sum, int n)
{
    if(n==0)
        return 0;

    sum = sum+2;
    n--;

    return sum + add(sum,n);
}

int main()
{
    //sum = 1 for odd and sum = 2 for even
    int sum = 2;
    int n = 5;
    sum = sum + add(sum,n-1);
    printf("%d\n",sum);
    return 0;
}