#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*Top = NULL;

void push(int x){
    Node *t = new Node;
    if(t==NULL)
        cout<<"Stack Overflow\n";
    else{
        t->data = x;
        t->next = Top;
        Top = t;
    }
}

int pop(){
    int x = -1;
    if(Top == NULL)
        cout<<"stack underflow\n";
    else{
        Node *t;
        t = Top;
        Top = Top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display(){
    Node *p = Top;
    for(int i=0; p!=NULL; i++){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int peek(int pos){
    Node *p = Top;
    for(int i=0; p!=NULL && i<pos-1; i++){
        p=p->next;
    }
    if(p!=NULL){
        return p->data;
    }
    else{
        return -1;
    }
}

int isEmpty(){
    if(Top == NULL)
        return 1;
    return 0;
}

int isFull(){
    Node *t = new Node;
    if(t==NULL){
        delete t;
        return 1;
    }
    else{
        delete t;
        return -1; 
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    Display();
    cout<<pop();
    return 0;
}