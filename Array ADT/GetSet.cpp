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

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
}

void set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
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

    return 0;
}