#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
    bool lthread;
    bool rthread;
} *root = NULL;

struct Node *Insert(struct Node *root, int key)
{
    Node *t = root;
    Node *p;
    Node *r = NULL;

    if (t == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        p->lthread = p->rthread = false;
        root = p;
        return root;
    }

    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            if (t->lthread == false)
                t = t->lchild;
            else
                break;
        }
        else if(key > t->data){
            if(t->rthread == false)
                t= t->rchild;
            else break;
        }
        else return root;
    }

    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    p->lthread = p->rthread = true;
    if(key < r->data){
        p->lchild = r->lchild;
        p->rchild = r;
        r->lchild = p;
        r->lthread = false;
    }
    else{
        p->rchild = r->rchild;
        p->lchild = r;
        r->rchild = p;
        r->rthread = false;
    }
    return root;
}

int main()
{

    return 0;
}