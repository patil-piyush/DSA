#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

// recurrsive version of inserting a node in BST
struct Node *RInsert(struct Node *t, int key)
{
    struct Node *p;
    if (t == NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return p; // Return the new node
    }
    if (key < t->data)
    {
        t->lchild = RInsert(t->lchild, key);
    }
    else if (key > t->data)
    { // Correctly handle right subtree
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

// recurrsive version of searching for a node in BST
struct Node *Rsearch(struct Node *t, int key)
{
    if (t == NULL)
        return NULL;
    if (t->data == key)
        return t;
    if (t->data > key)
        return Rsearch(t->lchild, key);
    if (t->data < key)
        return Rsearch(t->rchild, key);
}

// iterative version of searching for a node in BST
struct Node *search(struct Node *t, int key)
{
    while (t != NULL)
    {
        if (t->data == key)
            return t;
        if (t->data > key)
            t = t->lchild;
        if (t->data < key)
            t = t->rchild;
    }
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

int Height(struct Node *t){
    if(t!=NULL){
        int x = Height(t->lchild);
        int y = Height(t->rchild);
        if(x>y){
            return x+1;
        }
        return y+1;
    }
    return 0;
}

struct Node *InPre(struct Node *t){
    while(t && t->rchild){
        t = t->rchild;
    }
    return t;
}


struct Node *InSucc(struct Node *t){
    while(t && t->lchild){
        t = t->lchild;
    }
    return t;
}


struct Node *RDelete(struct Node *t, int key)
{
    struct Node *p;
    if (t==NULL)
        return NULL;
    //if t is leaf node
    if (t->lchild==NULL && t->rchild==NULL)
    {
        if (t == root)
            root = NULL;
        free(t);
        return NULL;
    }
    //if key < t->data  - use delete function for left subtree of t 
    if (key < t->data)
        t->lchild = RDelete(t->lchild, key);
    //if key > t->data  - use delete function for Right subtree of t
    else if (key > t->data)
        t->rchild = RDelete(t->rchild, key);
    // if key = t->data - 1)check the height
    //                    2)if height of left sbtree is greater than find predecessor and replace t->data with it
    //                    3)if predecessor node has childs - use delete function for left subtree of t
    //                                                     ELSE
    //                    4)if height of right sbtree is greater than find successor and replace t->data with it 
    //                    5)if successor node has childs - use delete function for right subtree of t
    else
    {
        if (Height(t->lchild) > Height(t->rchild))
        {
            p = InPre(t->lchild);
            t->data = p->data;
            t->lchild = RDelete(t->lchild, p->data);
        }
        else
        {
            p = InSucc(t->rchild);
            t->data = p->data;
            t->rchild = RDelete(t->rchild, p->data);
        }
    }
    return t;
}

int main()
{
    root = RInsert(root, 10);
    RInsert(root, 20);
    RInsert(root, 9);
    RInsert(root, 22);
    RInsert(root, 5);

    RDelete(root,2);
    struct Node *t = Rsearch(root, 222);
    if (t)
    {
        printf("key %d is found\n", t->data);
    }
    else
    {
        printf("key not found\n");
    }
    printf("\n");
    Inorder(root);
    return 0;
}