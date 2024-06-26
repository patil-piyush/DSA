#include <iostream>
using namespace std;

// taylors series using horners rule (recursion)
double e(int x, int n)
{
    static double s = 1;
    if (n == 0)
    {
        return s;
    }
    else
    {
        s = 1 + (x * s / n);
        return e(x, n - 1);
    }
}
int main()
{
    cout << e(1, 10);
    return 0;
}