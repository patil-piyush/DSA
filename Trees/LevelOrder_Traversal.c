#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node
{
    struct Node *lchild; // Pointer to the left child
    int data;            // Data of the node
    struct Node *rchild; // Pointer to the right child
};

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
    int x;              // Variable to store user input for node values
    struct Node *t, *p; // Temporary pointers for new nodes and processing
    struct Queue q;     // Queue for level-order tree construction
    create(&q, 100);    // Initialize the queue with a size of 100

    // Create the root node
    printf("Enter the value of root: ");
    scanf("%d", &x);
    t = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the root node
    t->data = x;                                    // Set the root node's data
    t->lchild = t->rchild = NULL;                   // Initialize the children as NULL
    root = t;                                       // Assign the root node
    enqueue(&q, root);                              // Enqueue the root node

    // Loop to create the tree level by level
    while (!isEmpty(q))
    {
        p = dequeue(&q); // Dequeue a node
        // Process the left child
        printf("Enter the value of left child of %d Node(-1 for no Node): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {                                                   // If input is not -1, create a left child
            t = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the left child
            t->data = x;                                    // Set the left child's data
            t->lchild = t->rchild = NULL;                   // Initialize the children as NULL
            p->lchild = t;                                  // Assign the left child
            enqueue(&q, t);                                 // Enqueue the left child
        }
        // Process the right child
        printf("Enter the value of Right child of %d Node(-1 for no Node): ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {                                                   // If input is not -1, create a right child
            t = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for the right child
            t->data = x;                                    // Set the right child's data
            t->lchild = t->rchild = NULL;                   // Initialize the children as NULL
            p->rchild = t;                                  // Assign the right child
            enqueue(&q, t);                                 // Enqueue the right child
        }
    }
}

// Recursive preorder traversal of the binary tree
void preorder(struct Node *p)
{
    if (p)
    {                           // Base condition: process only if node is not NULL
        printf("%d ", p->data); // Print the node's data
        preorder(p->lchild);    // Traverse the left subtree
        preorder(p->rchild);    // Traverse the right subtree
    }
}

// Recursive inorder traversal of the binary tree
void Inorder(struct Node *p)
{
    if (p)
    {                           // Base condition: process only if node is not NULL
        Inorder(p->lchild);     // Traverse the left subtree
        printf("%d ", p->data); // Print the node's data
        Inorder(p->rchild);     // Traverse the right subtree
    }
}

// Recursive postorder traversal of the binary tree
void postorder(struct Node *p)
{
    if (p)
    {                           // Base condition: process only if node is not NULL
        postorder(p->lchild);   // Traverse the left subtree
        postorder(p->rchild);   // Traverse the right subtree
        printf("%d ", p->data); // Print the node's data
    }
}

//Level Order traversal of the binary tree
void LevelOrder(struct Node *root){
    struct Queue q;
    create(&q,100);
    printf("%d ",root->data);
    enqueue(&q,root);
    while(!isEmpty(q)){
        root = dequeue(&q);
        if(root->lchild){
            printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild){
            printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }
    }
}

// Main function
int main()
{
    TreeCreate(); // Create the binary tree
    printf("\nLevelorder: ");
    LevelOrder(root);
    return 0;
}
