#include <stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("Queue is Full!!\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->rear == q->size)
        printf("Queue is Empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}


void display(struct Queue q){
    int i;
    for(i=q.front+1; i!=q.rear;i++){
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q, 7);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    display(q);

    dequeue(&q);
    display(q);
    return 0;
}