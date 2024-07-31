#include<iostream>
using namespace std;

class diagonal{
    private:
    int *a;
    int n;

    public:
    diagonal();
    diagonal(int n);
    ~diagonal();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

diagonal::diagonal(){
    n = 2;
    a = new int[2];
}

diagonal::diagonal(int n){
    this->n = n;
    a = new int[n];
}

void diagonal::set(int i, int j, int x){
    if(i==j){
        a[i] = x;
    }
}

int diagonal::get(int i, int j){
    if(i==j){
        return a[i];
    }
    else{
        return 0;
    }
}

void diagonal::display(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                cout<<a[i]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

diagonal::~diagonal(){
    delete []a;
}

int main(){
    diagonal d(4);
    d.set(0,0,2);
    d.set(1,1,4);
    d.set(2,2,6);
    d.set(3,3,8);
    d.display();
    cout<<d.get(2,2)<<endl;

    return 0;
}