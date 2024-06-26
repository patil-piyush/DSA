#include <iostream>
using namespace std;

/*
By using Formula
    int sum(int n)
    {
        return n*(n-1)/2;
    }
*/

/*
by using loops
    int sum(int n)
    {
        int s=0;
        for (int i = 0; i <= n; i++)
        {
            s=s+i;
        }
        return s;
    }
*/

// by using recursion
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sum(n - 1) + n;
    }
}
int main()
{
    int a = 5;
    cout << sum(a);
    return 0;
}