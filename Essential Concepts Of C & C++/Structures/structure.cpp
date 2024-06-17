#include<iostream>
using namespace std;

//defining a structure
struct Rectangle
{
    int length;
    int breadth;
};

/*
1) Declaring a variable of the structure outside the main function
    struct Rectangle r1;
2) Declaring a variable of the structure outside the main function along with defination of structure
    struct Rectangle
    {
        int length;
        int breadth;
    } r1,r2;
3) to show the padding of the data
    struct Rectangle
    {
        int length;
        int breadth;
        char x;
    };
*/

int main(){
    //Declaring and initialising a variable of the structure
    struct Rectangle r1 = {10 , 5};
    //calculating size of the struct variable
    cout<<sizeof(r1)<<endl;

    //accessing the data members
    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;
    return 0;
}