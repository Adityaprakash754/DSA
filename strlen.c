#include <stdio.h>
void str_len(char a[20])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    printf("the string length is %d",i);
}
int main() {
    char a[20];
    printf("enter the string \n");
    scanf("%s",a);
    str_len(a);

    return 0;
}
