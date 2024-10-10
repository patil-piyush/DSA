// Reversing the linked list by swapping the data
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

//function for deleting a node
int DeleteNode(struct Node *p,int pos){
    Node *c,*q;
    int x=-1,i;
    if(pos<1 || pos>count(p)){
        return -1;
    }
    if(pos==1){
        c=first;
        first = first->next;
        x = c->data;
        delete c;
        return x;
    }
    else{
        c = first;
        q = nullptr;

        for(i=0; i<pos-1; i++){
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}

void ReverseElements(struct Node *p){
    
    int* arr = new int[sizeof(int)*count(p)];
    Node *q=p,*temp;
    int i=0;
    while(q){
        arr[i] = q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q){
        q->data=arr[i];
        q=q->next;
        i--;
    }
    
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    DisplayLL(first);

    ReverseElements(first);
    DisplayLL(first);
 

    
    return 0;
}