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

// reverse function by using saperate array
void M1_reverse(struct Array *arr)
{
    int B[arr->length - 1];
    for (int i = 0; i < arr->length; i++)
    {
        B[i] = arr->A[arr->length - 1 - i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

// reverse function by swapping
void M2_reverse(struct Array *arr)
{
    int temp;
    for (int i = 0; i < arr->length / 2; i++)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[arr->length - 1 - i];
        arr->A[arr->length - 1 - i] = temp;
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

    // calling reverse function by using saperate array
    M1_reverse(&arr);
    display(arr);

    // calling reverse function by swapping
    M2_reverse(&arr);
    display(arr);
    return 0;
}