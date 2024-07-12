#include <iostream>
using namespace std;

int main()
{
    int n = 10, k = 10;
    int a[n] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};

    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] + a[j] == k)
        {
            cout << a[i] << " " << a[j] << " " << k << endl;
            i++;
            j--;
        }
        else if (a[i] + a[j] < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return 0;
}