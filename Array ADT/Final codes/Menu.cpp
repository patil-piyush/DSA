#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

//Function prototypes
void display(struct Array a);
void append(struct Array *arr, int x);
int average(struct Array arr);
int BinSearch(struct Array arr, int key);







// function definations

// 1.Display Function
void display(struct Array a)
{
    for (int i = 0; i < a.length; i++)
    {
        cout << a.A[i] << " ";
    }
    cout << endl;
}
//2.Append Function
void append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}
//3.Average Function
int average(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    return sum / arr.length;
}
//4.Binary Search
int BinSearch(struct Array arr, int key)
{
    int l = 0;
    int h = arr.length;
    int mid;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    
    return 0;
}