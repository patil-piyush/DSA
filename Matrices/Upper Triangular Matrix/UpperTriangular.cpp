#include<iostream>
using namespace std;

struct matrix{
    int *a;
    int n;
};

//set function for column major
void set(struct matrix *m, int i, int j, int x){
    if(i<=j){
        m->a[j*(j-1)/2+i-1] = x;
    }
}

/*
set function for row major
    void set(struct matrix *m, int i, int j, int x){
        if(i<=j){
            m->a[m->n*(i-1)-(i-2)(i-1)/2+j-i] = x;
        }
    }
*/

//get function for column major
int get(struct matrix m, int i, int j){
    if(i<=j){
        return m.a[j*(j-1)/2+i-1];
    }
    else{
        return 0;
    }
}

/*
get function for row major
    int get(struct matrix m, int i, int j){
        if(i<=j){
            return m.a[m.n*(i-1)-(i-2)(i-1)/2+j-i];
        }
        else{
            return 0;
        }
    }
*/

//display function for column major
void display(struct matrix m){
    for(int i=1; i<=m.n; i++){
        for(int j=1; j<=m.n; j++){
            if(i<=j){
                cout<<m.a[j*(j-1)/2+i-1]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

/*
display function for row major
    void display(struct matrix m){
        for(int i=1; i<=m.n; i++){
            for(int j=1; j<=m.n; j++){
                if(i<=j){
                    cout<<m.a[m.n*(i-1)-(i-2)(i-1)/2+j-i]<<" ";
                }
                else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
    }
*/

int main(){
    struct matrix m;

    cout<<"Enter the size of the lower triangular array: ";
    cin>>m.n;
    m.a = new int[m.n*(m.n-1)/2];
    int x;
    cout<<"Enter the elements: ";
    for(int i=1; i<=m.n; i++){
        for(int j=1; j<=m.n; j++){
            cin>>x;
            set(&m, i, j, x);
        }
    }
    
    display(m);

    return 0;
}