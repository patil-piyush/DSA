#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array a)
{
    for (int i = 0; i < a.length; i++)
    {
        cout << a.A[i] << " ";
    }
    cout << endl;
}

// normal sum function
int sum(struct Array arr){
    int sum = 0;
    for(int i = 0; i< arr.length; i++){
        sum = sum + arr.A[i];
    }
    return sum;
}

// recursive sum function
int Rsum(struct Array arr, int index)
{
    if(index < 0){
        return 0;
    }
    else{
        return Rsum(arr, index-1)+arr.A[index];
    }
}

int main()
{
    struct Array arr;
    cout << "Enter the size: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;

    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    cout << "enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr.A[i];
    }
    arr.length = n;

    display(arr);

    //calling normal sum function
    cout << sum(arr) << endl;

    // calling recursive sum function
    cout << Rsum(arr,arr.length-1) << endl;
    return 0;
}