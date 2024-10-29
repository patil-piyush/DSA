#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
}*Head;

void create(int a[], int n){
    int i;
    Node *t, *last;
    Head = new Node;
    Head->data = a[0];
    Head->next=nullptr;
    Head->next = last = Head;


    for(i=1;i<n;i++){
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=Head);
    cout<<endl;
}

void RDisplay(struct Node *p){
    static int flag = 0;
    if(p!=Head || flag==0){
        flag = 1;
        cout<<p->data<<" ";
        RDisplay(p->next);
    }
    flag = 0;
}

int main(){
    int a[]={1,2,3,4,5};
    create(a,5);
    Display(Head);
    RDisplay(Head);
    cout<<endl;
    return 0;
}