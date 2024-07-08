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
int Delete(struct Array *arr, int index);
int get(struct Array arr, int index);
void set(struct Array *arr, int index, int x);
void Insert(struct Array *arr, int index, int x);



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
//5.Delete Function
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
//6.Get function
int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
}
//7.set function
void set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}
//8.insert function
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

int main()
{
    
    return 0;
}