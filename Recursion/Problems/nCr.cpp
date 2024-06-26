#include <iostream>
using namespace std;

// by using factorial function
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return fact(n - 1) * n;
    }
}

int C(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n - r);
    return t1 / (t2 * t3);
}

// by using recursion
int RecursiveC(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return RecursiveC(n - 1, r - 1) + RecursiveC(n - 1, r);
    }
}
int main()
{
    cout << C(5, 3) << endl;
    cout << RecursiveC(5, 3) << endl;
    return 0;
}