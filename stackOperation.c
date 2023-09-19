#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;
} stack;

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("Stack is Full\n");
        return 1;
    }
    return 0;
}

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Stack is Empty\n");
        return 1;
    }
    return 0;
}

void push(stack *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("Cannot insert Element %d\n", element);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        return 1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(stack *ptr, int i)
{
    int arrayIndex = ptr->top - i + 1;
    if (arrayIndex < 0)
    {
        printf("Not A Valid Position\n");
        return 1;
    }
    else
    {
        return ptr->arr[arrayIndex];
    }
}

int main()
{
    stack *sp = (stack *)malloc(sizeof(stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sizeof(int) * sp->size);
    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    push(sp, 5);
    push(sp, 6);
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("Element %d is at Position No %d\n", peek(sp, j), j);
    }
    free(sp);
    return 0;
}