#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node * *)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node * x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full!!\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node * dequeue(struct Queue *q)
{
    struct Node * x = NULL;
    if (q->rear == q->front)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front==q.rear;
}

struct Node *root;

void TreeCreate(){
    int x;
    struct Node *t, *p;
    struct Queue q;
    create(&q,100);
    printf("Enter the value of root: ");
    scanf("%d",&x);
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->lchild = t->rchild = NULL;
    root = t;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        printf("Enter the value of left child of %d Node(-1 for no Node): ", p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        printf("Enter the value of Right child of %d Node(-1 for no Node): ", p->data);
        scanf("%d",&x);
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}


void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int main() {
    TreeCreate();
    preorder(root);
    printf("\npostorder: ");
    postorder(root);
    return 0;
}