#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * llink;
    int info;
    struct node * rlink;
};
typedef struct node * NODE;

NODE getNode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory isn't allocated\n");
        exit(0);
    }

    return x;
}

NODE insert_bst(NODE root,int info)
{
    NODE temp;
    temp=getNode();
    temp->info=info;
    temp->llink=temp->rlink=NULL;

    if(root==NULL)
    return temp;

    NODE prev,cur;
    cur=root;
    while(cur!=NULL)
    {
        prev=cur;

        if(info < cur->info)
        cur=cur->llink;
        else
        cur=cur->rlink;
    }

    if(info < prev->info)
    prev->llink=temp;
    else
    prev->rlink=temp;

    return root;
}

void preorder(NODE root)
{
    if(root==NULL)
    return;

    printf("%d ",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
void postorder(NODE root)
{
    if(root==NULL)
    return;

    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ",root->info);
}
void inorder(NODE root)
{
    if(root==NULL)
    return;

    inorder(root->llink);
    printf("%d ",root->info);
    inorder(root->rlink);
}
int main()
{
    NODE root=NULL;
    int ch,item;
    
    while(1)
    {
        printf("Enter 1:insert 2:preorder 3:inorder 4:postorder\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:
            printf("Enter the elem\n");
            scanf("%d",&item);
            root=insert_bst(root,item);
            break;
            
            case 2:
            printf("preorder\n");
            preorder(root);
            printf("\n");
            break;
            
            case 3:
            printf("\ninorder\n");
            inorder(root);
            printf("\n");
            break;
            
            case 4:
            printf("\npostorder\n");
            postorder(root);
            printf("\n");
            break;
            
            default:
            exit(0);
        }
    }
}