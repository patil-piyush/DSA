#include<iostream>
using namespace std;
//factorial using recursion
int fact (int n){
    if(n==0){
        return 1;
    }
    else{
        return fact(n-1)*n;
    }
}

//factorial using loop
int Ifact(int n){
    int f = 1;
    if(n==0){
        f=1;
    }
    else{
        for(int i = 1; i<=n; i++){
            f = f*i;
        }
    }
    return f;

}

int main(){
    cout<<fact(5) <<endl;
    cout << Ifact(5)<<endl;
    return 0;
}