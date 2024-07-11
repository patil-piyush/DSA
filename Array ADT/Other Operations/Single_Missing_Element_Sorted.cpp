#include <iostream>
using namespace std;

int main()
{

    int sum = 0, n = 11;
    int a[n] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    // Method 1
    // this method is only applicable for missing element in an array of sequence of first n natural numbers
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }
    int s = n * (n + 1) / 2;
    cout << "Missing element is " << s - sum;

    // method 2
    // this method is applicable for any sorted array
    int l = a[0];
    int diff = l - 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - i != diff)
        {
            cout << "Missing element is " << i + diff;
            break;
        }
    }

    return 0;
}