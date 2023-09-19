// Write a ‘C’ program to create linked list with given number in which data part of each
// node contains individual digit of the number.
// (Ex. Suppose the number is 368 then the nodes of linked list should contain 3, 6, 8)

#include <stdio.h>
#include <stdlib.h>

typedef struct slipNo_8
{
    int data;
    struct slipNo_8 *next;
} node;

node *createLinkedList()
{
    int n;
    printf("PLease Enter Number Nodes You Want :- ");
    scanf("%d", &n);
    node *top = NULL;
    node *nextNode = NULL;
    node *temp = NULL;
    while (n > 0)
    {

        nextNode = (node *)malloc(sizeof(node));
        nextNode->data = n % 10;
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
        n = n / 10;
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