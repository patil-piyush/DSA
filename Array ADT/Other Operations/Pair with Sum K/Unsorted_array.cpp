#include <iostream>
using namespace std;

int main()
{
    int n = 10, k = 10;
    int a[n] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
    // method 1 - simply by using 2 for loop
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == k)
            {
                cout << a[i] << " " << a[j] << " " << k << endl;
            }
        }
    }

    // method 2 - by using hashing
    int H[16] = {0};
    for (int i = 0; i < n; i++)
    {
        if (H[k - a[i]] != 0)
        {
            cout << a[i] << " " << k - a[i] << " " << k << endl;
        }
        H[a[i]]++;
    }

    return 0;
}