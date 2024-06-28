#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if (index >= 0 && index <= arr->length)
    {
        x = arr->A[index];
        for (int i = index; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return x;
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

    Delete(&arr, 3);
    display(arr);

    return 0;
}