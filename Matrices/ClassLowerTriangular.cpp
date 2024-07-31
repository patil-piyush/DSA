#include<iostream>
using namespace std;


//given code is for row major representation
//for column major representation you just have to chang the formula - [n*(j-1)-(j-2)(j-1)/2+i-j]
class LowerTriangular{
    private:
    int *a;
    int n;

    public:
    LowerTriangular();
    LowerTriangular(int n);
    ~LowerTriangular();
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
};

LowerTriangular::LowerTriangular(){
    n = 2;
    a = new int[2*(2+1)/2];
}

LowerTriangular::LowerTriangular(int n){
    this->n = n;
    a = new int[n*(n+1)/2];
}

void LowerTriangular::set(int i, int j, int x){
    if(i>=j){
        a[i*(i-1)/2+j-1] = x;
    }
}

int LowerTriangular::get(int i, int j){
    if(i>=j){
        return a[i*(i-1)/2+j-1];
    }
    else{
        return 0;
    }
}

void LowerTriangular::display(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i>=j){
                cout<<a[i*(i-1)/2+j-1]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

LowerTriangular::~LowerTriangular(){
    delete []a;
}

int main(){
    int x,y;
    cout<<"Enter the size of the lower triangular array: ";
    cin>>x;
    LowerTriangular d(x);
    
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