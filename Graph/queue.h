#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;

    Queue() { front = rear = NULL; }

    void enqueue(int x) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        if (t == NULL) {
            printf("Queue is Full\n");
            return;
        }
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }

    int dequeue() {
        if (front == NULL) {
            printf("Queue is Empty!\n");
            return -1;
        }
        struct Node *t = front;
        front = front->next;
        int x = t->data;
        free(t);
        return x;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void display() {
        struct Node *t = front;
        while (t) {
            printf("%d ", t->data);
            t = t->next;
        }
        printf("\n");
    }
};

#endif /*Queue_h*/
