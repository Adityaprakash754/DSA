// Recursive C program for level order insertion and traversal of Binary Tree

#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */

struct node {
    int info;
    struct node *llink, *rlink;
};

typedef  struct node* NODE;
 /* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

NODE getNode(int info)
{
    NODE x = (NODE)malloc(sizeof(struct node));

    x->info = info;
    x->llink = x->rlink = NULL;
    
    return (x);
}

// Function to insert nodes in level order 

NODE insertLevelOrder(int arr[], int i, int n) 
{ 
      NODE temp = NULL; 
    // Base case for recursion 
    if (i < n) 
    { 
        temp = getNode(arr[i]); 
        // insert left child 
        temp->llink = insertLevelOrder(arr, 2 * i + 1, n); 
        // insert right child 
        temp->rlink = insertLevelOrder(arr, 2 * i + 2, n); 
    } 
    return temp; 
} 

/* Print nodes at a current level */

void printCurrentLevel(NODE root, int level)
{
    if (root == NULL)
        return;

    if (level == 1)
        printf("%d ", root->info);

    else if (level > 1) {
        printCurrentLevel(root->llink, level - 1);
        printCurrentLevel(root->rlink, level - 1);
    }
}
 
/* Function to print level order traversal a tree*/

void printLevelOrder(NODE root,int n)
{
    int h=0;
    int j=1;
    while(j<=n)
    {
        j*=2;
        h++;
    }
    int i;
    for (i = 1; i <= h; i++)

        printCurrentLevel(root, i);
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = 7; 
    NODE root = insertLevelOrder(arr, 0, n); 
    
    printf("Level Order traversal of binary tree is \n");
    printLevelOrder(root,n);
    
    return 0;
}