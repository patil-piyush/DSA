#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class stack{
    private:
    Node *top;
    public:
    stack(){top = nullptr;}
    void push(int x);
    int pop();
    void Display();
};

void stack::push(int x){
    Node *t = new Node;
    if(t==NULL){
        cout<<"stack overflow\n";
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int stack::pop(){
    int x = -1;
    if(top == NULL){
        cout<<"stack underflow\n";
    }
    else{
        Node *t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void stack::Display(){
    Node *p = top;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.Display();
    cout<<st.pop()<<endl;
    return 0;
}