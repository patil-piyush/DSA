#include <stdio.h>

struct Node {
    struct Node* lchild;
    int data;
    int height;
    struct Node* rchild;
}*root = NULL;


//function for calculating the height for a node 
int NodeHeight(struct Node* p){
    int hl,hr;
    if(p && p->lchild)
        hl = p->lchild->height;
    else hl = 0;

    if(p && p->rchild)
        hr = p->rchild->height;
    else hr = 0;

    if(hl>hr) return hl+1;
    else return hr+1;
}


//function for calculating balance factor
int BalanceFactor(struct Node* p){
    int hl,hr;
    if(p && p->lchild)
        hl = p->lchild->height;
    else hl = 0;

    if(p && p->rchild)
        hr = p->rchild->height;
    else hr = 0;
    
    return hl-hr;
}


//functions for rotations
struct Node* LLRotation(struct Node* p){
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;
    return pl;
}

struct Node* LRRotation(struct Node* p){
    struct Node* pl = p->lchild;
    struct Node* plr = pl->rchild;

    pl->rchild = plr->rchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;
    return plr;
}

struct Node* RRRotation(struct Node* p){
    struct Node* pr = p->rchild;
    struct Node*prl = pr->lchild;

    pr->lchild = p;
    p->lchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root == p)
        root = pr;
    return pr;
}

struct Node* RLRotation(struct Node* p){
    struct Node* pr = p->rchild;
    struct Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->lchild = prl->lchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if(root == p)
        root = prl;
    return prl;
}

struct Node* Insert(struct Node* p, int key){
    struct Node* t;
    if(p==NULL){
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if(key< p->data)
        p->lchild = Insert(p->lchild, key);
    else if(key > p->data)
        p->rchild = Insert(p->rchild, key);
    else if(key == p->data)
        return NULL;
    
    p->height = NodeHeight(p);
    
    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p);
    else if(BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);
    return p;
}

int main() {
    
    return 0;
}