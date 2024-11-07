#include <stdio.h>
#define SIZE 5
typedef struct Queue
{
    int items[SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue *q)
{
    return (q->rear + 1) == SIZE;
}

int isEmpty(Queue *q)
{
    return q->front > q->rear;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("The queue is full");
        return;
    }

    q->items[++(q->rear)] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        return 0;
        printf("The queue is empty");
    }
    else
    {
        printf("What the sigman");
        return q->items[(q->front)++];
    }
}

void printQueue(Queue *q)
{
    printf("[");
    for (int i = q->front; i <= q->rear; i++)
    {
        if (i == q->rear)
        {
            printf("%d", q->items[i]);
        }
        else
        {
            printf("%d, ", q->items[i]);
        }
    }
    printf("]\n");
    printf("Front: %d, Rear: %d\n", q->front, q->rear);
}

int main(void)
{
    Queue q;
    init(&q);
    dequeue(&q); // Test underflow
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6); // Test overflow
    dequeue(&q);
    dequeue(&q);
    printQueue(&q);
}