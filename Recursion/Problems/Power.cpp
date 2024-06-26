#include <iostream>
using namespace std;

// initial function
int pow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return m * pow(m, n - 1);
    }
}
// modified function
int ModPow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return ModPow(m * m, n / 2);
    }
    else
    {
        return m * ModPow(m * m, (n - 1) / 2);
    }
}

// iterative function
int Ipow(int m, int n)
{
    int power = 1;
    while (n--)
    {
        power = power * m;
    }
    return power;
}

int main()
{
    cout << pow(2, 2) << endl;
    cout << ModPow(2, 2) << endl;
    cout << Ipow(2, 2) << endl;
    return 0;
}