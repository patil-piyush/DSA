#include <iostream>
using namespace std;

int main()
{
    char a[10] = "madam";
    int i = 0, j = 0;

    // method 1 - reverse and compare
    char b[10];
    for (i = 0; a[i] != '\0'; i++)
    {
    }
    i = i - 1;

    for (j = 0; i >= 0; j++, i--)
    {
        b[j] = a[i];
    }
    b[j] = '\0';

    for (i = 0; a[i] != '\0'; i++)
    {
        if(a[i]!=b[i]){
            cout << "not a palindrom" << endl;
            exit(0);
        }
    }
    cout << "palindrom" << endl;

    // method 2 - compare the same array from starting and ending
    char c[10] = "madamm";
    for (i = 0; c[i] != '\0'; i++){}
    i = i - 1;
    for (j = 0; j < i; j++, i--)
    {
        if(c[i]!=c[j]){
            cout << "not a palindrom" << endl;
            exit(0);
        } 
    }
    cout << "palindrom" << endl;

    return 0;
}