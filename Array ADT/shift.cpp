#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};


//Left shift
void LeftShift(struct Array *arr)
{
        for (int i = 0; i < arr->length; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;    
}

// Right shift
void RightShift(struct Array *arr)
{
    int i;
    for (i = arr->length ; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[i] = 0;
    arr->length++;
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

    // calling Left shift
    LeftShift(&arr);
    display(arr);

    //calling Right shift
    RightShift(&arr);
    display(arr);

    return 0;
}