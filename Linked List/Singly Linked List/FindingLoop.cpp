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



// Function for finding the existance of loop in the LL
int isLoop(Node *f){
    Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        if(q){
            q=q->next;            
        }
    }while(p && q && p!=q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}


int main()
{
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
     
    Node *tf1,*tf2;
    tf1 = first->next->next;
    tf2 = first->next->next->next->next;
    tf2->next = tf1;

    cout<<isLoop(first);
    return 0;
}