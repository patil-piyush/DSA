// Reversing the linked list by swapping the data
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first, *second, *third;

void createfirst(int a[], int n)
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

void createsecond(int a[], int n)
{
    int i;
    struct Node *t, *last;
    second = new Node;
    second->data = a[0];
    second->next = 0;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = 0;
        last->next = t;
        last = t;
    }
}

// simple count function for counting nodes of a linked list
int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
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

// recursive display function for displaying linked list
void RDisplayLL(struct Node *p)
{
    if (p != 0)
    {
        cout << p->data << endl;
        RDisplayLL(p->next);
    }
}

// function for deleting a node
int DeleteNode(struct Node *p, int pos)
{
    Node *c, *q;
    int x = -1, i;
    if (pos < 1 || pos > count(p))
    {
        return -1;
    }
    if (pos == 1)
    {
        c = first;
        first = first->next;
        x = c->data;
        delete c;
        return x;
    }
    else
    {
        c = first;
        q = nullptr;

        for (i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

// Function for Merging two linked list
void MergeLL(struct Node *p, struct Node *q)
{
    Node *last;
    // comparing first node of two linked list and making it first node of merged list
    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    // merging all nodes after the first node
    while (first && second)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    // merging remaining nodes
    if (first)
        last->next = first;
    else
        last->next = second;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int b[] = {11, 22, 33, 44, 55, 66};
    createfirst(a, 5);
    createsecond(b, 5);

    MergeLL(first, second);
    DisplayLL(third);

    return 0;
}