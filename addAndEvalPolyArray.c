// addition and evaluation of polynomial using arrays
#include<stdio.h>
#include<math.h>
#define pf printf
#define sf scanf
typedef struct poly
{
    int cf;
    int ex;
} p;

void accept (p p1[10],int *n)
{
    int i;
    pf("no of pol\n");
    sf("%d",n);
    for(i=0;i<*n;i++)
    {
        pf("element %d\n",i+1);
        sf("%d %d",&p1[i].cf,&p1[i].ex);
    }
    
}

void display(p p1[20],int n)
{
    for(int i=0;i<n;i++)
    {
        if(p1[i].cf>0)
            pf("+%dx^%d",p1[i].cf,p1[i].ex);
        else
            pf("%dx^%d",p1[i].cf,p1[i].ex);
    }
    pf("\n");
}

int add(p p1[10],p p2[10],p res[20],int n1,int n2)
{
    int i,j,k=0;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            if(p1[i].ex==p2[j].ex)
            {
                res[k].cf=p1[i].cf+p2[j].cf;
                res[k].ex=p1[i].ex;
                k++;
                p2[j].cf=-999;
                break;
            }
        }
            if(j==n2)
            {
                res[k]=p1[i];
                k++;
            }
        
    }
    for(i=0;i<n2;i++)
    {
        if(p2[i].cf!=-999)
        {
           res[k]=p2[i];
                k++; 
        }
    }
    return k;
}
void eval(p p1[10],int n)
{
    int x;
    pf("x\n");
    sf("%d",&x);
    int i,res=0;
    for(i=0;i<n;i++)
    res+=p1[i].cf*pow(x,p1[i].ex);
    
    pf("%d",res);
}
 int main()
 {
     p p1[10],p2[10],res[20];
     int n1,n2,n3;
     accept(p1,&n1);
     display(p1,n1);
     accept(p2,&n2);
     display(p2,n2);
     n3=add(p1,p2,res,n1,n2);
     display(res,n3);
     eval(p1,n1);
 } 
