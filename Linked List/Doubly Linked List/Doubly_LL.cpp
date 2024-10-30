#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
} *head;

void create(struct Node *p, int a[], int n)
{
    Node *t, *last;
    t = new Node;
    t->data = a[0];
    t->prev = nullptr;
    t->next = nullptr;
    head = last = t;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->prev = last;
        last->next = t;
        t->next = nullptr;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void RDisplay(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        RDisplay(p->next);
    }
}

int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x)
{
    if (index < 0 || index > Length(p))
    {
        return;
    }

    int i;
    Node *t = new Node;
    t->data = x;
    if (index == 0)
    {
        t->prev = nullptr;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if(p->next) p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    if (index < 1 || index > Length(p))
    {
        return -1;
    }
    int x = -1, i;
    if (index == 1)
    {
        x = p->data;
        head = head->next;
        delete p;
        if (head)
            head->prev = nullptr;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

void reverse(struct Node *p){
    Node *temp;
    while(p){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp; 
        p=p->prev;
        if(p!=NULL && p->next == nullptr) head = p;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(head, a, 5);
    cout<<Length(head)<<endl;
    Insert(head, 5,40); 
    Display(head);
    reverse(head);
    Display(head);

    return 0;
}