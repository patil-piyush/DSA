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
void SortedInsert(struct Array *arr, int x);
int LinearSearch(struct Array arr, int key);
void Merge(struct Array first, struct Array second, struct Array *third);
int max(struct Array arr);
int min(struct Array arr);
void sortInt(struct Array *arr);
void Reverse(struct Array *arr);
void LeftRotation(struct Array *arr);
void RightRotation(struct Array *arr);
void LeftShift(struct Array *arr);
void RightShift(struct Array *arr);
bool CheckSort(struct Array arr);
int sum(struct Array arr);
void swap(int *x, int *y);



// function definations

//1.Display Function
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
//9.insert function for sorted array
void SortedInsert(struct Array *arr, int x)
{
    int i = arr->length - 1;
    while (arr->A[i] > x)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}
//10.linear search
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
//11.function for merging
void Merge(struct Array first, struct Array second, struct Array *third)
{
    third->size = first.size + second.size;
    third->length = 0;
    int i, j, k;
    i = j = k = 0;
    while (i < first.length && j < second.length)
    {
        if (first.A[i] > second.A[j])
        {
            third->A[k++] = second.A[j++];
        }
        else if (first.A[i] < second.A[j])
        {
            third->A[k++] = first.A[i++];
        }
        else
        {
            third->A[k++] = second.A[j++];
            i++;
        }
    }

    for (; i < first.length; i++)
    {
        third->A[k++] = first.A[i];
    }
    for (; j < second.length; j++)
    {
        third->A[k++] = second.A[j];
    }
    third->length = k;
}
//12.max function
int max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (max < arr.A[i])
        {
            max = arr.A[i];
        }
    }
    return max;
}
//13.min function
int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (min > arr.A[i])
        {
            min = arr.A[i];
        }
    }
    return min;
}
//14.function for arranging Positive numbers on right and negative numbers on left
void sortInt(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr->A[i], arr->A[j]);
        }
    }
}
//15.Reverse Function
void Reverse(struct Array *arr)
{
    int temp;
    for (int i = 0; i < arr->length / 2; i++)
    {
        temp = arr->A[i];
        arr->A[i] = arr->A[arr->length - 1 - i];
        arr->A[arr->length - 1 - i] = temp;
    }
}
//16.Left Rotation
void LeftRotation(struct Array *arr)
{
    arr->A[arr->length] = arr->A[0];
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
}
//17.Right Rotation
void RightRotation(struct Array *arr)
{
    for (int i = arr->length; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = arr->A[arr->length];
}
//18.Left shift
void LeftShift(struct Array *arr)
{
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
}

//19.Right shift
void RightShift(struct Array *arr)
{
    int i;
    for (i = arr->length; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[i] = 0;
    arr->length++;
}
//20.function for checking if array is sorted or not
bool CheckSort(struct Array arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return false;
        }
    }
    return true;
}
//21.sum function
int sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    return sum;
}
//22.swap Function
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    
    return 0;
}