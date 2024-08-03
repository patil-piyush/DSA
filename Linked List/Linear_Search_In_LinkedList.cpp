#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = 0;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}

// simple function for linear search in a linked list
Node* search(struct Node *p,int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        else{
            p=p->next;
        }
    }
    return NULL;
}



int main()
{
    int a[] = {10, 20, 30, 90, 50};
    create(a, 5);
    cout << "Element is at " << search(first,40) << endl;
    // cout << "Element is at " << Rsearch(first,40) << endl;
    return 0;
}