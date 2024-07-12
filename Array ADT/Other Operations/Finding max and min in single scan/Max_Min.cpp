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

// max function
void max_min(struct Array arr)
{
    int max = arr.A[0];
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i]<min)
        {
            min = arr.A[i];
        }
        else if(arr.A[i]>max){
            max = arr.A[i];
        }
    }
    cout<<"max: "<<max<<endl;
    cout << "max: " << max << endl;
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

    max_min(arr);
    return 0;
}