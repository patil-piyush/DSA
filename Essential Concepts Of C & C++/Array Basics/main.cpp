#include <iostream>
using namespace std;

int main()
{
    int A[10]; // Declaration

    // assigning the values to each element
    A[0] = 20;
    A[1] = 12;
    A[2] = 13;

    // printing the size of the array
    cout << sizeof(A)<<endl;

    // printing elements
    cout << A[0] << endl;
    cout << A[1] << endl;
    cout << A[2] << endl;
    cout << A[9] << endl;

    //printing the size of an array without giving the size while declaration it will decided by the elements you will assign while declaration
    int B[] = {1,2,3,4,5,6,7};
    cout<<sizeof(B)<<endl;

    //print all the elements
    for (int i = 0; i < 10; i++)
    {
        cout<<A[i]<<endl;
    }

    //OR

    for(int x:A){
        cout<<x<<endl;
    } 

    //take the size of array from user
    int n;
    cout<<"Enter the size of array";
    cin>>n;
    int C[n];

    //End of problems
    return 0;
}