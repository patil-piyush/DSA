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

// normal binary search
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

// recursive binary search
int RBinSearch(struct Array arr, int l, int h, int key)
{

    if (l <= h)
    {
        int mid = (l + h) / 2;
        if (key == arr.A[mid])
        {
            return mid;
        }
        else if (key < arr.A[mid])
        {
            return RBinSearch(arr, l, mid - 1, key);
        }
        else
        {
            return RBinSearch(arr, mid + 1, h, key);
        }
    }
    return -1;
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

    int key;
    cout << "enter the number to search\n";
    cin >> key;
    // result of normal binary search
    cout << BinSearch(arr, key) << endl;
    // result of recursive binary search
    cout << RBinSearch(arr, 0, arr.length, key) << endl;
    return 0;
}