//Search and replace the string
#include <stdio.h>
#include <string.h>
int pattern_match(char ps[20],char T[20],int t_pos)
{
    int n1=strlen(ps);
    for(int i=0;i<n1;i++,t_pos++)
    {
        if(ps[i]!=T[t_pos])
        return 1;
    }
    return 0;
}

int cpy_str_match(char os[20],char rs[20],int os_pos)
{
    for(int i=0;rs[i]!='\0';i++,os_pos++)
    {
        os[os_pos]=rs[i];
    }
    return os_pos;
}
int main() {
   char T[20],ps[20],rs[20];
    printf("Enter the Test string\n");
    scanf("%[^\n]",T);
    printf("Enter the pattern string to replace\n");
    scanf("%s",ps);
    printf("Enter the string to replace with \n");
    scanf("%s",rs);
    
    char os[20];
    int os_pos=0;
    
    for(int i=0;T[i]!='\0';i++)
    {
        if(pattern_match(ps,T,i)==0)
        {
            os_pos= cpy_str_match(os,rs,os_pos);
            i=i+strlen(ps)-1;
        }
        else
        {
            os[os_pos]=T[i];
            os_pos++;
        }
    }
    os[os_pos]='\0';
    printf("%s\n",os);
    return 0;
}
