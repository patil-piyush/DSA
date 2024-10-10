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

// recursive count function for counting nodes of a linked list
int Rcount(struct Node *p)
{
    if (p != 0)
    {
        return Rcount(p->next) + 1;
    }
    else
    {
        return 0;
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

//function for removing the duplicates from the sorted linked list
void RemoveDuplicates(struct Node *p){
    p = first;
    Node *q = first->next;
    while(q){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}

//Function for inserting a node in a sorted linked list
void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q;
    q = NULL;

    t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
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


// simple function for finding max element of a linked list
int max(struct Node *p)
{
    int m = INT32_MIN;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
        }
        p = p->next;
    }
    return m;
}


// recursive function for finding max element of a linked list
int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MIN;
    }
    x = Rmax(p->next);
    if (x > p->data)
    {
        return x;
    }
    else
    {
        return p->data;
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

//reversing the linked list Method 1
//it uses a array of size equal to the size of linked list
//firstly traverse the LL and copy the elements from LL to the array 
//while traversing second time copy the elements from array to LL in reverse order
void ReverseElements1(struct Node *p){
    
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

//Reversing the LL method 2 - 
//Reversing it by using 3 sliding pointers
void ReverseElements2(struct Node *p)
{
    Node *current = nullptr;
    Node *prev = nullptr;

    while (p)
    {
        prev = current;
        current = p;
        p = p->next;
        current->next = prev;
    }
    first = current;
}

//Reversing the LL method 3 - 
//Reversing it by using Recursion
void ReverseElements3(struct Node *q,struct Node *p)
{
    if(p){
        ReverseElements3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}

int main()
{
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    create(a, 7);
    
    return 0;
}