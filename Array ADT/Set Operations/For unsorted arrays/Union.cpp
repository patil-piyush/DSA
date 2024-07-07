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

// function for Union by using merging
void Union(struct Array first, struct Array second, struct Array *third)
{
    third->size = first.size + second.size;
    third->length = 0;
    
    // step 1 -- copy first array in third array
    for (int i = 0; i < first.length; i++)
    {
        third->A[i] = first.A[i];
    }
    third->length = first.length;

    //step 2 -- copying second array in third array
    for (int i = 0; i < second.length; i++)
    {
        for (int j = 0; j < first.length; j++)
        {
            //check if element of second array is present or not in first array which you copied in third array
            if (second.A[i] == first.A[j])
            {
                //if yes then leave the element and look for next because we are not copying same element twice
                break;
            }
            else{
                //if no then copy the element in third array and increament length of third array
                third->A[third->length++] = second.A[i];
                break;
            }
        }
    }
}

int main()
{
    // taking input for First array
    struct Array first;
    cout << "Enter the size: ";
    cin >> first.size;
    first.A = new int[first.size];
    first.length = 0;

    int n;
    cout << "enter the number of elements: ";
    cin >> n;
    cout << "enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> first.A[i];
    }
    first.length = n;

    // taking input for second array
    struct Array second;
    cout << "Enter the size: ";
    cin >> second.size;
    second.A = new int[second.size];
    second.length = 0;

    cout << "enter the number of elements: ";
    cin >> n;
    cout << "enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> second.A[i];
    }
    second.length = n;

    struct Array third;
    Union(first, second, &third);
    display(third);

    return 0;
}