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


// simple display function for displaying linked list
void DisplayLL(struct Node *p)
{
    while (p != 0)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

void SortedInsert(struct Node *p, int x){
    struct Node *t,*q;
    q=NULL;

    t = new Node;
    t->data=x;
    t->next=NULL;

    while(p && p->data<x){

    }
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    create(a, 7);

    SortedInsert(first, 0);
    DisplayLL(first);
    return 0;
}