#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node
{
    struct Node *lchild; // Pointer to the left child
    int data;            // Data of the node
    struct Node *rchild; // Pointer to the right child
};

// Definition of a stack for tree traversal
struct stack
{
    int size;        // Maximum size of the stack
    int top;         // Index of the top element in the stack
    struct Node **s; // Array of pointers to nodes
};

// Function to create the stack
void createStack(struct stack *st, int ss)
{
    st->size = ss;                                                    // Set the size of the stack
    st->s = (struct Node **)malloc(st->size * sizeof(struct Node *)); // Allocate memory for the stack
    st->top = -1;                                                     // Initialize the top pointer to -1 (stack is empty)
}

// Function to check if the stack is empty
int Empty(struct stack st)
{
    return st.top == -1; // Returns 1 if the stack is empty, otherwise 0
}

// Function to check if the stack is full
int isFull(struct stack st)
{
    if (st.top == st.size - 1) // Check if the top index has reached the maximum size
        return 1;              // Stack is full
    return 0;                  // Stack is not full
}

// Function to push an element onto the stack
void push(struct stack *st, struct Node *x)
{
    if (isFull(*st))
    { // Check if the stack is full
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;          // Increment the top pointer
        st->s[st->top] = x; // Add the element to the stack
    }
}

// Function to pop an element from the stack
struct Node *pop(struct stack *st)
{
    struct Node *x = NULL; // Initialize the popped element
    if (Empty(*st))
    { // Check if the stack is empty
        printf("Stack underflow\n");
    }
    else
    {
        x = st->s[st->top]; // Get the top element
        st->top--;          // Decrement the top pointer
    }
    return x;
}

// Definition of a circular queue for tree creation
struct Queue
{
    int size;        // Maximum size of the queue
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    struct Node **Q; // Array of pointers to nodes
};

// Function to create the queue
void create(struct Queue *q, int size)
{
    q->size = size;                                                 // Set the size of the queue
    q->front = q->rear = 0;                                         // Initialize the front and rear pointers to 0
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *)); // Allocate memory for the queue
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    { // Check if the queue is full
        printf("Queue is Full!!\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size; // Increment the rear pointer in a circular manner
        q->Q[q->rear] = x;                 // Add the element to the queue
    }
}

// Function to dequeue an element from the queue
struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL; // Initialize the dequeued element
    if (q->rear == q->front)
    { // Check if the queue is empty
        printf("Queue is Empty\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size; // Increment the front pointer in a circular manner
        x = q->Q[q->front];                  // Get the front element
    }
    return x;
}

// Function to check if the queue is empty
int isEmpty(struct Queue q)
{
    return q.front == q.rear; // Returns 1 if the queue is empty, otherwise 0
}

// Root node of the binary tree
struct Node *root;

// Function to create the binary tree
void TreeCreate()
{
    int x;
    struct Node *t, *p;
    struct Queue q;
    create(&q, 100); // Initialize the queue with a size of 100

    // Create the root node
    printf("Enter the value of root: ");
    scanf("%d", &x);
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->lchild = t->rchild = NULL;
    root = t;
    enqueue(&q, root); // Enqueue the root node

    // Loop to create the tree level by level
    while (!isEmpty(q))
    {
        p = dequeue(&q); // Dequeue a node
        printf("Enter the value of left child of %d Node(-1 for no Node): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;  // Assign left child
            enqueue(&q, t); // Enqueue the left child
        }
        printf("Enter the value of Right child of %d Node(-1 for no Node): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;  // Assign right child
            enqueue(&q, t); // Enqueue the right child
        }
    }
}

// Iterative preorder traversal of the binary tree
void Ipreorder(struct Node *p)
{
    struct stack st;
    createStack(&st, 100); // Create a stack with a size of 100
    while (p || !Empty(st))
    {
        if (p)
        {
            printf("%d ", p->data); // Print the node data
            push(&st, p);           // Push the node onto the stack
            p = p->lchild;          // Move to the left child
        }
        else
        {
            p = pop(&st);  // Pop a node from the stack
            p = p->rchild; // Move to the right child
        }
    }
}

// Iterative inorder traversal of the binary tree
void IInorder(struct Node *p)
{
    struct stack st;
    createStack(&st, 100); // Create a stack with a size of 100
    while (p || !Empty(st))
    {
        if (p)
        {
            push(&st, p);  // Push the node onto the stack
            p = p->lchild; // Move to the left child
        }
        else
        {
            p = pop(&st);           // Pop a node from the stack
            printf("%d ", p->data); // Print the node data
            p = p->rchild;          // Move to the right child
        }
    }
}

// void Ipostorder(struct Node *p) {
//     struct stack st;
//     createStack(&st, 100);

//     struct Node *lastVisited = NULL; // Pointer to track the last visited node
//     while (p || !Empty(st)) {
//         if (p) {
//             push(&st, p);
//             p = p->lchild; // Traverse the left subtree
//         } else {
//             struct Node *peekNode = stackTop(st);
//             // Check if the right child exists and is not processed
//             if (peekNode->rchild && lastVisited != peekNode->rchild) {
//                 p = peekNode->rchild; // Move to the right subtree
//             } else {
//                 printf("%d ", peekNode->data); // Process the node
//                 lastVisited = pop(&st);       // Mark it as visited
//                 p = NULL;                     // Reset to avoid reprocessing
//             }
//         }
//     }
// }

// Main function
int main()
{
    TreeCreate(); // Create the binary tree
    printf("\npreorder: ");
    Ipreorder(root); // Perform preorder traversal
    printf("\nInorder: ");
    IInorder(root); // Perform inorder traversal
    // printf("\npostorder: ");
    // Ipostorder(root);
    return 0;
}
