#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

// recurrsive version of inserting a node in BST
struct Node *RInsert(struct Node *t, int key) {
    struct Node *p;
    if (t == NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p; // Return the new node
    }
    if (key < t->data) {
        t->lchild = RInsert(t->lchild, key);
    } else if (key > t->data) { // Correctly handle right subtree
        t->rchild = RInsert(t->rchild, key);
    }
    return t; // Return the unchanged node
}
// iterative version of inserting a node in BST
void Insert(int key)
{
    struct Node *p, *r, *t;
    t = root;
    r = NULL;
    if (t == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (t->data == key)
            return;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (r->data > key)
        r->lchild = p;
    else
        r->rchild = p;
}


// recursive function for inorder traversal
void Inorder(struct Node *t)
{
    if (t != NULL)
    {
        Inorder(t->lchild);
        printf("%d ", t->data);
        Inorder(t->rchild);
    }
}

int main()
{
    root = RInsert(root, 10); 
    root = RInsert(root, 20);
    root = RInsert(root, 9);
    root = RInsert(root, 22);
    root = RInsert(root, 5);
    
    Inorder(root);
    return 0;
}