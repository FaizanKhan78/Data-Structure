#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *createLinkedList()
{
    int n;
    printf("PLease Enter How Many Nodes You Want :-");
    scanf("%d", &n);
    node *head = NULL;
    node *nextNode = NULL;
    node *temp = NULL;
    for (int i = 0; i < n; i++)
    {
        nextNode = (node *)malloc(sizeof(node));
        printf("Please Enter Data :-");
        scanf("%d", &(nextNode->data));
        nextNode->next = NULL;
        if (head == NULL)
        {
            head = temp = nextNode;
        }
        else
        {
            temp->next = nextNode;
            temp = nextNode;
        }
    }
    return head;
}

void traversal(node *top)
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
    traversal(top);
    return 0;
}