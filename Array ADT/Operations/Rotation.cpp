#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

//Left Rotation
void LeftRotation(struct Array *arr)
{
    arr->A[arr->length] = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
}

//Right Rotation
void RightRotation(struct Array *arr)
{
    for (int i = arr->length; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = arr->A[arr->length];
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

    // calling Left Rotation
    LeftRotation(&arr);
    display(arr);

    // calling Right Rotation
    RightRotation(&arr);
    display(arr);

    return 0;
}