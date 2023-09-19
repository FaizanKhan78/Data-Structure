#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
} queue;

int isEmpty(queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue OverFlow \n");
    }
    else
    {
        q->arr[++q->r] = data;
    }
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Empty\n");
    }
    else
    {
        return q->arr[++q->f];
    }
}

int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->f = q->r = -1;
    q->size = 4;
    q->arr = (int *)malloc(sizeof(int) * q->size);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    return 0;
}