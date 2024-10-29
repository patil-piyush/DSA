#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    public:
    Node();
    Node(int a);
};

class LinkedList{
    private:
    Node *head;
    public:
    LinkedList();
    void create(int a[],int x);
    void Display();
    void recursive_Display(Node *a);
    void Delete(int pos);
    int count();
    int recursion_count();
    void InsertNode(int index, int value);
    void ReverseLL_Array();
    void ReverseLL_Pointer();
    void ReverseLL_Recursion();
    bool isSorted();
    int min();
    int Recursive_min();
    int max();
    int Recursive_max();
    int sum();
    int Recursive_sum();
    void RemoveDuplicates();
    void MergeLL(LinkedList &T);
    void Concatinate(LinkedList &T);
    void sorted_Insert(int x);
    int isLoop();
};


Node::Node(){
    next = nullptr;
}

Node::Node(int a){
    data = a;
    next = nullptr;
}

LinkedList::LinkedList(){
    head = nullptr;
}

void LinkedList::create(int a[],int x){
    Node *nn = new Node(a[0]);
    head = nn;
    Node *p = head;
    for(int i=1; i<x;i++){
        Node *t = new Node(a[i]);
        p->next=t;
        p=p->next;
    }
}

void LinkedList::Display(){
    Node *p = head;
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
}


void LinkedList::recursive_Display(Node *a){
    Node *p = head;
    if(p){
        cout<<p->data<<endl;
        recursive_Display(p->next);
    }
}


int main(){
    
    return 0;
}