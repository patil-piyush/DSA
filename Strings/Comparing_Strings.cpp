#include <iostream>
using namespace std;

int main()
{
    char a[] = "Piyush";
    char b[] = "Piyush";
    int i = 0, j = 0;

    // if case is different than change case of both the strings
    //  for uppercase to lowercase
    //  changing case of string a
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
        {
            a[i] = a[i] + 32;
        }
    }
    // changing case of string b
    for (int i = 0; b[i] != '\0'; i++)
    {
        if (b[i] >= 65 && b[i] <= 90)
        {
            b[i] = b[i] + 32;
        }
    }

    // comparing strings
    for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i] != b[j])
        {
            break;
        }
    }
    if (a[i] == b[j])
        cout << "equal" << endl;
    else if (a[i] > b[j])
        cout << "smaller" << endl;
    else
        cout << "Greater" << endl;
    return 0;
}