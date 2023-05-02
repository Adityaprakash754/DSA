//polynomial addition using a cll with node by deleting the node after it has been  copied to result
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

void read_poly(P p1,int n)
{
    P temp;
    int i;
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

P compare(P term,P p2)
{
    P cur;
    cur=p2->link;
    while(cur!=p2)
    {
        if(cur->px==term->px &&cur->py==term->py &&cur->pz==term->pz)
            return cur;
        
        cur=cur->link;
    }
    return NULL;
}
void delete(P p,P term)
{
    P prev,cur,next;
    prev=p;
    cur=p->link;
    next=cur->link;
    while(cur!=term)
    {
        prev=cur;
        cur=cur->link;
        next=cur->link;
    }
    prev->link=next;
    free(cur);
}
void addPoly(P p1,P p2,P res)
{
    P res_pos;
    P term=p1->link;
    while(term!=p1)
    {
        res_pos=compare(term,p2);
        if(res_pos!=NULL){
        insert(res,term->cf+res_pos->cf,term->px,term->py,term->pz);
        delete(p2,res_pos);
        }
        else
            insert(res,term->cf,term->px,term->py,term->pz);
        
        delete(p1,term);
        
        term=p1->link;
    }
    term=p2->link;
    while(term!=p2)
    {
        insert(res,term->cf,term->px,term->py,term->pz);
        
        delete(p2,term);
        term=p2->link;
    }
    printf("After addition of the polynomial:\n");
    
    display(res);
}
int main() {
    
    int n,m;
    P p1,p2,res;
    p1=getnode();
    p1->link=p1;
    printf("Enter the terms of poly p1\n");
    scanf("%d",&n);
    read_poly(p1,n);
    display(p1);
    
    p2=getnode();
    p2->link=p2;
    printf("Enter the terms of poly p2\n");
    scanf("%d",&m);
    read_poly(p2,m);
    display(p2);
    
    res=getnode();
    res->link=res;
    
    addPoly(p1,p2,res);
    display(p1);
    display(p2);
    return 0;
}