#include<iostream>
using namespace std;

struct matrix{
    int *a;
    int n;
};

//set function for row major
void set(struct matrix *m, int i, int j, int x){
    if(i>=j){
        m->a[i*(i-1)/2+j-1] = x;
    }
}

/*
set function for column major
    void set(struct matrix *m, int i, int j, int x){
        if(i>=j){
            m->a[m->n*(j-1)-(j-2)(j-1)/2+i-j] = x;
        }
    }
*/

//get function for row major
int get(struct matrix m, int i, int j){
    if(i>=j){
        return m.a[i*(i-1)/2+j-1];
    }
    else{
        return 0;
    }
}

/*
get function for column major
    int get(struct matrix m, int i, int j){
        if(i>=j){
            return m.a[m->n*(j-1)-(j-2)(j-1)/2+i-j];
        }
        else{
            return 0;
        }
    }
*/

void display(struct matrix m){
    for(int i=1; i<=m.n; i++){
        for(int j=1; j<=m.n; j++){
            if(i>=j){
                cout<<m.a[i*(i-1)/2+j-1]<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

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