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

// simple function for counting sum of elements of a linked list
int sum(struct Node *p)
{
    int s = 0;
    while (p)
    {
        s = s + p->data;
        p = p->next;
    }
    return s;
}

// recursive function for counting sum of elements of a linked list
int Rsum(struct Node *p)
{
    if (p != 0)
    {
        return Rsum(p->next) + p->data;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    cout << "sum is " << sum(first) << endl;
    cout << "sum is " << Rsum(first) << endl;
    return 0;
}