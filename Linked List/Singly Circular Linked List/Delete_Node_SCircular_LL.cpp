#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *Head;

void create(int a[], int n)
{
    int i;
    Node *t, *last;
    Head = new Node;
    Head->data = a[0];
    Head->next = nullptr;
    Head->next = last = Head;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != Head);
    cout << endl;
}

void RDisplay(struct Node *p)
{
    static int flag = 0;
    if (p != Head || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        RDisplay(p->next);
    }
    flag = 0;
}

int count(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > count(p))
        return;

    Node *t;
    int i;
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        while (p->next != Head)
            p = p->next;
        if (Head == p)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            t->next = p->next;
            p->next = t;
            Head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    if (index < 1 || index > count(p))
        return -1;

    int i=0,x;
    Node *q;
    if (index == 1)
    {
        while (p->next != Head)
            p = p->next;
        p->next = Head->next;
        x=Head->data;
        delete Head;
        Head = p->next;
    }
    else
    {
        for(i=0;i<index-2;i++){
            p = p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);

    Display(Head);
    cout<<Delete(Head, 1);
    cout<<endl;
    RDisplay(Head);
    cout << endl;
    return 0;
}