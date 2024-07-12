#include <iostream>
using namespace std;

int main()
{
    int n = 11;
    int a[n] = {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19};
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        count = 1;
        if (a[i] != -1)
        {
            for (int j = i + 1; i < n; j++)
            {
                if (a[i] == a[j])
                {
                    count++;
                    a[j] = -1;
                }
            }
            if (count > 1)
            {
                cout << a[i] << " " << count << endl;
            }
        }
    }
    return 0;
}