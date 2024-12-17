#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node()
    {
        rchild = lchild = NULL;
    }
};
class queue
{
    int size;
    int rear;
    int front;
    Node **a;

public:
    queue()
    {
        size = 10;
        rear = front = -1;
        a = new Node *[size];
    }
    queue(int s)
    {
        size = s;
        rear = front = -1;
        a = new Node *[size];
    }
    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty();
    void display();
};

void queue::enqueue(Node *x)
{
    if (rear == size - 1)
        cout << "queue is full\n";
    else
    {
        rear++;
        a[rear] = x;
    }
}

Node *queue::dequeue()
{
    Node *x = NULL;
    if (front == rear)
        cout << "Queue is Empty!!\n";
    else
    {
        front++;
        x = a[front];
    }
    return x;
}

int queue::isEmpty()
{
    return front == rear;
}

class Tree
{
public:
    Node *root;
    Tree() { root = NULL; }
    Tree(int s)
    {
        root->data = s;
        root->lchild = root->rchild = NULL;
    }
    void CreateTree();
    void preorder(Node *p);
    void postorder(Node *p);
    void Inorder(Node *p);
    void LevelOrder(Node *root);
    int count(Node *p);
    int height(Node *p);
};

void Tree::CreateTree()
{
    int x;
    Node *t, *p;
    queue q(100);
    cout << "Enter the value of root: ";
    cin >> x;
    t = new Node;
    t->data = x;
    t->lchild = t->rchild = NULL;
    root = t;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter the value of left child of " << p->data << " Node(-1 for no Node): ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter the value of Right child of " << p->data << " Node(-1 for no Node): ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

// Level Order traversal of the binary tree
void Tree::LevelOrder(Node *root)
{
    queue q(100);
    printf("%d ", root->data);
    q.enqueue(root);
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
}

// function for counting the Nodes
int Tree::count(Node *p)
{
    if (p)
        return count(p->lchild) + count(p->rchild) + 1;
    return 0;
}

// function for counting Height of the tree
int Tree::height(Node *p)
{
    int x = -1, y = -1;
    if (p == 0)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
    return 0;
}

int main()
{
    Tree t;
    t.CreateTree();
    cout << "\nPreOrder: ";
    t.preorder(t.root);
    cout << "\nInOrder: ";
    t.Inorder(t.root);
    cout << "\nPostOrder: ";
    t.postorder(t.root);
    cout << endl;
    return 0;
}