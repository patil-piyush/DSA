#include<iostream>
using namespace std;

class queue{
    int size;
    int rear;
    int front;
    int *a;
    public:
    queue(){size = 10; rear = front=-1; a = new int[size];}
    queue(int s){size = s; rear = front=-1; a = new int[size];}
    void enqueue(int x);
    int dequeue();
    void display();
};

void queue::enqueue(int x){
    if(rear ==size-1) cout<<"queue is full\n";
    else{
        rear++;
        a[rear]=x;
    }
}

int queue::dequeue(){
    int x=-1;
    if(front==rear)cout<<"Queue is Empty!!\n";
    else{
        front++;
        x = a[front];
    }
    return x;
}

void queue::display(){
    int i;
    for(i=front+1; i<=rear;i++){
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}


int main(){
    queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();
    return 0;
}