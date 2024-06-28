#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;

    // Insert as member function of structure
    void Insert(int index, int x)
    {
        if (length < size && index >= 0)
        {
            for (int i = length; i > index; i--)
            {
                A[i] = A[i - 1];
            }
            A[index] = x;
            length++;
        }
    }
};

// Normal insert function
void Insert(struct Array *arr, int index, int x)
{
    if (arr->length < arr->size && index >= 0)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
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

    // calling insert function as member function of structure array
    arr.Insert(3, 10);

    display(arr);

    // calling normal insert function
    Insert(&arr, 4, 10);

    display(arr);

    return 0;
}