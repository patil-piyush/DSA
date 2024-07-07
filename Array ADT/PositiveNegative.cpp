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

//function for arranging Positive numbers on right and negative numbers on left
void sortInt(struct Array *arr){
    int i = 0;
    int j = arr->length-1;
    while(i<j){
        while(arr->A[i]<0){
            i++;
        }
        while (arr->A[j] > 0)
        {
            j--;
        }
        if(i<j){
            swap(arr->A[i],arr->A[j]);
        }
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

    sortInt(&arr);
    display(arr);
    return 0;
}