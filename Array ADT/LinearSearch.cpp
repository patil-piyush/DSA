#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

// normal linear search
int LinearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (key == arr.A[i])
        {
            return i;
        }
    }
    return -1;
}

// swap function used in advance linear search
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// Advance linear search

// 1) Transposition

int SearchTransposition(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

// 2) move to Head
int MoveToHead(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (key == arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
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

    // displaying initial array
    display(arr);

    // using normal linear search and displaying the changes in initial array
    cout << LinearSearch(arr, 4) << endl;
    display(arr);

    // using transposition linear search and displaying the changes in initial array
    cout << SearchTransposition(&arr, 5) << endl;
    display(arr);

    // using move to head linear search and displaying the changes in initial array
    cout << MoveToHead(&arr, 3) << endl;
    display(arr);
    return 0;
}