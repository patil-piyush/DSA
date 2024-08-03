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

// simple function for finding min element of a linked list
int min(struct Node *p)
{
    int m = INT32_MAX;
    while (p)
    {
        if (p->data < m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}


// recursive function for finding min element of a linked list
int Rmin(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MAX;
    }
    x = Rmin(p->next);
    if (x < p->data)
    {
        return x;
    }
    else
    {
        return p->data;
    }
}

int main()
{
    int a[] = {10, 20, 30, 90, 50};
    create(a, 5);
    cout << "min is " << min(first) << endl;
    cout << "min is " << Rmin(first) << endl;
    return 0;
}