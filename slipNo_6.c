// Write a ‘C’ program to create singly Linked list and display it.

#include <stdio.h>
#include <stdlib.h>

typedef struct slipNo_6
{
    int data;
    struct slipNo_6 *next;
} node;

node *createLinkedList()
{
    int n;
    printf("PLease Enter Number Nodes You Want :- ");
    scanf("%d", &n);
    node *top = NULL;
    node *nextNode = NULL;
    node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        nextNode = (node *)malloc(sizeof(node));
        printf("Please Enter The Data For Node No. %d :- ", (i + 1));
        scanf("%d", &(nextNode->data));
        nextNode->next = NULL;
        if (top == NULL)
        {
            top = temp = nextNode;
        }
        else
        {
            temp->next = nextNode;
            temp = nextNode;
        }
    }
    return top;
}

void display(node *top)
{
    node *p = top;
    while (p != NULL)
    {
        printf("Element :- %d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    node *top = NULL;
    top = createLinkedList();
    display(top);
    return 0;
}