#include<iostream>
using namespace std;

int add(int a , int b){
    int c;
    c = a + b;
    return 0;
}

int main(){
    int num1 = 10, num2 = 5, sum;
    sum = add(num1,num2);
    cout<<"sum is "<<sum;
    return 0;
}