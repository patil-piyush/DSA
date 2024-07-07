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

// function for Difference of two sets
void Diff(struct Array first, struct Array second, struct Array *third)
{
    third->length = 0;
    for (int i = 0; i < first.length; i++)
    {
        int flag = 0;
        for (int j = 0; j < second.length; j++)
        {
            if (first.A[i] == second.A[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            third->A[third->length++] = first.A[i];
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
    Diff(first, second, &third);
    display(third);

    return 0;
}