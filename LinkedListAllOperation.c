//! Linked List.
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *first)
{
    struct Node *ptr = first;
    while (ptr != NULL)
    {
        printf("Element :- %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node *insertAtFirst(struct Node *first, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = first;
    return ptr;
}

struct Node *insertAtIndex(struct Node *first, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = first;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return first;
}

struct Node *insertAtEnd(struct Node *first, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = first;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return first;
}

struct Node *insertAtNode(struct Node *first, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = first;
    while (p->next != prevNode)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return first;
}

struct Node *deleteAtFirst(struct Node *first)
{
    struct Node *p = first;
    first = first->next;
    free(p);
    return first;
}

struct Node *deleteAtIndex(struct Node *first, int index)
{
    struct Node *p = first;
    struct Node *q = p->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    free(q);
    return first;
}

struct Node *deleteAtEnd(struct Node *first)
{
    struct Node *p = first;
    struct Node *q = p->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return first;
}

struct Node *deleteAtNode(struct Node *first, struct Node *prevNode)
{
    struct Node *p = first;
    struct Node *q = p->next;
    while (p->next != prevNode)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return first;
}

int main()
{
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    first->data = 5;
    first->next = second;

    second->data = 7;
    second->next = third;

    third->data = 10;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = NULL;

    traversal(first);
    //! Insertion.
    // first = insertAtFirst(first, 46);
    // first = insertAtIndex(first, 56, 2);
    // first = insertAtEnd(first, 56);
    // first = insertAtNode(first, third, 56);

    //! Deletion.
    // first = deleteAtFirst(first);
    // first = deleteAtIndex(first, 2);
    // first = deleteAtEnd(first);
    // first = deleteAtNode(first, third);
    traversal(first);
    return 0;
}