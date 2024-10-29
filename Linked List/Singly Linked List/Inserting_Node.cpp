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

// Insert function for inserting a node in a linked list
int Insert(struct Node *p, int index, int x)
{
    struct Node *t;

    if (index < 0 || index > count(p))
        return 0;
    t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1 && p; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    create(a, 7);

    Insert(first, 0, 33);
    DisplayLL(first);
    return 0;
}