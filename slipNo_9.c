// Write a menu driven program using ‘C’ for singly linked list-
// - To create linked list.
// - To display linked list
// - Insert at last position

#include <stdio.h>
#include <stdlib.h>

typedef struct slipNo_9
{
    int data;
    struct slipNo_9 *next;
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
    do
    {
        printf("%d\n", p->data);
        p = p->next;
    } while (p != NULL);
    printf("\n");
}

node *insertAtEnd(node *first)
{
    int data;
    printf("Please Enter The Data :- ");
    scanf("%d", &data);
    node *ptr = (node *)malloc(sizeof(node));
    node *p = first;
    ptr->data = data;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return first;
}

int main()
{
    node *top = NULL;
    int choice;
    do
    {
        printf("Please Enter the Your Choice\n");
        printf("Enter 1 for Create Linked List\n");
        printf("Enter 2 for Display Linked List\n");
        printf("Enter 3 for Insert at last position\n");
        printf("Enter 4 for Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            top = createLinkedList();
            break;
        case 2:
            traversal(top);
            break;
        case 3:
            top = insertAtEnd(top);
            printf("After Insertion\n");
            traversal(top);
            break;

        case 4:
            exit(1);

        default:
            printf("Please Enter Valid Input\n");
            break;
        }
    } while (choice != 4);
    return 0;
}