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
Node *search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        else
        {
            p = p->next;
        }
    }
    return NULL;
}

// recursive function for linear search in a linked list
Node *Rsearch(struct Node *p, int key)
{
    if (p == 0)
    {
        return NULL;
    }
    else if (key == p->data)
    {
        return p;
    }
    else
    {
        return Rsearch(p->next, key);
    }
}

// improved linear search by using move to head method
Node *ImpSearch(Node *p, int key)
{
    Node *q = NULL;
    while (p != 0)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        else
        {
            q = p;
            p = p->next;
        }
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

int main()
{
    int a[] = {10, 20, 30, 90, 50};
    create(a, 5);
    Node *Temp;
    Temp = ImpSearch(first, 50);
    if (Temp)
    {
        cout << "Element is present " << endl;
    }
    else
    {
        cout << "Element is not present " << endl;
    }
    DisplayLL(first);
    return 0;
}