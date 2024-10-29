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

// recursive display function for displaying linked list
void RDisplayLL(struct Node *p)
{
    if (p != 0)
    {
        cout << p->data << endl;
        RDisplayLL(p->next);
    }
}

// function for checking whether the linked list is sorted or not
bool isSorted(struct Node *p)
{
    int x = INT8_MIN;

    while(p){
        if(p->data < x){
            return false;
        }
        else{
            x = p->data;
            p=p->next;
        }
    }
    return true;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    
    if(isSorted(first)){
        cout<<"Sorted"<<endl;
    }
    else{
        cout<<"Not Sorted"<<endl;
    }
    return 0;
}