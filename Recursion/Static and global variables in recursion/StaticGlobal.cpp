#include <iostream>
using namespace std;

// initial code for printinf=g the sum of n natural numbers using recursion
int fun(int n)
{
    if (n > 0)
    {
        return fun(n - 1) + n;
    }
    return 0;
}
int main()
{
    int a = 5;
    cout << fun(a);
    return 0;
}

/*  modified code for static variables

int fun(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}
int main()
{
    int a = 5;
    cout << fun(a);
    return 0;
}

*/

/*  modified code for global variables

int x = 0;

int fun(int n)
{
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}
int main()
{
    int a = 5;
    cout << fun(a);
    return 0;
}

*/