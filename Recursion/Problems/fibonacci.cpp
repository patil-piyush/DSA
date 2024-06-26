#include <iostream>
using namespace std;
int F[100];

int Ifib(int n)
{
    int t1 = 0, t2 = 1, t3;
    for (int i = 2; i <= n; i++)
    {
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
    }
    return t3;
}

int fib(int n)
{

    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fib(n - 2) + fib(n - 1);
    }
}

int Mfib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = Mfib(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = Mfib(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
}
int main()
{
    for (int i = 0; i <= 100; i++)
    {
        F[i] = -1;
    }
    cout << Ifib(10) << endl;
    cout << fib(10) << endl;
    cout << Mfib(10) << endl;
    return 0;
}