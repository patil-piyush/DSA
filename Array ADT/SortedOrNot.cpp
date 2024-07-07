#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

// function for checking if array is sorted or not
bool CheckSort(struct Array arr){
    for(int i = 0; i< arr.length; i++){
        if(arr.A[i] > arr.A[i+1]){
            return false;
        }
    }
    return true;
}

void display(struct Array a)
{
    for (int i = 0; i < a.length; i++)
    {
        cout << a.A[i] << " ";
    }
    cout << endl;
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

    cout<<CheckSort(arr)<<endl;
    return 0;
}