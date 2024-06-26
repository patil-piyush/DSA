#include <iostream>
using namespace std;
// taylors series using horners rule (Iterative)
double e(int x, int n)
{
    double s = 1;
    double num = 1, den = 1;
    for (int i = 1; i <= n; i++)
    {
        num *= x;
        den *= i;
        s += num / den;
    }
    return s;
}
int main()
{
    cout << e(1, 10);
    return 0;
}
