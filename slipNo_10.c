// Write a ‘C’ program to create a singly linked list and count total number of nodes in it
// and display the list and total number of Nodes.
#include <stdio.h>
#include <stdlib.h>

typedef struct slipNo_10
{
    int data;
    struct slipNo_10 *next;
} node;

node *createLinkedList()
{
    int n;
    node *temp = NULL;
    node *head = NULL;
    node *newNode = NULL;
    printf("Please Enter The Nodes You Want :- ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        newNode = (node *)malloc(sizeof(node));
        printf("Please Enter The Data for Node %d :- ", (i + 1));
        scanf("%d", &(newNode->data));
        newNode->next = NULL;
        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void traversal(node *head)
{
    printf("\n");
    node *p = head;
    int count = 0;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        count++;
        p = p->next;
    }
    printf("Total Number Of Nodes Are %d", count);
    printf("\n");
}

int main()
{
    node *top = NULL;
    top = createLinkedList();
    traversal(top);
    return 0;
}