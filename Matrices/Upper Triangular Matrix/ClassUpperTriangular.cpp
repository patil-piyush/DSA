#include<iostream>
using namespace std;


//given code is for column major representation
//for row major representation you just have to chang the formula - [n*(i-1)-(i-2)(i-1)/2+j-i]
class UpperTriangular{
    private:
    int *a;
    int n;

    public:
    UpperTriangular();
    UpperTriangular(int n);
    ~UpperTriangular();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

UpperTriangular::UpperTriangular(){
    n = 2;
    a = new int[2*(2+1)/2];
}

UpperTriangular::UpperTriangular(int n){
    this->n = n;
    a = new int[n*(n+1)/2];
}

void UpperTriangular::set(int i, int j, int x){
    if(i<=j){
        a[j*(j-1)/2+i-1] = x;
    }
}

int UpperTriangular::get(int i, int j){
    if(i<=j){
        return a[j*(j-1)/2+i-1];
    }
    else{
        return 0;
    }
}

void UpperTriangular::display(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i<=j){
                cout<<a[j*(j-1)/2+i-1]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

UpperTriangular::~UpperTriangular(){
    delete []a;
}

int main(){
    int x,y;
    cout<<"Enter the size of the lower triangular array: ";
    cin>>x;
    UpperTriangular d(x);
    
    cout<<"Enter the elements: ";
    for(int i=1; i<=x; i++){
        for(int j=1; j<=x; j++){
            cin>>y;
            d.set(i, j, y);
        }
    }
    
    d.display();

    return 0;
}