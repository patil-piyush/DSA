#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node*next;
}*first;

void create(int a[], int n){
    int i;
    struct Node *t,*last;
    first = new Node;
    first->data=a[0];
    first->next=0;
    last=first;

    for(i=1; i<n; i++){
        t = new Node;
        t->data=a[i];
        t->next=0;
        last->next = t;
        last=t;
    }
}

//simple display function for displaying linked list
void DisplayLL(struct Node *p){
    while(p!=0){
        cout<<p->data<<endl;
        p=p->next;
    }
}

//recursive display function for displaying linked list
void RDisplayLL(struct Node *p){
    if(p!=0){
        cout<<p->data<<endl;
        RDisplayLL(p->next);
    }
}


int main(){
    int a[]= {10,20,30,40,50};
    create(a,5);
    RDisplayLL(first);
    return 0;
}