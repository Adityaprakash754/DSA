//polynomial addition using a cll with node method 1


#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int cf,px,py,pz;
    struct poly *link;
};
typedef struct poly * P;

P getnode()
{
    P temp;
    temp=(P)malloc(sizeof(struct poly));
    if(temp==NULL)
    {
        printf("Memory isn't allocated \n");
        exit(0);
    }
    return temp;
}

P accept()
{
    P temp;
    temp=getnode();
    temp->link=temp;
    return temp;
}
void read_poly(P p1)
{
    P temp;
    int i,n;
    printf("Enter the no of terms of polynomial\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=getnode();
        printf("Enter the cf,px,py,pz\n");
        scanf("%d%d%d%d",&(temp->cf),&(temp->px),&(temp->py),&(temp->pz));
        temp->link=p1->link;
        p1->link=temp;
    }
}
void display(P head)
{
    P cur;
    printf("Elements of polynomial\n");
    cur=head->link;
    if(cur==head)
    {
        printf("Nothing to display\n");
        return;
    }
    while(cur!=head)
    {
        if(cur->cf>=0)
        printf("+%dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
        else
        printf("%dx^%dy^%dz^%d",cur->cf,cur->px,cur->py,cur->pz);
        
        cur=cur->link;
    }
    printf("\n");
}
void insert(P res,int cf,int px,int py,int pz)
{
    P temp;
    temp=getnode();
    temp->cf=cf;
    temp->px=px;
    temp->py=py;
    temp->pz=pz;
    temp->link=res->link;
    res->link=temp; 
}

void polyAdd(P p1,P p2)
{
    P res,cur,cur1,temp;
    res=accept();
    cur=p1->link;
    
    while(cur!=p1)
    {
        cur1=p2->link;
        while(cur1!=p2)
        {
            if(cur->px==cur1->px &&cur->py==cur1->py &&cur->pz==cur1->pz)
            {
                insert(res,cur->cf+cur1->cf,cur->px,cur->py,cur->pz);
                cur1->cf=-999;
                break;
            }
            cur1=cur1->link;
        }
        if(cur1==p2)
        insert(res,cur->cf,cur->px,cur->py,cur->pz);
        
        cur=cur->link;
    }
    
    cur1=p2->link;
    while(cur1!=p2)
    {
        if(cur1->cf!=-999)
        {
            insert(res,cur1->cf,cur1->px,cur1->py,cur1->pz);
        }
        cur1=cur1->link;
    }
    
    display(res);
}

int main() {
    
    P p1,p2;
    p1=accept();
    read_poly(p1);
    display(p1);
    
    p2=accept();
    read_poly(p2);
    display(p2);
    
    polyAdd(p1,p2);
    return 0;
}
