#include<iostream>
using namespace std;

int main(){

    //this method is only applicable for missing element in an array of sequence of first n natural numbers
    int sum=0,n=11;
    int a[n] = {1,2,3,4,5,6,8,9,10,11,12};
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    int s = n*(n+1)/2;
    cout<<"Missing element is "<<s-sum; 
    
    return 0;
}