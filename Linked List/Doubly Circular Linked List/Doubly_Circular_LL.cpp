#include<iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
}*head;

void create(struct Node *p, int a[], int n){
    Node *t = new Node;
    Node *last;
    t->data = a[0];
    head = last = t;
    t->prev = t;
    t->next = t;

    for(int i=1; i<n; i++){
        t = new Node;
        t->data = a[i];
        t->prev = last;
        last->next = t;
        t->next = head;
        head->prev = t;
        last = t;
    }
}

int Length(struct Node *p){
    int len =0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}

void Display(struct Node *p){
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
    cout<<endl;
}

void Insert(struct Node *p, int index, int x){
    if(index < 0 || index > Length(p)){
        return;
    }
    Node *t = new Node;
    t->data = x;
    if(index == 0){
        t->next = head;
        t->prev = head->prev;
        head->prev->next = t;
        head->prev = t;
        head = t;
    }
    else{
        for(int i=0;i<index-1;i++){
            p=p->next;
        }
        t->prev = p;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
    }
}

int Delete(struct Node *p, int index){
    if(index < 1 || index > Length(p)){
        return -1;
    }
    int x=-1;
    if(index == 1){
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        x= p->data;
        delete p;
    }
    else{
       for(int i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        x= p->data;
        delete p;
    }
    return x;
}
int main(){
    int a[] = {1, 2, 3, 4, 5};
    create(head, a, 5);
    cout<<Length(head)<<endl;
    Insert(head,4,100);
    Display(head);
    Delete(head,6);
    Display(head);
    return 0;
}