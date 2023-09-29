#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int data;
    struct Stack *next;
} stack;

int isFull(stack *sp)
{
    stack *p = (stack *)malloc(sizeof(stack));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(stack *sp)
{
    if (sp == NULL)
    {
        return 1;
    }
    return 0;
}

stack *push(stack *top, int data)
{
    if (isFull(top))
    {
        printf("stack overflow\n");
    }
    else
    {
        stack *n = (stack *)malloc(sizeof(stack));
        n->data = data;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(stack **top)
{
    int x = -1;
    if (isEmpty(*top))
    {
        printf("Stack UnderFlow\n");
        return x;
    }
    else
    {
        stack *p = *top;
        x = p->data;
        *top = (*top)->next;
        free(p);
        return x;
    }
}

void linkedListTraversal(stack *top)
{
    stack *p = top;
    while (p != NULL)
    {
        printf("ELement :- %d\n", p->data);
        p = p->next;
    }
    printf("\n");
}

int peek(stack *top, int position)
{
    stack *p = top;
    for (int i = 0; (i < position - 1 && p != NULL); i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        return p->data;
    }
    else
    {
        return 1;
    }
}

int main()
{
    stack *top = NULL;
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    // linkedListTraversal(top);
    // printf("Pop Element %d\n", pop(&top));
    // printf("Pop Element %d\n", pop(&top));
    // printf("Pop Element %d\n", pop(&top));
    for (int i = 1; i <= 3; i++)
    {
        printf("Element %d was At Index No. %d \n", peek(top, i), i);
    }
    return 0;
}