// Search and replace a string initial method 

#include <stdio.h>
//we are returning an array here
int *check_sub_str(char *ms, char *ss,int *n,int *a,int *b)
{
    int i,j,c,*pos;
    for(i=0;ms[i]!='\0';i++);
    for(j=0;ss[j]!='\0';j++);
    *a=i;
    *b=j;
    for(i=0;i<*a;i++)
    {
        int q=1;
        if(ss[0]==ms[i])
        {
            c=i+1;
           for(j=1;j<*b;j++)
           {
               if(ss[j]==ms[c])
               {
                    c++;
                    q++;
               }
               else
               break;
               
           }
           if(q==*b)
            {
                pos[(*n)]=i;
                (*n)++;
            }
        }
        
        
    }
    return pos;
}
void replace(char ms[20],int *pos,int a,int z)
{
    int i,j=0,c=0,b;
    char ns[40];
    char s1[20];
    printf("Enter string to replace with \n");
    scanf(" %s",s1);
    for(b=0;s1[b]!='\0';b++);
    
    for(i=0;i<a;i++)
    {
        if(i==pos[j])
        {
            for(int k=0;k<b;k++)
            {
                ns[c]=s1[k];
                c++;
            }
            j++;
            i=i+z;
            if(ms[i]==' ')
            {
                ns[c]=' ';
                c++;  
            }
            else
            i--;
        }
        else
        {
            ns[c]=ms[i];
            c++;
        }
    }
    ns[c]='\0';
    printf("%s",ns);
}
int main() {
    
    char ms[20];
    char ss[10];
    int n=0,a,b;
    printf("enter ms and ss\n");
    scanf(" %[^\n] %[^\n]",ms,ss);
   
    int *pos;
    printf("\n");
    pos=check_sub_str(ms,ss,&n,&a,&b);
    
    
    for(int i=0;i<n;i++)
    printf("It is at %d \n",pos[i]);
    
    replace(ms,pos,a,b);
    return 0;
}
