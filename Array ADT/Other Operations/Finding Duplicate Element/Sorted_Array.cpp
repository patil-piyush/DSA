#include <iostream>
using namespace std;

int main()
{
    int n = 11;
    int a[n] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};

    // method 1 - bu simple checking
    int LastDuplicate = 0;
    for (int i = 0; i < n; i++)
    {
        if (LastDuplicate != a[i] && a[i] == a[i + 1])
        {
            cout << a[i] << endl;
            LastDuplicate = a[i];
        }
    }

    // counting
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            int j = i + 1;
            while (a[j] == a[i])
            {
                j++;
            }
            cout << a[i] << " " << j - i;
            i = j - 1;
        }
    }

    // method 2 - by hashing
    int h = a[n - 1], l = a[0];
    int H[h] = {0};

    for (int i = 0; i < n; i++)
    {
        H[a[i]]++;
    }
    for (int i = l; i < h; i++)
    {
        if (H[i] > 0)
        {
            cout << i << " " << H[i] << endl;
        }
    }
    return 0;
}