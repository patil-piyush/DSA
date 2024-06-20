#include <iostream>
using namespace std;
/*
Array as parameter using call by address
    void fun(int A[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << endl;
        }
    }

    int main()
    {
        int A[] = {1, 2, 3, 4, 5};
        fun(A, 5);
        return 0;
    }
*/
/*
Array as Parameter by using pointer
    void fun(int *A, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << endl;
        }
    }

    int main()
    {
        int A[] = {1, 2, 3, 4, 5};
        fun(A, 5);
        return 0;
    }
*/

/*  Function returning array  */
    int * fun(int n)
    {
        int *p;
        p = new int[n];
        for (int i = 0; i < n; i++)
        {
            p[i] = i+1;
        }
        return (p);
    }

    int main()
    {
        int *A, n = 5;
        A = fun(n);
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << endl;
        }
        return 0;
    }
