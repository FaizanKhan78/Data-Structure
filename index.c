#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *createTree()
{
    int x;
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    printf("Enter Data (-1 for No Node) :- ");
    scanf("%d", &x);
    printf("\n");
    if (x == -1)
    {
        return NULL;
    }
    newNode->data = x;
    printf("Enter Left Child For %d\n", x);
    newNode->left = createTree();
    printf("Enter Right Child For %d\n", x);
    newNode->right = createTree();
    return newNode;
}

void preOrder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        printf("%d ", root->data);
        postOrder(root->right);
    }
}

int isBST(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    return 1;
}

int main()
{
    node *root = NULL;
    root = createTree();
    // preOrder(root);
    // printf("\n");
    // postOrder(root);
    // printf("\n");
    inOrder(root);
    printf("\n");
    printf("%d\n", isBST(root));
    return 0;
}